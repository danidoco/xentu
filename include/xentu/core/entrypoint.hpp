#pragma once

#include "xentu/core/application.hpp"

extern xentu::Application *xentu::CreateApplication();

int main(int argc, char const *argv[])
{
   auto app = xentu::CreateApplication();
   app->Run();
   delete app;
   return 0;
}
