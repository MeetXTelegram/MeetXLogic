cmake_minimum_required(VERSION 3.16)

project(MeetXLogic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(spdlog REQUIRED)
find_package(TgBot REQUIRED)
find_package(Boost CONFIG REQUIRED COMPONENTS system)

include(GNUInstallDirs)

include_directories(include)


add_library(MeetXLogic STATIC
    include/Logic.hpp
    src/MeetXStart.cpp
    src/Logic.cpp
    src/MainLoop.cpp
)

target_link_libraries(MeetXLogic PRIVATE TgBot::TgBot ${Boost_LIBRARIES} spdlog::spdlog Definitions)

install(TARGETS MeetXLogic
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
install(FILES include/Logic.hpp DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/MeetXLogic)
