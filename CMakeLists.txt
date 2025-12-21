cmake_minimum_required(VERSION 3.15)

project(SoftwareRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Fetch Eigen linear algebra library
FetchContent_Declare(
  Eigen
  GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
  GIT_TAG 3.4.0
)
FetchContent_MakeAvailable(Eigen)

file(GLOB_RECURSE LIB_SOURCES "${CMAKE_SOURCE_DIR}/lib/*.cpp")

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
# add_subdirectory(tests)
