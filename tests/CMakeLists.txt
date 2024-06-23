# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Add the test executable
add_executable(MyTests test.cpp)

# Link the test executable with Google Test
target_link_libraries(MyTests
    ${GTEST_LIBRARIES}
    pthread)