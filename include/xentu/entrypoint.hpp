#ifndef XN_ENTRYPOINT_H
#define XN_ENTRYPOINT_H

#include "xentu/application.hpp"

extern Xentu::Application *Xentu::get_application();

int main(int argc, char const *argv[])
{
   auto app = Xentu::get_application();
   app->run();
   delete app;
   return 0;
}


#endif