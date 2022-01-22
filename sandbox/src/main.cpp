#include "xentu/xentu.hpp"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"

class Sandbox : public xentu::Application
{
public:
   Sandbox()
      : Application("Sandbox")
   {
      XN_INFO("{} running!", GetApplicationName());
   }

   void Mainloop() {}

   ~Sandbox() {}
};

xentu::Application *xentu::CreateApplication()
{
   return new Sandbox();
}
