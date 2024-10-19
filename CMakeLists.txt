cmake_minimum_required(VERSION 3.22)

# Setup project
project(LwLibPROJECT)

if(NOT PROJECT_IS_TOP_LEVEL)
    add_subdirectory(lwshell)
else()
    add_executable(${PROJECT_NAME})
    target_sources(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/dev/main.cpp
    )
    target_include_directories(${PROJECT_NAME} PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/dev
    )

    # Add subdir with lwshell and link to project
    add_subdirectory(signal)
    target_link_libraries(${PROJECT_NAME} signal)

    # Add compile options to the library, which will propagate options to executable through public link
    target_compile_definitions(${CMAKE_PROJECT_NAME} INTERFACE WIN32 _DEBUG CONSOLE)
    target_compile_options(${CMAKE_PROJECT_NAME} PUBLIC -Wall -Wextra -Wpedantic)
endif()
