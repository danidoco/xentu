#pragma once

#include "xentu/render/window.hpp"
#include "xentu/event/event_listener.hpp"
#include "xentu/debug/logger.hpp"

namespace xentu
{
   class Application
   {
   private:
      bool running;
      const char *name;

   protected:
      std::shared_ptr<EventListener> windowCloseEventListener;
      std::shared_ptr<Window> window;

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
