#include "xentu/xentu.hpp"

class Sandbox : public xentu::Application
{
public:
   Sandbox()
      : Application("Sandbox", 1920, 1080, true)
   {
      XN_INFO("{} running!", GetApplicationName());
      XN_DEBUGBREAK();

      window = GetWindow();
   }  

   void Mainloop() 
   {
      window->Draw();
   }

   ~Sandbox() 
   {}

private:
   std::shared_ptr<xentu::Window> window;
};

xentu::Application *xentu::CreateApplication()
{
   return new Sandbox();
}
