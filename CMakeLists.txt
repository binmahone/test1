set( CMAKE_VERBOSE_MAKEFILE on )
set_property(GLOBAL PROPERTY GLOBAL_DEPENDS_DEBUG_MODE 1)

cmake_minimum_required(VERSION 3.20)
project(test1)

set(CMAKE_CXX_STANDARD 17)
set(VERBOSE ON)

find_package(Boost REQUIRED COMPONENTS
        system filesystem regex context program_options thread)

add_library(libb SHARED libb_bar.cpp)

add_executable(test1 main.cpp )

add_library(jemalloc STATIC IMPORTED)

#change this absolute URL
set_target_properties(jemalloc PROPERTIES IMPORTED_LOCATION /data0/hongbin/code/ClickHouse/cmake-build-release/contrib/jemalloc-cmake/lib_jemalloc.a)

#set_target_properties(jemalloc PROPERTIES IMPORTED_LOCATION /usr/lib/x86_64-linux-gnu/libjemalloc.so)
target_link_libraries(libb PRIVATE jemalloc)
target_link_libraries(libb PRIVATE -lpthread -ldl)
target_compile_options(libb PRIVATE -fPIC)

target_link_libraries(test1 PRIVATE -ldl)

target_link_libraries(test1 PRIVATE libb)


#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v -stdlib=libc++ -fuse-ld=lld")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lc++abi -lpthread -ldl")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v ")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ")


#target_compile_options(test1 PRIVATE -stdlib=libc++)
#target_link_options(test1 PRIVATE -lc++abi )
