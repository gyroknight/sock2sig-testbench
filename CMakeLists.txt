cmake_minimum_required(VERSION 3.13)

project(sock2sig-testbench
    VERSION 0.1
    DESCRIPTION "Testbench for sock2sig SystemC module"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

find_package(PkgConfig REQUIRED)

pkg_check_modules(SYSTEMC REQUIRED IMPORTED_TARGET systemc)
pkg_check_modules(TLM2 REQUIRED IMPORTED_TARGET tlm)

add_executable(sock2sig-tb "")
target_include_directories(sock2sig-tb PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_sources(sock2sig-tb
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/src/bytePrinter.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/stringProducer.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/src/testbench.cc"
)

target_link_libraries(sock2sig-tb PkgConfig::SYSTEMC PkgConfig::TLM2)

# target_compile_definitions(
#     sock2sig-tb
#     PUBLIC
#     SC_INCLUDE_DYNAMIC_PROCESSES
# )

target_compile_options(sock2sig-tb
    PUBLIC -Wall
)