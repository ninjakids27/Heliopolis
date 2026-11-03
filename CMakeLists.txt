cmake_minimum_required(VERSION 3.16)
project(MD)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MD src/main.cpp
        src/MDMath/Matrix.h
        src/MDMath/NumberTheoryOPS.cpp
        src/MDMath/NumberTheoryOPS.h
        src/ANSI_COLORS.h
        src/MDMath/MatrixOPS.h
        src/unitTests.cpp
)

get_filename_component(MINGW_BIN_DIR ${CMAKE_CXX_COMPILER} DIRECTORY)
get_filename_component(MINGW_ROOT_DIR ${MINGW_BIN_DIR} DIRECTORY)

# Prefer the static archives (.a) over the shared import libs (.dll.a) so the
# resulting exe does not depend on libgmp*.dll being on PATH at run time.
set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

find_path(GMP_INCLUDE_DIR gmpxx.h HINTS "${MINGW_ROOT_DIR}/include")
find_library(GMP_LIB gmp HINTS "${MINGW_ROOT_DIR}/lib")
find_library(GMPXX_LIB gmpxx HINTS "${MINGW_ROOT_DIR}/lib")

if(NOT GMP_INCLUDE_DIR OR NOT GMP_LIB OR NOT GMPXX_LIB)
    message(FATAL_ERROR "GMP (with C++ bindings) not found. On MSYS2, install it with: pacman -S mingw-w64-ucrt-x86_64-gmp, and build this project with the UCRT64 toolchain.")
endif()

target_include_directories(MD PRIVATE ${GMP_INCLUDE_DIR})
target_link_libraries(MD PRIVATE ${GMPXX_LIB} ${GMP_LIB})
target_link_options(MD PRIVATE -static)
