#ifndef XN_APPLICATION_H
#define XN_APPLICATION_H

namespace Xentu
{
   class Application
   {
   public:
      Application();
      virtual ~Application();
      virtual void mainloop() = 0;
      virtual void run() final;
   };
} // namespace Xentu

#endif