#include "Engine.h"

namespace fage
{
	Display CreateDisplay(const char* title = "Fuckass Advanced Game Engine", int width = 800, int height= 600, bool fullscreen = false)
	{
		return Display();
	}
	Engine& Engine::Get()
	{
		static Engine engine;
		return engine;
	}
}