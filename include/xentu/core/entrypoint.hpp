#pragma once

#include "xentu/core/application.hpp"
#include "xentu/debug/logger.hpp"

extern xentu::Application *xentu::CreateApplication();

int main(int argc, char const *argv[])
{
   auto app = xentu::CreateApplication();
   app->Run();

   delete app;

   return 0;
}
