cmake_minimum_required(VERSION 3.5)
project(renderBox)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

IF (WIN32)
    set(OPENGL_LIBRARIES -lopengl32)
ELSE()
    set(OPENGL_LIBRARIES -ldl -lGLEW -lGL -lGLU)
ENDIF()

set(SOURCE_FILES main.cpp Window.cpp math/Vector2.cpp)
add_executable(renderBox ${SOURCE_FILES})
target_include_directories(renderBox PRIVATE include)

IF (WIN32)
    target_link_libraries(renderBox "${CMAKE_SOURCE_DIR}/lib/libSOIL.a")
    target_link_libraries(renderBox "${CMAKE_SOURCE_DIR}/lib/libfreetype.a")
    target_link_libraries(renderBox "${CMAKE_SOURCE_DIR}/lib/libglfw3.a")
    target_link_libraries(renderBox ${OPENGL_LIBRARIES})
ELSE()
    target_link_libraries(renderBox glfw ${GLFW_LIBRARIES})
    target_link_libraries(renderBox ${OPENGL_LIBRARIES})
ENDIF()
