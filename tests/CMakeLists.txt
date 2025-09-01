enable_testing()

add_executable(cubix_tests test_main.cpp test_moves.cpp)
target_include_directories(cubix_tests PRIVATE ${tomlplusplus_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/inc)
target_link_libraries(cubix_tests PRIVATE GTest::gtest_main cubix_core)

include(GoogleTest)
gtest_discover_tests(cubix_tests)
