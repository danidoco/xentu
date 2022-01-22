#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace xentu
{
   class Logger
   {
   private:
      static std::shared_ptr<spdlog::logger> engineLogger;
      static std::shared_ptr<spdlog::logger> applicationLogger;

   public:
      static void Init(const char *name);

      inline static std::shared_ptr<spdlog::logger> &GetEngineLogger()
      {
         return engineLogger;
      }

      inline static std::shared_ptr<spdlog::logger> &GetApplicationLogger()
      {
         return applicationLogger;
      }
   };
} // namespace xentu

#ifdef XN_DEBUG_BUILD
   #define XN_ENGINE_TRACE(...)                                                \
      ::xentu::Logger::GetEngineLogger()->trace(__VA_ARGS__)
   #define XN_ENGINE_INFO(...)                                                 \
      ::xentu::Logger::GetEngineLogger()->info(__VA_ARGS__)
   #define XN_ENGINE_WARN(...)                                                 \
      ::xentu::Logger::GetEngineLogger()->warn(__VA_ARGS__)
   #define XN_ENGINE_ERROR(...)                                                \
      ::xentu::Logger::GetEngineLogger()->error(__VA_ARGS__)
   #define XN_ENGINE_CRITICAL(...)                                             \
      ::xentu::Logger::GetEngineLogger()->critical(__VA_ARGS__)

   #define XN_TRACE(...)                                                       \
      ::xentu::Logger::GetApplicationLogger()->trace(__VA_ARGS__)
   #define XN_INFO(...)                                                        \
      ::xentu::Logger::GetApplicationLogger()->info(__VA_ARGS__)
   #define XN_WARN(...)                                                        \
      ::xentu::Logger::GetApplicationLogger()->warn(__VA_ARGS__)
   #define XN_ERROR(...)                                                       \
      ::xentu::Logger::GetApplicationLogger()->error(__VA_ARGS__)
   #define XN_CRITICAL(...)                                                    \
      ::xentu::Logger::GetApplicationLogger()->critical(__VA_ARGS__)
#elif XN_RELEASE_BUILD
   #define XN_ENGINE_TRACE(...)
   #define XN_ENGINE_INFO(...)
   #define XN_ENGINE_WARN(...)
   #define XN_ENGINE_ERROR(...)                                                \
      ::xentu::Logger::GetEngineLogger()->error(__VA_ARGS__)
   #define XN_ENGINE_CRITICAL(...)                                             \
      ::xentu::Logger::GetEngineLogger()->critical(__VA_ARGS__)

   #define XN_TRACE(...)
   #define XN_INFO(...)
   #define XN_WARN(...)
   #define XN_ERROR(...)                                                       \
      ::xentu::Logger::GetApplicationLogger()->error(__VA_ARGS__)
   #define XN_CRITICAL(...)                                                    \
      ::xentu::Logger::GetApplicationLogger()->critical(__VA_ARGS__)
#endif
