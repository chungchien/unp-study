INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

ADD_EXECUTABLE(daytimetcpcli daytimetcpcli.c)
ADD_EXECUTABLE(daytimetcpcliv6 daytimetcpcliv6.c)
TARGET_LINK_LIBRARIES(daytimetcpcli unp)
TARGET_LINK_LIBRARIES(daytimetcpcliv6 unp)

INSTALL(TARGETS daytimetcpcli daytimetcpcliv6
  RUNTIME DESTINATION bin)
