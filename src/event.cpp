#include "xentu/event/event_category.hpp"
#include "xentu/event/event_type.hpp"
#include "xentu/event/event.hpp"
#include "xentu/event/event_listener.hpp"

namespace xentu
{
   Event::Event()
      : category(category)
      , type(type)
   {}

   void Event::AddListener(const EventListener &listener)
   {
      listeners.push_back(listener);
   }

   void Event::Dispatch()
   {
      for (auto &listener : listeners)
      {
         std::function<void()> callback = listener->GetDispatchCallback();
         callback();
      }
   }

} // namespace xentu
