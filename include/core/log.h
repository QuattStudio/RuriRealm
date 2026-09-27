#pragma once


void Log_Info(int line, const char* fmt, ...);
void Log_Warn(int line, const char* fmt, ...);
void Log_Error(int line, const char* fmt, ...);
void Log_Debug(int line, const char* fmt, ...);


#if defined(ENABLE_LOG)

#   define RLOG_INFO(...)  Log_Info(__LINE__, __VA_ARGS__)
#   define RLOG_WARN(...)  Log_Warn(__LINE__, __VA_ARGS__)
#   define RLOG_ERROR(...) Log_Error(__LINE__, __VA_ARGS__)
#   define RLOG_DEBUG(...) Log_Debug(__LINE__, __VA_ARGS__)


    // Deep log also includes internal systems such as renderer, GLFW, etc.
#   if defined(RENABLE_DEEP_LOG)

        // I in RLOGI stands for internal
#       define RLOGI_INFO(...)  Log_Info(__LINE__, __VA_ARGS__)
#       define RLOGI_WARN(...)  Log_Warn(__LINE__, __VA_ARGS__)
#       define RLOGI_ERROR(...) Log_Error(__LINE__, __VA_ARGS__)
#       define RLOGI_DEBUG(...) Log_Debug(__LINE__, __VA_ARGS__)

#   else

#       define RLOGI_INFO(...)
#       define RLOGI_WARN(...)
#       define RLOGI_ERROR(...)
#       define RLOGI_DEBUG(...)

#   endif


#else

#   define RLOG_INFO(...)
#   define RLOG_WARN(...)
#   define RLOG_ERROR(...)
#   define RLOG_DEBUG(...)

#   define RLOGI_INFO(...)
#   define RLOGI_WARN(...)
#   define RLOGI_ERROR(...)
#   define RLOGI_DEBUG(...)

#endif
