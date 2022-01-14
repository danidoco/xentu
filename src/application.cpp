#include "xentu/core/application.hpp"

namespace Xentu
{
   Application::Application()
   {
      this->running = true;
   }

   Application::~Application()
   {
   }

   void Application::run()
   {
      while (running)
      {
         mainloop();
      }
   }

   void Application::terminate()
   {
      running = false;
   }
} // namespace Xentu
