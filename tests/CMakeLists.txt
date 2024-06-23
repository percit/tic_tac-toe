# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the test executable
add_executable(MyTests test.cpp)

# Link the test executable with Google Test
target_link_libraries(MyTests
    ${GTEST_LIBRARIES}
    tic_tac_toe_lib
)

# Include Google Benchmark via FetchContent
include(FetchContent)

FetchContent_Declare(
    googlebenchmark
    URL https://github.com/google/benchmark/archive/v1.6.1.tar.gz
)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON CACHE BOOL "Enable fetching Google Benchmark dependencies.")
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable testing components in Google Benchmark.")
set(BENCHMARK_USE_BUNDLED_GTEST OFF CACHE BOOL "Disable bundled Google Test in Google Benchmark.")

FetchContent_MakeAvailable(googlebenchmark)

# Add the benchmark executable
add_executable(MyBenchmarks benchmark.cpp)

# Link the benchmark executable with Google Benchmark and your library
target_link_libraries(MyBenchmarks
    ${GTEST_LIBRARIES}
    benchmark::benchmark
    tic_tac_toe_lib
)
