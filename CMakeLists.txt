cmake_minimum_required(VERSION 3.0.0)
project(sorting VERSION 0.1.0)

find_package(SFML 2.5.1 REQUIRED COMPONENTS graphics)

add_executable(sorting 
    main.cpp
    )

target_include_directories(sorting PRIVATE src)
target_link_libraries(sorting PRIVATE sfml-graphics)
target_compile_features(sorting PRIVATE cxx_std_17)
