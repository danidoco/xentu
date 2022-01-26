#pragma once

#include "xentu/core/application.hpp"
#include "xentu/debug/logger.hpp"

extern xentu::Application *xentu::CreateApplication();

int main()
{
   auto app = xentu::CreateApplication();
   app->Run();

   delete app;

   return 0;
}
