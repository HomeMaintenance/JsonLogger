cmake_minimum_required(VERSION 3.20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

find_package(jsoncpp CONFIG REQUIRED)

add_library(JsonLogger
    JsonLogger.h
    JsonLogger.cpp
)
target_include_directories(JsonLogger PUBLIC ${CMAKE_CURRENT_LIST_DIR})

if(DEFINED CROSS_COMPILE)
target_link_libraries(JsonLogger PUBLIC
    jsoncpp_object
    jsoncpp_static
    JsonCpp::JsonCpp
)
else()
target_link_libraries(JsonLogger PUBLIC
    jsoncpp_lib
    jsoncpp_object
    JsonCpp::JsonCpp
)
endif()
