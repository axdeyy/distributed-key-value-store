file(GLOB_RECURSE distributed_kv_store_lib_SRC
    "*.cpp"
)

add_library(distributed_kv_store_lib
    ${distributed_kv_store_lib_SRC}
)

target_include_directories(distributed_kv_store_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})