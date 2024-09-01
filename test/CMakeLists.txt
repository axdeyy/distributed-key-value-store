# Enable testing
enable_testing()

# Add the executable for testing
add_executable(kvstore_test test.cpp)

# Link any necessary libraries for testing
# e.g., target_link_libraries(kvstore_test some_test_lib)

# Define a test using CTest
add_test(NAME KVStoreTest COMMAND kvstore_test)
