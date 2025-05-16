#pragma once

#include "Display.h"

namespace fage
{
	class Engine
	{
	public:
		Engine(const Engine&) = delete;
		Engine& operator=(const Engine&) = delete;
		
		static Engine& Get();

		Display& CreateDisplay();

	private:
		Engine() = default;

		bool m_Running = false;
		
		Display display;
	};
}