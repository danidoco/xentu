#pragma once

#include "xentu/render/window.hpp"
#include "xentu/event/event_listener.hpp"
#include "xentu/debug/logger.hpp"

namespace xentu
{
   class Application
   {
   private:
      std::shared_ptr<EventListener> windowCloseEventListener;
      bool running;
      const char *name;
      Window *window;

   public:
      Application(const char *name);
      virtual ~Application();

      virtual const char *GetApplicationName() const final { return name; }

      virtual void Mainloop() = 0;
      void Run();
      void Terminate();
   };

   Application *CreateApplication();
} // namespace xentu
