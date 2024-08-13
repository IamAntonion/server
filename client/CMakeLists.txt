cmake_minimum_required(VERSION 3.14)

project(client LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(client
  main.cpp
  client.cpp
  client.h
)

install(TARGETS client
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
