#pragma once




#include <stdint.h>

#if UINTPTR_MAX != UINT64_MAX
    #error "Ruri requires a 64-bit platform"
#endif




/* Operating system */
#if defined(_WIN32)
    #define RPLATFORM_WINDOWS 1

#elif defined(__linux__)
    #define RPLATFORM_LINUX 1

#elif defined(__APPLE__) && defined(__MACH__)
    #define RPLATFORM_MACOS 1

#elif defined(__ANDROID__)
    #define RPLATFORM_ANDROID 1

#else

    #error "Unsupported platform"

#endif


/* Window system */
#if RURI_PLATFORM_LINUX

    #if defined(RUSE_WAYLAND)
        #define RPLATFORM_LINUX_WAYLAND 1

    #elif defined(RUSE_X11)
        #define RPLATFORM_LINUX_X11 1

    #else
        #error "Linux requires X11 or Wayland"
    #endif

#endif



