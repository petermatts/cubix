enable_testing()

add_executable(cubix_tests test_main.cpp)
target_include_directories(cubix_tests PRIVATE ${tomlplusplus_SOURCE_DIR})
target_link_libraries(cubix_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(cubix_tests)
