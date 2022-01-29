#pragma once

#include <queue>
#include "xentu/event/event_listener.hpp"
#include "xentu/event/event_type.hpp"

namespace xentu
{  
   class Event
   {
   private:
      EventCategory category;
      EventType type;
      std::queue<EventListener> listenerQueue;
   
   public:
      void AddListener(const EventListener &listener);
      void ClearListenerQueue();
      void Dispatch();
   };
} // namespace xentu

