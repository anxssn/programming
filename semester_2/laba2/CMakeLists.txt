cmake_minimum_required(VERSION 3.10)

project(student_manager)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Опция выбора типа библиотеки 
option(BUILD_SHARED_LIBS "Build shared library" OFF)

# Debug/Release 
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Компиляция библиотеки
add_library(student src/student.c)

# Компиляция исполняемого файла
add_executable(program src/main.c)

# Линковка
target_link_libraries(program student)