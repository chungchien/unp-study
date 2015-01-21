cmake_minimum_required(VERSION 2.8)
project(UNP)

# 添加自定義模塊路徑
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${PROJECT_SOURCE_DIR}/cmake"
  "${PROJECT_SOURCE_DIR}/cmake/kde-modules"
  "${PROJECT_SOURCE_DIR}/cmake/modules"
)

# 檢查頭文件是否存在
include(CheckIncludeFiles)
check_include_files(strings.h HAVE_STRINGS_H)
check_include_files(string.h HAVE_STRING_H)
check_include_files(netinet/in.h HAVE_NETINET_IN_H)
check_include_files(arpa/inet.h HAVE_ARPA_INET_H)

# 檢查函數是否存在
include(CheckFunctionExists)
check_function_exists(bzero HAVE_BZERO)
check_function_exists(inet_pton HAVE_INET_PTON)
check_function_exists(inet_ntop HAVE_INET_NTOP)
check_function_exists(snprintf HAVE_SNPRINTF)
check_function_exists(vsnprintf HAVE_VSNPRINTF)

# 檢查符號是否定義
include(CheckSymbolExists)
check_symbol_exists(INET_ADDRSTRLEN netinet/in.h HAVE_INET_ADDRSTRLEN)
check_symbol_exists(INET6_ADDRSTRLEN netinet/in.h HAVE_INET6_ADDRSTRLEN)

# 設置CPU_VENDOR_OS的值
include(GetHostTriple)
get_host_triple(CPU_VENDOR_OS)

# 設置機器信息配置文件輸出
configure_file(
  "${PROJECT_SOURCE_DIR}/include/config.h.in"
  "${PROJECT_BINARY_DIR}/include/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}/include")

add_subdirectory(lib)
add_subdirectory(libfree)
add_subdirectory(intro)
