cmake_minimum_required(VERSION 2.8)
project(UNP)

# 添加自定義模塊路徑
set(CMAKE_MODULE_PATH
  ${CMAKE_MODULE_PATH}
  "${PROJECT_SOURCE_DIR}/cmake"
  "${PROJECT_SOURCE_DIR}/cmake/kde-modules"
  "${PROJECT_SOURCE_DIR}/cmake/modules"
)

# 開關選項
option(USE_READLINE_NOBUFFER "使用不帶緩沖的readline函數" OFF)


# 包含 config-ix.cmake 以檢查系統環境
include(config-ix)

# 設置機器信息配置文件輸出
configure_file(
  "${PROJECT_SOURCE_DIR}/include/config.h.in"
  "${PROJECT_BINARY_DIR}/include/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}/include")

add_subdirectory(lib)
add_subdirectory(libfree)
add_subdirectory(intro)
