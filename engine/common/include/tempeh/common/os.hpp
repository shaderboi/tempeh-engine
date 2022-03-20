#ifndef _TEMPEH_COMMON_OS_HPP
#define _TEMPEH_COMMON_OS_HPP

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#    define TEMPEH_OS_WINDOWS
#elif __APPLE__
#   include <TargetConditionals.h>
#   if TARGET_IPHONE_SIMULATOR
#      error "Unimplemented target operating system"
#   elif TARGET_OS_MACCATALYST
#      error "Unimplemented target operating system"
#   elif TARGET_OS_IPHONE
#      error "Unimplemented target operating system"
#   elif TARGET_OS_MAC
#      error "Unimplemented target operating system"
#   else
#      error "Unknown Apple platform"
#   endif
#elif __linux__
#   define TEMPEH_OS_LINUX
#elif __unix__
#   error "Unimplemented target operating system"
#elif defined(_POSIX_VERSION)
#   error "Unimplemented target operating system"
#else
#   error "Unknown OS"
#endif

#endif
