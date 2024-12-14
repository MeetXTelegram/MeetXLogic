cmake_minimum_required(VERSION 3.16)

project(MeetXLogic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lc++")

find_package(spdlog REQUIRED)
find_package(TgBot REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS system)

include_directories(include)
message(STATUS "CXX_FLAGS is: ${CMAKE_CXX_FLAGS}")
message(STATUS "EXE_LINGER_FLAGS is: ${CMAKE_EXE_LINKER_FLAGS}")

add_library(MeetXLogic SHARED
    include/Logic.hpp
    src/MeetXStart.cpp
    src/Logic.cpp
    src/MainLoop.cpp
)

target_link_libraries(MeetXLogic PRIVATE TgBot::TgBot ${Boost_LIBRARIES} spdlog::spdlog Definitions)
