add_executable(udpserv01 udpserv01.c)
target_link_libraries(udpserv01 unp)

add_executable(udpcli01 udpcli01.c)
target_link_libraries(udpcli01 unp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")