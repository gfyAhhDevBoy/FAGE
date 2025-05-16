#include "Engine.h"

namespace fage
{
Core& Core::Get()
{
	static Core engine;
	return engine;
}

void Core::CreateDisplay(const char* title, int width, int height, bool fullscreen)
{
	if (m_Display == nullptr)
	{
		m_Display = std::make_shared<Display>(title, width, height, fullscreen);
	}
}

void Core::SetCurrentScene(std::shared_ptr<Scene> scene)
{
	currentScene = scene;
}

void Core::AddKeyboardListener(KeyboardCallbackType callback)
{
	keyboardListeners.push_back(callback);
}

bool Core::Run()
{
	m_Running = true;
	if (!m_Display->Create())
	{
		return false;
	}

	while (m_Running)
	{
		m_Display->Clear(Color(0.2, 0.3, 0.3, 1.f));

		// Updating
		ProcessInput();


		currentScene->Update();

		// Drawing
		currentScene->Draw(std::weak_ptr(m_Display));

		// Last
		m_Display->Swap();

		if (m_Display->ShouldClose())
			m_Running = false;
	}

	
	return true;
}
void Core::Stop()
{
	m_Running = false;
}
void Core::ProcessInput()
{
	for (int i = input::First; i != input::Last; i++)
	{
		if (glfwGetKey(m_Display->m_Window, static_cast<input::Key>(i)) == GLFW_PRESS)
		{
			for (auto kb : keyboardListeners)
			{
				kb(static_cast<input::Key>(i));
			}
		}
	}
}
}