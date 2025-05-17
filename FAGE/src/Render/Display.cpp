#include "Display.h"

namespace fage
{
	namespace render {
		Display::Display(const std::string& title, int width, int height, bool fullscreen)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			m_Fullscreen = fullscreen;
			m_Window = nullptr;


		}

		Display::~Display()
		{
			glfwTerminate();
		}

		bool Display::Create()
		{
			glfwInit();
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
			glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title.c_str(), 0, 0);
			if (m_Window == NULL)
			{
				std::cout << "Failed to create GLFW window" << std::endl;
				glfwTerminate();
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			glViewport(0, 0, m_Width, m_Height);
			return true;




		}

		void Display::Clear(Color color)
		{
			glClearColor(color.r, color.g, color.b, color.alpha);

			// Stupid fucking normalized coords
			//std::cout << std::truncf(static_cast<float>(color.r / 255) * 10) / 10 << " " << std::truncf(static_cast<float>(color.g / 255) * 10) / 10 << " " << std::truncf(static_cast<int>(color.b / 255) * 10) / 10 << " " << std::truncf(static_cast<int>(color.alpha / 255) * 10) / 10 << std::endl;
			//std::cout << std::truncf(color.r / 255 * 10) / 10 << " " << std::truncf(color.g / 255 * 10) / 10 << " " << std::truncf(color.b / 255 * 10) / 10 << " " << std::truncf(color.alpha / 255 * 10) / 10 << std::endl;
			//std::cout << color.r << " " << color.g << " " << color.b << " " << color.alpha << std::endl;
			glClear(GL_COLOR_BUFFER_BIT);


		}

		void Display::Swap()
		{
			glfwSwapBuffers(m_Window);
			glfwPollEvents();
		}

		bool Display::ShouldClose()
		{
			return glfwWindowShouldClose(m_Window);
		}
	}
	

}

