cmake_minimum_required(VERSION 3.10)
project(CipherProject VERSION 1.0)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Опции для отладки
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")

# Статическая библиотека
add_library(mylib STATIC mylib.c)

# Исполняемые файлы
add_executable(KeyTable KeyTable.c)
add_executable(DeKeyTable DeKeyTable.c)

# Линковка библиотеки
target_link_libraries(KeyTable mylib)
target_link_libraries(DeKeyTable mylib)

# Если нужно установить в систему
install(TARGETS KeyTable DeKeyTable DESTINATION bin)
install(TARGETS mylib DESTINATION lib)
install(FILES mylib.h DESTINATION include)