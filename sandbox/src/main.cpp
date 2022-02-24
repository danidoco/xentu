#include "xentu/xentu.hpp"

class Sandbox : public xentu::Application
{
public:
   Sandbox()
      : Application("Sandbox", 1920, 1080, true)
   {
      XN_INFO("{} running!", GetApplicationName());
      XN_TRACE("it's a trace");
      XN_INFO("it's an info");
      XN_WARN("it's a warning");
      XN_ERROR("it's an error");
      XN_CRITICAL("it's a critical error");

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
