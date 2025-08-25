cmake_minimum_required(VERSION 3.15)
project(Cubix LANGUAGES CXX)

# Use C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable SWIG and Python
find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

foreach(lib ${Python3_LIBRARIES})
    if(lib MATCHES ".*/?python[0-9]+\\.lib$")
        set(Python3_LIB_ONLY "${lib}")
    endif()
endforeach()

# Add the main source directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Create a shared library for core logic
add_library(cubix_core
    src/cube.cpp
    src/common.cpp
    src/moves/B.cpp
    src/moves/D.cpp
    src/moves/E.cpp
    src/moves/F.cpp
    src/moves/L.cpp
    src/moves/M.cpp
    src/moves/R.cpp
    src/moves/S.cpp
    src/moves/U.cpp
    src/moves/X.cpp
    src/moves/Y.cpp
    src/moves/Z.cpp
)
target_include_directories(cubix_core PUBLIC src)


# SWIG configuration
set_source_files_properties(interface/cubix.i PROPERTIES CPLUSPLUS ON)
set(CMAKE_SWIG_FLAGS "-w503")

add_definitions(-DSWIG_PYTHON_INTERPRETER_NO_DEBUG)

swig_add_library(cubix_python
    LANGUAGE python
    TYPE MODULE
    SOURCES interface/cubix.i
            src/cube.cpp
            src/common.cpp
            src/moves/B.cpp
            src/moves/D.cpp
            src/moves/E.cpp
            src/moves/F.cpp
            src/moves/L.cpp
            src/moves/M.cpp
            src/moves/R.cpp
            src/moves/S.cpp
            src/moves/U.cpp
            src/moves/X.cpp
            src/moves/Y.cpp
            src/moves/Z.cpp
)

# Link SWIG module with Python and core logic
target_include_directories(cubix_python PRIVATE ${Python3_INCLUDE_DIRS})
swig_link_libraries(cubix_python ${Python3_LIB_ONLY} cubix_core)

# Build main executable
# todo: add compiler optimiztions?
add_executable(cubix main.cpp)
target_link_libraries(cubix PRIVATE cubix_core)

add_subdirectory(tests)
