#include "xentu/core/application.hpp"

namespace xentu
{
   Application::Application()
   {
      this->running = true;
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
