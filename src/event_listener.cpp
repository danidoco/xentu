#include "xentu/event/event_listener.hpp"

namespace xentu
{
   EventListener::EventListener(const std::function<void()> &callback)
      : dispatchCallback(callback)
   {}
} // namespace xentu