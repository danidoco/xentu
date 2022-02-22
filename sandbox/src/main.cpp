#include "xentu/xentu.hpp"

class Sandbox : public xentu::Application
{
private:
   std::shared_ptr<xentu::Window> window;

public:
   Sandbox()
      : Application("Sandbox", 800, 800, true)
   {
      XN_INFO("{} running!", GetApplicationName());

      window = GetWindow();
   }  

   void Mainloop() 
   {
      window->Draw();
   }

   ~Sandbox() 
   {}
};

xentu::Application *xentu::CreateApplication()
{
   return new Sandbox();
}
