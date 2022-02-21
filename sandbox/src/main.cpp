#include "xentu/xentu.hpp"

class Sandbox : public xentu::Application
{
public:
   Sandbox()
      : Application("Sandbox")
   {
      XN_INFO("{} running!", GetApplicationName());
      
      window = xentu::CreateWindow(800, 800, "Sandbox", false);
      
      windowCloseEventListener = std::make_shared<xentu::EventListener>([this]() -> void { Terminate(); } );

      window->GetEventDispatcher()->AddListener(windowCloseEventListener);
   }  

   void Mainloop() 
   {
      window->Draw();
   }

   ~Sandbox() 
   {
   }
};

xentu::Application *xentu::CreateApplication()
{
   return new Sandbox();
}
