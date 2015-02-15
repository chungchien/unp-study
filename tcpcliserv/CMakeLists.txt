add_executable(tcpserv tcpserv.c sigchldwait.c)
target_link_libraries(tcpserv unp)

add_executable(tcpserv04 tcpserv04.c sigchldwait.c)
target_link_libraries(tcpserv04 unp)

add_executable(tcpcli tcpcli.c)
target_link_libraries(tcpcli unp)

add_executable(tcpcli04 tcpcli04.c)
target_link_libraries(tcpcli04 unp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
