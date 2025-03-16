cmake_minimum_required(VERSION 3.8)

project(pengine VERSION 0.1.0 LANGUAGES CXX)

set(SRCDIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INCDIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIBDIR ${CMAKE_CURRENT_SOURCE_DIR}/libs)
set(TSTDIR ${CMAKE_CURRENT_SOURCE_DIR}/tests)
set(TRDDIR ${CMAKE_CURRENT_SOURCE_DIR}/third-party)
set(SMPDIR ${CMAKE_CURRENT_SOURCE_DIR}/sample)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(${TRDDIR}/entt)
add_subdirectory(${TRDDIR}/SFML)
file(GLOB_RECURSE SOURCES ${SRCDIR}/*.cpp)
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCDIR})
target_link_libraries(${PROJECT_NAME} EnTT sfml-system sfml-window sfml-graphics)

enable_testing()

file(GLOB_RECURSE TESTSRC ${TSTDIR}/*.cpp)
foreach(TESTFILE ${TESTSRC})
    get_filename_component(TSTNAME ${TESTFILE} NAME_WE)
    add_executable(${TSTNAME} ${TESTSRC})
    target_link_libraries(${TSTNAME} ${PROJECT_NAME})
    target_include_directories(${TSTNAME} PRIVATE ${INCDIR})
    add_test(NAME ${TSTNAME} COMMAND ${TSTNAME})
endforeach()

add_subdirectory(${SMPDIR})