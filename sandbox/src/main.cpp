#include "xentu/xentu.hpp"

class Sandbox : public xentu::Application
{
private:
   xentu::Window *window;

public:
   Sandbox()
      : Application("Sandbox")
   {
      XN_TRACE("Hello world");
      XN_INFO("{} running!", GetApplicationName());
      XN_WARN("Warning from {}", GetApplicationName());
      XN_ERROR("HELLWORLD");
      XN_CRITICAL("CRITICAL!!!");

      window = xentu::CreateWindow(this, 800, 800, "Sandbox", false);

      XN_ASSERT(1 == 1);
   }  

   void Mainloop() 
   {
      window->Draw();
   }

   ~Sandbox() 
   {
      delete window;
   }
};

xentu::Application *xentu::CreateApplication()
{
   return new Sandbox();
}
