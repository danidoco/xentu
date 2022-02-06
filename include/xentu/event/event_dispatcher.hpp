#pragma once

#include <vector>

#include "xentu/event/event.hpp"
#include "xentu/event/event_listener.hpp"

namespace xentu
{
   class EventDispatcher
   {
   private:
      Event event;
      std::vector<EventListener> listeners;

   public:
      EventDispatcher(const Event &event);
      void AddListener(const EventListener &listener);
   };
} // namespace xentu
