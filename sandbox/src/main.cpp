#include "xentu/xentu.hpp"

class Sandbox : public xentu::Application
{
private:
   xentu::Window *window;

public:
   Sandbox()
      : Application("Sandbox")
   {
      XN_INFO("{} running!", GetApplicationName());
      XN_WARN("Warning from {}", GetApplicationName());

      window = xentu::CreateWindow(this, 800, 800, "Sandbox", false);
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
