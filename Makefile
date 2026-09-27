# CC = gcc
# CFLAGS = -Wall -Wextra -O2 -Isrc/glfw/include

# # GLFW source files
# GLFW_SRCS = src/glfw/src/platform.c \
#             src/glfw/src/init.c \
#             src/glfw/src/input.c \
#             src/glfw/src/monitor.c \
#             src/glfw/src/window.c \
#             src/glfw/src/vulkan.c \
#             src/glfw/src/win32_init.c \
#             src/glfw/src/win32_monitor.c \
#             src/glfw/src/win32_window.c \
#             src/glfw/src/win32_joystick.c \
#             src/glfw/src/win32_thread.c \
#             src/glfw/src/win32_time.c \
#             src/glfw/src/win32_module.c 

# # Your source files
# YOUR_SRCS = src/main.c

# all: Ruri.exe

# Ruri.exe: $(YOUR_SRCS) $(GLFW_SRCS)
# 	$(CC) $(CFLAGS) -Iinclude -D_GLFW_WIN32 -o Ruri.exe $^ -luser32 -lshell32 -lwinmm -lgdi32

# clean:
# 	rm -f Ruri.exe




















CC = gcc

CFLAGS = -Wall -Wextra -O2 \
         -Isrc/glfw/include \
         -Iinclude \
         -D_GLFW_WIN32 -DENABLE_LOG -DRENABLE_DEEP_LOG

LDFLAGS = -luser32 -lshell32 -lwinmm -lgdi32


GLFW_SRCS = \
    src/glfw/src/platform.c \
    src/glfw/src/init.c \
    src/glfw/src/input.c \
    src/glfw/src/monitor.c \
    src/glfw/src/window.c \
    src/glfw/src/vulkan.c \
    src/glfw/src/win32_init.c \
    src/glfw/src/win32_monitor.c \
    src/glfw/src/win32_window.c \
    src/glfw/src/win32_joystick.c \
    src/glfw/src/win32_thread.c \
    src/glfw/src/win32_time.c \
    src/glfw/src/win32_module.c


YOUR_SRCS = \
    src/main.c \
    src/core/log.c


SRCS = $(YOUR_SRCS) $(GLFW_SRCS)

OBJS = $(patsubst src/%.c,build/%.o,$(SRCS))


all: Ruri.exe


Ruri.exe: $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)


# Generic rule for ANY source under src/
build/%.o: src/%.c
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	@if exist build rmdir /s /q build
	@if exist Ruri.exe del Ruri.exe