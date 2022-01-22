#include "xentu/debug/logger.hpp"

namespace xentu
{
   std::shared_ptr<spdlog::logger> Logger::engineLogger;
   std::shared_ptr<spdlog::logger> Logger::applicationLogger;

   void Logger::Init(const char *applicationName)
   {
      spdlog::set_pattern("%Y-%m-%d %T [%n] %^%8l | %v%$");

      engineLogger = spdlog::stdout_color_mt("xentu");
      engineLogger->set_level(spdlog::level::trace);

      applicationLogger = spdlog::stdout_color_mt(applicationName);
      applicationLogger->set_level(spdlog::level::trace);
   }

} // namespace xentu
