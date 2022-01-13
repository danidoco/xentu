#ifndef XN_APPLICATION_H
#define XN_APPLICATION_H

namespace Xentu
{
   class Application
   {
   public:
      Application();
      virtual ~Application();
      virtual void mainloop();
      virtual void run() final;
   };

   Application* get_application();
} // namespace Xentu

#endif