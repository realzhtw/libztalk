cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(libztalk VERSION 1.0 LANGUAGES CXX)

add_library(ztalk
  include/ztalk/types.h
  include/ztalk/stdio.h
  include/ztalk/read.h

  src/not_implemented.h
  src/not_implemented.cpp
  src/stdio.cpp
  src/read.cpp
)

target_include_directories(ztalk
  PUBLIC
    include
)

target_link_libraries(ztalk
  PUBLIC
    vegan
)

option(LIBVEGAN_BUILD_TESTS "" OFF)
option(LIBVEGAN_BUILD_EXAMPLES "" OFF)

add_subdirectory(extern)
#add_subdirectory(tests)
add_subdirectory(examples)
