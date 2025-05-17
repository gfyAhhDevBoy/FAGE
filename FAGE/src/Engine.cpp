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
		m_Display = std::make_shared<render::Display>(title, width, height, fullscreen);
	}
}

void Core::ChangeScene(std::shared_ptr<Scene> scene)
{
	m_CurrentScene = scene;
}

void Core::AddKeyboardListener(KeyboardCallbackType callback)
{
	m_KeyboardListeners.push_back(callback);
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

		// Updating
		ProcessInput();


		m_CurrentScene->Update(0);

		// Drawing
		m_CurrentScene->Draw(std::shared_ptr(m_Display));

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
		if (glfwGetKey(m_Display->m_Window, static_cast<input::Keycode>(i)) == GLFW_PRESS)
		{
			for (auto kb : m_KeyboardListeners)
			{
				kb(static_cast<input::Keycode>(i));
			}
		}
	}
}
}