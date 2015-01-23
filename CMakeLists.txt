cmake_minimum_required(VERSION 2.8)

# 如果存在 clang 使用 clang 做爲默認的編譯器
if (NOT CMAKE_C_COMPILER AND NOT CMAKE_CXX_COMPILER)
  find_program(CLANG "clang")
  find_program(CLANG_CXX "clang++")
  if (CLANG AND CLANG_CXX)
    set(CMAKE_C_COMPILER ${CLANG})
    set(CMAKE_CXX_COMPILER ${CLANG_CXX})
  endif (CLANG AND CLANG_CXX)
endif (NOT CMAKE_C_COMPILER AND NOT CMAKE_CXX_COMPILER)

# 設置項目名
project(UNP)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING
    "Choose the type of build, options are: Non Debug Release RelWithDebInfo
MinSizeRel."
    FORCE)
endif ()

set(CMAKE_C_FLAGS_DEBUG "$ENV{CFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_C_FLAGS_RELEASE "$ENV{CFLAGS} -O2 -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O2 -Wall")

# 添加自定義模塊路徑
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${PROJECT_SOURCE_DIR}/cmake"
  "${PROJECT_SOURCE_DIR}/cmake/kde-modules"
  "${PROJECT_SOURCE_DIR}/cmake/modules"
)

# 開關選項
option(USE_READLINE_NOBUFFER "使用不帶緩沖的readline函數" OFF)
option(BUILD_TESTS "生成單元測試" OFF)

# 包含 config-ix.cmake 以檢查系統環境
include(config-ix)

# 設置機器信息配置文件輸出
configure_file(
  "${PROJECT_SOURCE_DIR}/include/config.h.in"
  "${PROJECT_BINARY_DIR}/include/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/include")

add_subdirectory(lib)
add_subdirectory(libfree)
add_subdirectory(intro)

if (BUILD_TESTS)
  add_subdirectory(gtest-1.7.0)
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

  add_subdirectory(test)

  enable_testing()
  add_test(NAME runUnitTests COMMAND runUnitTests)
  add_custom_target(check COMMAND runUnitTests)
endif (BUILD_TESTS)