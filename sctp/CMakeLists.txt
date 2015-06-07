set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

add_executable(sctpserv01
  sctpserv01.c 
  sctp_getnostrm.c
  sctp_addr_to_associd.c
  )
target_link_libraries(sctpserv01 unp)

add_executable(sctpclient01
  sctpclient01.c
  sctp_strcli.c
  sctp_strcliecho.c
  )
target_link_libraries(sctpclient01 unp)

add_executable(sctpserv02
  sctpserv02.c 
  sctp_getnostrm.c
  sctp_addr_to_associd.c
  )
target_link_libraries(sctpserv02 unp)


add_executable(sctpclient02
  sctpclient02.c
  sctp_strcli.c
  sctp_strcliecho.c
  )
target_link_libraries(sctpclient02 unp)

add_executable(sctpserv03
  sctpserv03.c 
  sctp_getnostrm.c
  sctp_addr_to_associd.c
  )
target_link_libraries(sctpserv03 unp)

add_executable(sctpclient03
  sctpclient03.c
  sctp_strcli.c
  sctp_strcliecho.c
  )
target_link_libraries(sctpclient03 unp)
