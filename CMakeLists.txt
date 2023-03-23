cmake_minimum_required(VERSION 3.24)
project(test1)

set(CMAKE_CXX_STANDARD 17)
set(VERBOSE ON)

find_package(Boost REQUIRED COMPONENTS
        system filesystem regex context program_options thread)

add_library(libb libb_bar.cpp)
add_library(libc libc_bar.cpp)

add_executable(test1 main.cpp )
target_link_libraries(test1 libc)
target_link_libraries(test1 libb)

add_library(jemalloc STATIC IMPORTED)
set_target_properties(jemalloc PROPERTIES IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libjemalloc.a)
target_link_libraries(test1 jemalloc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++ -fuse-ld=lld")

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi -lpthread -ldl")


#target_compile_options(test1 PRIVATE -stdlib=libc++)
#target_link_options(test1 PRIVATE -lc++abi )
