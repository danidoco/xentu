#include "xentu/event/event.hpp"

namespace xentu
{
   Event::Event(EventCategory category, EventType type)
      : category(category)
      , type(type)
   {}

   bool Event::IsTypeInCategory() const
   {
      // TODO: implement this method
      XN_WARN("Event::IstTypeInCategory is not implemented yet");
      return true;
   }
} // namespace xentu
