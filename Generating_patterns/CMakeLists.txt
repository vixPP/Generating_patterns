cmake_minimum_required(VERSION 3.20)

project(Generation_patterns)

set (PostgreSQl_ADDITIONAL_VERSIONS "16")

add_executable(Generation_patterns main.cpp "sql_query_builder.h")

add_subdirectory("C:\\Program Files\\libpq++\\libpqxx-7.9.1\\libpqxx-7.9.1" libpqxx-build) 

target_compile_features(Generation_patterns PRIVATE cxx_std_20) 

target_link_libraries(Generation_patterns pqxx)