#include <gtest/gtest.h>
#include "custom_hash_map.hpp"  // Replace with the actual header for your hash map

// Test fixture for setting up the hash map
class CustomHashMapTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Initialize your hash map here
        map = new CustomHashMap<int, std::string>(10);  // Adjust parameters as needed
    }

    void TearDown() override {
        delete map;
    }

    CustomHashMap<int, std::string>* map;
};

// Test case: Insert and retrieve a key-value pair
TEST_F(CustomHashMapTest, InsertAndRetrieve) {
    map->put(1, "value1");
    EXPECT_EQ(map->get(1), "value1");
}

TEST_F(CustomHashMapTest, InsertAndRetrieveMultiple) {
    map->put(1, "value1");
    map->put(2, "value2");
    map->put(3, "value3");
    EXPECT_EQ(map->get(1), "value1");
    EXPECT_EQ(map->get(2), "value2");
    EXPECT_EQ(map->get(3), "value3");
}

TEST_F(CustomHashMapTest, OverwriteValue) {
    map->put(1, "value1");
    map->put(1, "new_value1");
    EXPECT_EQ(map->get(1), "new_value1");
}

TEST_F(CustomHashMapTest, KeyNotFound) {
    // Expect a runtime error when trying to access a non-existent key
    EXPECT_THROW({
        try {
            map->get(999);  
        } catch (const std::runtime_error& e) {
            EXPECT_STREQ(e.what(), "Key not found"); 
            throw;
        }
    }, std::runtime_error);
}

TEST_F(CustomHashMapTest, DeleteKey) {
    map->put(1, "value1");
    map->del(1);
    EXPECT_THROW({
        try {
            map->get(999);  
        } catch (const std::runtime_error& e) {
            EXPECT_STREQ(e.what(), "Key not found"); 
            throw;
        }
    }, std::runtime_error);
}

TEST_F(CustomHashMapTest, EmptyMap) {
    EXPECT_THROW({
        try {
            map->get(999);  
        } catch (const std::runtime_error& e) {
            EXPECT_STREQ(e.what(), "Key not found"); 
            throw;
        }
    }, std::runtime_error);
}

TEST_F(CustomHashMapTest, DuplicateKeys) {
    map->put(1, "value1");
    map->put(1, "value1_again");
    EXPECT_EQ(map->get(1), "value1_again");
}

