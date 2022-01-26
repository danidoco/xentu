#pragma once

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "xentu/debug/logger.hpp"
#include "xentu/core/application.hpp"

#undef CreateWindow
#undef CreateWindowA

namespace xentu
{
   class Window
   {
   private:
      /*
      Application pointer will be temporarily used to control the application
      with window events. This method should be replaced by an proper event
      system asap.
      */
      Application *application;

      int width, height;
      const char *caption;
      bool fullscreen;
      GLFWwindow *window;

   public:
      Window(Application *application, int width, int height,
             const char *caption, bool fullscreen);
      ~Window();

      inline int GetWidth() { return width; }
      inline int GetHeight() { return height; }
      inline const char *GetCaption() { return caption; }
      inline bool IsFullscreen() { return fullscreen; }

      void Draw();
   };

   Window *CreateWindow(Application *application, int width, int height,
                        const char *caption, bool fullscreen);
} // namespace xentu
