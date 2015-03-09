add_executable(printtcpudpbufsize printtcpudpbufsize.c)
target_link_libraries(printtcpudpbufsize unp)

add_executable(daytimetcpcli_testmss daytimetcpcli_testmss.c)
target_link_libraries(daytimetcpcli_testmss unp)

add_executable(reuseaddrcli reuseaddrcli.c)
target_link_libraries(reuseaddrcli unp)

add_executable(reuseaddrserv reuseaddrserv.c)
target_link_libraries(reuseaddrserv unp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")