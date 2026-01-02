cmake_minimum_required(VERSION 3.15)

# Silences the "DOWNLOAD_EXTRACT_TIMESTAMP" warning
cmake_policy(SET CMP0135 NEW)

# Silences the Eigen deprecation warning about CMake versions.
# This tells CMake to ignore the fact that Eigen asks for an old version.
set(CMAKE_POLICY_DEFAULT_CMP0000 OLD) 

project(SoftwareRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Enable export of compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Fetch Eigen linear algebra library
set(EIGEN_BUILD_PKGCONFIG OFF CACHE BOOL "" FORCE)
set(EIGEN_BUILD_TESTING OFF CACHE BOOL "" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
  Eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.4.0
)
FetchContent_MakeAvailable(Eigen)

file(GLOB_RECURSE LIB_SOURCES 
  "${CMAKE_SOURCE_DIR}/lib/*.cpp"
  "${CMAKE_SOURCE_DIR}/lib/*.cc"
)

if(LIB_SOURCES)
  add_library(${PROJECT_NAME}_lib ${LIB_SOURCES})
  target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_SOURCE_DIR}/include)
  # Eigen is header-only, so we just need to include its directory
  target_include_directories(${PROJECT_NAME}_lib PUBLIC ${eigen_SOURCE_DIR})
endif()

# Fetch googletest for testing
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
# This downloads and makes the "gtest_main" target available to use
FetchContent_MakeAvailable(googletest)

enable_testing()
add_subdirectory(tests)
