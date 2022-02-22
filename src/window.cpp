#include "xentu/render/window.hpp"

namespace xentu
{
   Window::Window(int width, int height, const char *caption, bool fullscreen)
      : width(width)
      , height(height)
      , caption(caption)
      , fullscreen(fullscreen)
   {
      windowCloseEventDispatcher = std::make_shared<EventDispatcher>(
         EventCategory::WindowEvent, EventType::WindowClose);

      if (!glfwInit())
      {
         XN_ENGINE_CRITICAL("Failed to initialize GLFW");
      }

      glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
      glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
      glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
      glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

      window = glfwCreateWindow(
         this->width, this->height, this->caption,
         this->fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);

      if (window == nullptr)
      {
         XN_ENGINE_CRITICAL("Failed to create GLFW window");
         glfwTerminate();
      }

      glfwMakeContextCurrent(window);

      if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
      {
         XN_ENGINE_CRITICAL("Failed to initialize GLAD");
      }

      glViewport(0, 0, 800, 600);

      glfwSetFramebufferSizeCallback(
         window, [](GLFWwindow *window, int width, int height) -> void {
            (void)window;
            glViewport(0, 0, width, height);
         });
   }

   Window::~Window()
   {
      glfwDestroyWindow(window);
      glfwTerminate();
   }

   void Window::Draw()
   {
      if (glfwWindowShouldClose(window))
      {
         windowCloseEventDispatcher->Dispatch();
      }

      glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      glfwPollEvents();
      glfwSwapBuffers(window);
   }

   std::shared_ptr<Window> CreateWindow(int width, int height,
                                        const char *caption, bool fullscreen)
   {
      return std::make_shared<Window>(width, height, caption, fullscreen);
   }
} // namespace xentu