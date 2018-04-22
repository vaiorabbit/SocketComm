project( SocketCommServer )

file( GLOB SCS_LIB_HDRS "${CMAKE_CURRENT_LIST_DIR}/*.h" )
file( GLOB SCS_LIB_SRCS "${CMAKE_CURRENT_LIST_DIR}/*.cpp" )
add_executable( SocketCommServer ${SCS_LIB_HDRS} ${SCS_LIB_SRCS} )
include_directories( ${CMAKE_CURRENT_LIST_DIR}/../.. )

set_property(TARGET SocketCommServer PROPERTY CXX_STANDARD 14)
