#include "xentu/core/application.hpp"
#include "xentu/debug/logger.hpp"

namespace xentu
{
   Application::Application()
      : running(true)
   {
      xentu::Logger::Init();
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
