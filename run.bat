gcc -Wall -Wextra -O2 -Isrc/glfw/include -o myapp.exe src/main.c src/glfw/context.c src/glfw/init.c src/glfw/input.c src/glfw/monitor.c src/glfw/window.c src/glfw/vulkan.c src/glfw/egl_context.c src/glfw/win32_init.c src/glfw/win32_monitor.c  src/glfw/win32_window.c src/glfw/win32_joystick.c src/glfw/win32_thread.c src/glfw/win32_time.c src/glfw/wgl_context.c -luser32 -lshell32 -lwinmm -lgdi32 -lopengl32


@REM C:\Users\CurseEye\OneDrive\Desktop\Ruri\build>cmake -G "MinGW Makefiles" ..
@REM -- Including Win32 support
@REM -- Found OpenGL: opengl32
@REM -- Configuring done (0.2s)
@REM -- Generating done (0.2s)
@REM -- Build files have been written to: C:/Users/CurseEye/OneDrive/Desktop/Ruri/build

@REM C:\Users\CurseEye\OneDrive\Desktop\Ruri\build>mingw32-make
@REM [ 88%] Built target glfw
@REM [ 92%] Linking C executable Ruri.exe
@REM [ 96%] Built target Ruri
@REM [100%] Built target docs

@REM C:\Users\CurseEye\OneDrive\Desktop\Ruri\build>ruri