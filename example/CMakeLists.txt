cmake_minimum_required(VERSION 2.6)
project( SocketCommDemo )

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(server)
add_subdirectory(client)

