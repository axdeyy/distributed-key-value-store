#include <vector>

/**
 * @class CustomHashMap
 * @brief A custom hash map implementation using linear probing for collision resolution
 * 
 * We are using a template class to create a type-agnostic generic implementation to store key-value pairs
 */
template <typename KeyType, typename ValueType>
class CustomHashMap {
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

    size_t hash(const KeyType& key) const {
        return std::hash<KeyType>{}(key) % capacity_;  // Calls the instantiated hash function object with given key as argument
    }

    std::vector<HashEntry> table_; // Underlying storage "table" for hash map 
    size_t capacity_;              // Current capacity of the hash map
    size_t size_;                  // Current number of hash entries in the hash map

public:
    /**
     * @brief Constructs a CustomHashMap with a given capacity
     * @param capacity Initiail capacity of the hashmap. Defaults to 128
    */
    CustomHashMap(size_t capacity = 128) : capacity_(capacity), size_(0) {
        table_.resize(capacity_);
    }

    /**
     * @brief Inserts a key-value pair into the hash map.
     * @param key The key to be inserted.
     * @param value The value associated with the key.
     */
    void put(const KeyType& key, const ValueType& value) {
        size_t index = hash(key);
        while (table_[index].occupied && table_[index].key != key) {
            index = (index + 1) % capacity_;
        }
        table_[index] = {key, value, true};
        size_++;
    }

    /**
     * @brief Retrieves the value associated with a key.
     * @param key The key for which to retrieve the value.
     * @return The value associated with the key.
     * @throw std::runtime_error if the key is not found in the hash map.
     */
    ValueType get(const KeyType& key) {
        size_t index = hash(key);
        while (table_[index].occupied) {
            if (table_[index].key == key) return table_[index].value;
            index = (index + 1) % capacity_;
        }
        throw std::runtime_error("Key not found");
    }

    /**
     * @brief Removes a key-value pair from the hash map.
     * @param key The key to be removed.
     */
    void del(const KeyType& key) {
        size_t index = hash(key);
        while (table_[index].occupied) {
            if (table_[index].key  == key) {
                table_[index].occupied = false;
                return;
            }
            index = (index + 1) % capacity_;
        }
    }
};