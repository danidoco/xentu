#include "xentu/core/application.hpp"

namespace xentu
{
   Application::Application(const char *name)
      : running(true)
      , name(name)
   {
      xentu::Logger::Init(name);

      windowCloseEventListener =
         std::make_shared<EventListener>([this]() -> void { Terminate(); });

      // FIXME: this line throws segfault
      // NOTE: i think GetEventDispatcher() returns nullptr
      //       or t 
      window->GetEventDispatcher()->AddListener(windowCloseEventListener);
   }

   Application::~Application() {}

   void Application::Run()
   {
      while (this->running)
      {
         this->Mainloop();
      }
   }

   void Application::Terminate() { this->running = false; }
} // namespace xentu
