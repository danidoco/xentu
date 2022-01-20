#pragma once

namespace xentu
{
   class Application
   {
   private:
      bool running;

   public:
      Application();
      virtual ~Application();
      virtual void Mainloop() = 0;
      virtual void Run() final;
      virtual void Terminate() final;
   };

   Application *CreateApplication();
} // namespace xentu
