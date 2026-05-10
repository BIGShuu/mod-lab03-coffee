cmake_minimum_required(VERSION 3.5)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.0
)
FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME}.test tests.cpp)

target_link_libraries(${PROJECT_NAME}.test
  automata_lib
  gtest
  gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}.test)
