#pragma once

#include "Display.h"
#include "Scene.h"
#include "Input/Keyboard.h"

#include <memory>
#include <iostream>
#include <vector>

namespace fage
{
	class Core
	{
		typedef void (*KeyboardCallbackType)(int);

	public:
		Core(const Core&) = delete;
		Core& operator=(const Core&) = delete;

		Core(const Core&&) = delete;
		Core&& operator=(const Core&&) = delete;
		
		static Core& Get();

		void CreateDisplay(const char* title = "Fuckass Advanced Game Engine", int width = 800, int height = 600, bool fullscreen = false);
		
		void SetCurrentScene(std::shared_ptr<Scene> scene);
		void AddKeyboardListener(KeyboardCallbackType callback);

		bool Run();
		void Stop();

	private:
		Core() = default;

		void ProcessInput();

		bool m_Running = false;
		
		std::shared_ptr<Scene> currentScene = nullptr;

		std::vector<KeyboardCallbackType> keyboardListeners;
		std::shared_ptr<Display> m_Display;
	};

}