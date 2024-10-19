# Register core library
# This library is a header-only
add_library(signal INTERFACE)
target_include_directories(signal INTERFACE ${CMAKE_CURRENT_LIST_DIR}/src/include)
