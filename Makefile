CC = gcc
CFLAGS = -Wall -Wextra -O2 -Isrc/glfw/include

# GLFW source files
GLFW_SRCS = src/glfw/context.c \
            src/glfw/init.c \
            src/glfw/input.c \
            src/glfw/monitor.c \
            src/glfw/window.c \
            src/glfw/vulkan.c \
            src/glfw/egl_context.c \
            src/glfw/win32_init.c \
            src/glfw/win32_monitor.c \
            src/glfw/win32_window.c \
            src/glfw/win32_joystick.c \
            src/glfw/egl_context.c

# Your source files
YOUR_SRCS = src/main.c

all: myapp.exe

myapp.exe: $(YOUR_SRCS) $(GLFW_SRCS)
	$(CC) $(CFLAGS) -o myapp.exe $^ -luser32 -lshell32 -lwinmm -lgdi32

clean:
	rm -f myapp.exe
