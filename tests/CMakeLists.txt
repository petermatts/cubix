# enable_testing()
# find_package(GTest REQUIRED)

# add_executable(cubix_tests test_cube.cpp)
# target_link_libraries(cubix_tests PRIVATE cubix_core GTest::gtest_main)

# include(GoogleTest)
# gtest_discover_tests(cubix_tests)

#####################################################

#? make makefile not remove google test installation on clean
# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
# )
# FetchContent_MakeAvailable(googletest)

# enable_testing()
