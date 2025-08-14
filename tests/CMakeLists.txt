enable_testing()
find_package(GTest REQUIRED)

add_executable(cubix_tests test_cube.cpp)
target_link_libraries(cubix_tests PRIVATE cubix_core GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(cubix_tests)