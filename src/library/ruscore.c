#include "library/ruscore.h"





#if defined(_WIN32)

#include <windows.h>



bool lib_SetThreadPriorityMax(void)
{
    return SetThreadPriority(
        GetCurrentThread(),
        THREAD_PRIORITY_TIME_CRITICAL
    ) != 0;
}


void lib_Sleep(u32 milliseconds)
{
    Sleep(milliseconds);
}


#elif defined(__linux__)

#include <pthread.h>
#include <sched.h>

bool lib_SetThreadPriorityMax(void)
{
    struct sched_param param;

    param.sched_priority =
        sched_get_priority_max(SCHED_FIFO);

    if (param.sched_priority == -1)
        return false;

    return pthread_setschedparam(
        pthread_self(),
        SCHED_FIFO,
        &param
    ) == 0;
}




#include <time.h>

void lib_Sleep(u32 milliseconds)
{
    struct timespec time;

    time.tv_sec = milliseconds / 1000;
    time.tv_nsec = (milliseconds % 1000) * 1000000;

    nanosleep(&time, nil);
}


#elif defined(__APPLE__)

#include <pthread.h>

bool lib_SetThreadPriorityMax(void)
{
    return pthread_set_qos_class_self_np(
        QOS_CLASS_USER_INTERACTIVE,
        0
    ) == 0;
}




void lib_Sleep(u32 milliseconds)
{
    usleep(milliseconds * 1000);
}




#else

bool lib_SetThreadPriorityMax(void)
{
    return false;
}


void lib_Sleep(u32 milliseconds)
{
    (void)milliseconds;
}

#endif
