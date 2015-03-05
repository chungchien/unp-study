add_executable(printtcpudpbufsize printtcpudpbufsize.c)
target_link_libraries(printtcpudpbufsize unp)

add_executable(daytimetcpcli_testmss daytimetcpcli_testmss.c)
target_link_libraries(daytimetcpcli_testmss unp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")