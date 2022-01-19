#include "xentu/xentu.hpp"
#include <iostream>

class Sandbox : public xentu::Application
{
public:
   Sandbox() {}

   void Mainloop() {}

   ~Sandbox() {}
};

xentu::Application *xentu::CreateApplication()
{
   return new Sandbox();
}
