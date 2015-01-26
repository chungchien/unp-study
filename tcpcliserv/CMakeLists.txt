add_executable(tcpserv tcpserv.c)
target_link_libraries(tcpserv unp)

add_executable(tcpcli tcpcli.c)
target_link_libraries(tcpcli unp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
