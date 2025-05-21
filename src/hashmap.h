#pragma once

// ReSharper disable once CppUnusedIncludeDirective
#include <cstddef>
#include <stdexcept>
#include <string>
#include "linkedlist.h"

#include <iostream>

constexpr size_t BUCKET_COUNT = 100;

template <typename V>
class StringHashMap {
public:
    typedef size_t SizeType;

    struct KeyValuePair {
        std::string key;
        V* value;
    };
private:
    LinkedList<KeyValuePair*> buckets[BUCKET_COUNT];

    // This is bad because we're essentially duplicating the data, but I have done this for the sake of simplicity
    // (not introducing a separate "iterator" subclass) and in the interest of reducing coding/debugging time and
    // complexity.
    LinkedList<KeyValuePair*> all_pairs;
public:
    StringHashMap() = default;
    ~StringHashMap() {
        for (auto & bucket : buckets) {
        }
    }

    [[nodiscard]] static SizeType hash(const std::string& s) {
        SizeType total = 0;
        for (auto c : s) ++total;
        return total % BUCKET_COUNT;
    }

    void set(const std::string& key, const V& value) {
        _set(key, new V(value));
    }

    void set(const std::string& key, V&& value) {
        _set(key, new V(std::move(value)));
    }

    V& get(const std::string& key) {
        SizeType index = hash(key);
        auto& bucket = buckets[index];

        for (auto i = bucket.begin(); !i.finished(); i.next()) {
            if (i.get()->key == key) {
                return *(i.get()->value);
            }
        }

        throw std::out_of_range("Key '" + key + "' does not exist in current hashmap.");
    }

    typename LinkedList<KeyValuePair*>::LinkedListIterator begin() {
        return all_pairs.begin();
    }

private:
    void _set(const std::string& key, V* value) {
        SizeType index = hash(key);
        auto& bucket = buckets[index];

        // Check if the item already exists
        for (auto i = bucket.begin(); !i.finished(); i.next()) {
            if (i.get()->key == key) {
                i.get()->value = value;
                return;
            }
        }

        auto new_pair = new KeyValuePair{.key = key, .value = value};
        bucket.push_back(new_pair);
        all_pairs.push_back(new_pair);
    }
};
