/**
 * @file kv_store.tpp
 * @brief Implementation of the key-value store template
 */

template<typename KeyType, typename ValueType>
size_t KVStore<KeyType, ValueType>::hash(const KeyType& key) const {
    return std::hash<KeyType>{}(key) % capacity_;  // Calls the instantiated hash function object with given key as argument
}

template<typename KeyType, typename ValueType>
KVStore<KeyType, ValueType>::KVStore(size_t capacity) : capacity_(capacity), size_(0) {
    table_.resize(capacity_);
}

template<typename KeyType, typename ValueType>
void KVStore<KeyType, ValueType>::put(const KeyType& key, const ValueType& value) {
    size_t index = hash(key);
    while (table_[index].occupied && table_[index].key != key) {
        index = (index + 1) % capacity_;
    }
    table_[index] = {key, value, true};
    size_++;
}

template<typename KeyType, typename ValueType>
ValueType KVStore<KeyType, ValueType>::get(const KeyType& key) {
    size_t index = hash(key);
    while (table_[index].occupied) {
        if (table_[index].key == key) return table_[index].value;
        index = (index + 1) % capacity_;
    }
    throw std::runtime_error("Key not found");
}

template<typename KeyType, typename ValueType>
void KVStore<KeyType, ValueType>::del(const KeyType& key) {
    size_t index = hash(key);
    while (table_[index].occupied) {
        if (table_[index].key  == key) {
            table_[index].occupied = false;
            return;
        }
        index = (index + 1) % capacity_;
    }
}