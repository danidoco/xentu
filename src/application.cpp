#include "xentu/application.hpp"

namespace Xentu
{
   Application::Application()
   {
   }

   Application::~Application()
   {
   }

   void Application::run()
   {
      while (true)
      {
         mainloop();
      }
   }
} // namespace Xentu
