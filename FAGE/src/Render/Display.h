#pragma once

#include <GLFW/glfw3.h>

#include "../Color.h"

#include <iostream>
#include <string>
#include <memory>

namespace fage
{
class Core;

namespace render {
	class Display
	{
	public:
		Display(const std::string& title, int width, int height, bool fullscreen);
		~Display();

		bool Create();
		void Clear(Color color);
		void Swap();

		bool ShouldClose();

		friend class fage::Core;

	private:
		std::string m_Title;
		int m_Width, m_Height;
		bool m_Fullscreen;

		GLFWwindow* m_Window;
	};
}
}
