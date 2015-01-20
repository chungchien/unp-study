INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

ADD_EXECUTABLE(daytimetcpcli daytimetcpcli.c)
ADD_EXECUTABLE(daytimetcpcliv6 daytimetcpcliv6.c)
ADD_EXECUTABLE(daytimetcpsrv daytimetcpsrv.c)
ADD_EXECUTABLE(byteorder byteorder.c)

TARGET_LINK_LIBRARIES(daytimetcpcli unp)
TARGET_LINK_LIBRARIES(daytimetcpcliv6 unp)
TARGET_LINK_LIBRARIES(daytimetcpsrv unp)
TARGET_LINK_LIBRARIES(byteorder unp)

INSTALL(TARGETS
  daytimetcpcli
  daytimetcpcliv6
  daytimetcpsrv
  byteorder
  RUNTIME DESTINATION bin)
