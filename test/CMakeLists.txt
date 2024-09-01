file(GLOB_RECURSE distributed_kv_store_tests_SRC
    "*.cpp"
)

add_executable(distributed_kv_store_tests
    ${distributed_kv_store_tests_SRC}
)

target_link_libraries(distributed_kv_store_tests PRIVATE distributed_kv_store_lib)

add_test(NAME distributed_kv_store_tests COMMAND distributed_kv_store_tests)