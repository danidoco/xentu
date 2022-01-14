#ifndef XN_APPLICATION_H
#define XN_APPLICATION_H

namespace Xentu
{
   class Application
   {
   private:
      bool running;
      
   public:
      Application();
      virtual ~Application();
      virtual void mainloop() = 0;
      virtual void run() final;
      virtual void terminate() final;
   };

   Application* get_application();
} // namespace Xentu

#endif