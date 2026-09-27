@REM gcc -Wall -Wextra -O2 -Isrc/glfw/include -o myapp.exe src/main.c src/glfw/context.c src/glfw/init.c src/glfw/input.c src/glfw/monitor.c src/glfw/window.c src/glfw/vulkan.c src/glfw/egl_context.c src/glfw/win32_init.c src/glfw/win32_monitor.c  src/glfw/win32_window.c src/glfw/win32_joystick.c src/glfw/win32_thread.c src/glfw/win32_time.c src/glfw/wgl_context.c -luser32 -lshell32 -lwinmm -lgdi32 -lopengl32


@echo off

cls


if "%1"=="-publish" (

    git add .
    git commit -m "%~2"
    git push

) else (

    if "%1"=="" (

        mingw32-make -j4
        Ruri.exe


    ) else if "%1"=="-rm" (

        mingw32-make clean

    ) else (

        mingw32-make -j%1
        Ruri.exe


    )

)