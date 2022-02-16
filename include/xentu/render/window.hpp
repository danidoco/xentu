#pragma once

#include <memory>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "xentu/debug/logger.hpp"
#include "xentu/event/event_dispatcher.hpp"
#include "xentu/event/event_category.hpp"
#include "xentu/event/event_type.hpp"
#include "xentu/event/event_listener.hpp"

#undef CreateWindow
#undef CreateWindowA

namespace xentu
{
   class Window
   {
   private:
      int width, height;
      const char *caption;
      bool fullscreen;
      GLFWwindow *window;
      std::shared_ptr<EventDispatcher> windowCloseEventDispatcher;

   public:
      Window(int width, int height, const char *caption, bool fullscreen);
      ~Window();

      std::shared_ptr<EventDispatcher> GetEventDispatcher() const
      {
         return windowCloseEventDispatcher;
      }
      int GetWidth() const { return width; }
      int GetHeight() const { return height; }
      const char *GetCaption() const { return caption; }
      bool IsFullscreen() const { return fullscreen; }

      void Draw();
   };

   Window *CreateWindow(int width, int height, const char *caption,
                        bool fullscreen);
} // namespace xentu
