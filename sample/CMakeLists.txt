cmake_minimum_required(VERSION 3.8)

project(pengine_sample VERSION 0.1.0 LANGUAGES CXX)

set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

file(GLOB_RECURSE SOURCES ${SRCDIR}/*.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${SRCDIR})
target_link_libraries(${PROJECT_NAME} pengine)

