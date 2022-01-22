#pragma once

namespace xentu
{
   class Application
   {
   private:
      bool running;
      const char *name;

   public:
      Application(const char *name);
      virtual ~Application();

      inline virtual const char *GetApplicationName() const
      {
         return name;
      }

      virtual void Mainloop() = 0;
      virtual void Run() final;
      virtual void Terminate() final;
   };

   Application *CreateApplication();
} // namespace xentu
