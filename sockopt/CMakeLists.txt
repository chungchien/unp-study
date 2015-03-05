add_executable(checkopts checkopts.c)
target_link_libraries(checkopts unp)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/bin")