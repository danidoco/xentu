#include "xentu/core/application.hpp"

namespace xentu
{
   Application::Application(const char *name, int windowWidth, int windowHeight,
                            bool fullscreen)
      : name(name)
      , running(true)
   {
      xentu::Logger::Init(name);

      window =
         xentu::CreateWindow(windowWidth, windowHeight, this->name, fullscreen);

      windowCloseEventListener = std::make_shared<xentu::EventListener>(
         [this]() -> void { Terminate(); });
      window->GetEventDispatcher()->AddListener(windowCloseEventListener);
   }

   Application::~Application() {}

   void Application::Run()
   {
      while (running)
      {
         this->Mainloop();
      }
   }

   void Application::Terminate() { running = false; }
} // namespace xentu
