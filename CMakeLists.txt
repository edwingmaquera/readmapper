cmake_minimum_required(VERSION 3.0.0)
project(readmapper)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(src)
configure_file(
    "${CMAKE_SOURCE_DIR}/cmake_uninstall.cmake.in"
    "${CMAKE_SOURCE_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake_uninstall.cmake)
    