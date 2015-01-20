cmake_minimum_required(VERSION 2.8)
project(UNP)

# 添加自定義模塊路徑
set(CMAKE_MODULE_PATH
  "${PROJECT_SOURCE_DIR}/cmake"
  "${PROJECT_SOURCE_DIR}/cmake/modules"
)


include(GetHostTriple)
get_host_triple(CPU_VENDOR_OS)

# 設置機器信息配置文件輸出
configure_file(
  "${PROJECT_SOURCE_DIR}/include/config.h.in"
  "${PROJECT_BINARY_DIR}/include/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}/include")

add_subdirectory(lib lib)
add_subdirectory(intro bin)
