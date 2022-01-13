#include "xentu/application.hpp"

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
} // namespace Xentu
