/**
 * @file kv_store.hpp
 * @brief Header file for the key-value store template
 */

#ifndef KV_STORE_HPP
#define KV_STORE_HPP

#include <vector>

/**
 * @class KVStore
 * @brief A custom hash map implementation using linear probing for collision resolution
 * 
 * We are using a template class to create a type-agnostic generic implementation to store key-value pairs
 */
template<typename KeyType, typename ValueType>
class KVStore {
private:
    /**
     * @struct HashEntry
     * @brief Represents an entry in the hash table
    */
    struct HashEntry {
        KeyType key;
        ValueType value;
        bool occupied = false;
    };

    /**
     * @brief Our custom hash function
     * @param key The key to be hashed
    */
    size_t hash(const KeyType& key) const;

    std::vector<HashEntry> table_; // Underlying storage "table" for hash map 
    size_t capacity_;              // Current capacity of the hash map
    size_t size_;                  // Current number of hash entries in the hash map

public:
    /**
     * @brief Constructs a KVStore with a given capacity
     * @param capacity Initiail capacity of the hashmap. Defaults to 128
    */
    KVStore(size_t capacity = 128);

    /**
     * @brief Inserts a key-value pair into the hash map.
     * @param key The key to be inserted.
     * @param value The value associated with the key.
     */
    void put(const KeyType& key, const ValueType& value);

    /**
     * @brief Retrieves the value associated with a key.
     * @param key The key for which to retrieve the value.
     * @return The value associated with the key.
     * @throw std::runtime_error if the key is not found in the hash map.
     */
    ValueType get(const KeyType& key);

    /**
     * @brief Removes a key-value pair from the hash map.
     * @param key The key to be removed.
     */
    void del(const KeyType& key);
};

#include "kv_store.tpp"

#endif // KV_STORE_HPP