#include <iostream>
#include "xentu/xentu.hpp"

class Sandbox : public Xentu::Application
{
public:
   Sandbox()
   {
   }

   void mainloop() override
   {

   }

   ~Sandbox()
   {
   }
};

Xentu::Application *Xentu::get_application()
{
   return new Sandbox();
}