// #include "core/log.h"

// #include <stdio.h>
// #include <stdarg.h>

// static void Log_Write(
//     const char* level,
//     const char* fmt,
//     va_list args)
// {
//     printf("[%s] > ", level);

//     vprintf(fmt, args);

//     putchar('\n');
// }

// void Log_Info(const char* fmt, ...)
// {
//     va_list args;
//     va_start(args, fmt);

//     Log_Write("INFO", fmt, args);

//     va_end(args);
// }

// void Log_Warn(const char* fmt, ...)
// {
//     va_list args;
//     va_start(args, fmt);

//     Log_Write("WARN", fmt, args);

//     va_end(args);
// }

// void Log_Error(const char* fmt, ...)
// {
//     va_list args;
//     va_start(args, fmt);

//     Log_Write("ERROR", fmt, args);

//     va_end(args);
// }

// void Log_Debug(const char* fmt, ...)
// {
//     va_list args;
//     va_start(args, fmt);

//     Log_Write("DEBUG", fmt, args);

//     va_end(args);
// }












#include "core/log.h"

#include <stdio.h>
#include <stdarg.h>

static void Log_Write(
    const char* level,
    int line,
    const char* fmt,
    va_list args)
{
    printf("%s |%d| > ", level, line);

    vprintf(fmt, args);

    putchar('\n');
}

void Log_Info(int line, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    Log_Write("INFO", line, fmt, args);

    va_end(args);
}

void Log_Warn(int line, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    Log_Write("WARN", line, fmt, args);

    va_end(args);
}

void Log_Error(int line, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    Log_Write("ERROR", line, fmt, args);

    va_end(args);
}

void Log_Debug(int line, const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    Log_Write("DEBUG", line, fmt, args);

    va_end(args);
}
