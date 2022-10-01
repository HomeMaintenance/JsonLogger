find_package(GTest CONFIG REQUIRED)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_executable(JsonLogger_test JsonLogger_test.cpp)
target_include_directories(JsonLogger_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(JsonLogger_test PUBLIC JsonLogger)
target_link_libraries(JsonLogger_test PUBLIC GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(JsonLogger_test)
