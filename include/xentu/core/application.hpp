#pragma once

#include "xentu/render/window.hpp"
#include "xentu/event/event_listener.hpp"
#include "xentu/debug/logger.hpp"

namespace xentu
{
   class Application
   {
   private:
      const char *name;

      bool running;
      std::shared_ptr<EventListener> windowCloseEventListener;
      std::shared_ptr<Window> window;

   public:
      Application(const char *name, int windowWidth, int windowHeight,
                  bool fullscreen);
      virtual ~Application();

      const char *GetApplicationName() const { return name; }
      std::shared_ptr<Window> GetWindow() const { return window; }

      virtual void Mainloop() = 0;
      void Run();
      void Terminate();
   };

   Application *CreateApplication();
} // namespace xentu
