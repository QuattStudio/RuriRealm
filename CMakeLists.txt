cmake_minimum_required(VERSION 3.10)
project(Ruri)

set(CMAKE_C_STANDARD 99)

# Add GLFW as a subdirectory
add_subdirectory(src/glfw)

# Find OpenGL
find_package(OpenGL REQUIRED)

# Your application executable
add_executable(Ruri src/main.c)

# Link GLFW and OpenGL to your application
target_link_libraries(Ruri glfw OpenGL::GL)
