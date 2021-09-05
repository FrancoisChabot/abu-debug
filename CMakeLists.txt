cmake_minimum_required(VERSION 3.16)
project(abu_debug)

enable_testing()

if (NOT TARGET GTest::gtest_main)
  include(FetchContent)

  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.11.0
  )

  FetchContent_MakeAvailable(googletest)
endif()

add_library(abu_debug 
  src/abu_debug.cpp
)

target_include_directories(abu_debug PUBLIC include)
target_compile_features(abu_debug PUBLIC cxx_std_20)

add_library(abu::debug ALIAS abu_debug)

add_subdirectory(tests)