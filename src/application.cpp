#include "xentu/core/application.hpp"
#include "xentu/debug/logger.hpp"

namespace xentu
{
   Application::Application(const char *name)
      : running(true)
      , name(name)
   {
      xentu::Logger::Init(name);
   }

   Application::~Application() {}

   void Application::Run()
   {
      while (this->running)
      {
         this->Mainloop();
      }
   }

   void Application::Terminate()
   {
      this->running = false;
   }
} // namespace xentu
