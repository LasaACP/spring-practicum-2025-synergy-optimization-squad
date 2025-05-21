#pragma once

#include <cassert>
#include <cstddef>
#include <stdexcept>


template <typename T>
class LinkedList {
public:
    typedef size_t SizeType;
private:
    struct Element {
        T* value;
        Element* previous;
        Element* next;
    };

    Element* head;
    Element* tail;
    SizeType _size;
public:
    class LinkedListIterator {
        Element* current;
    public:
        explicit LinkedListIterator(LinkedList* list) {
            current = list->head;
        }

        ~LinkedListIterator() = default;

        T& get() {
            if (finished()) {
                throw std::out_of_range("Reached end of linked list.");
            }
            return *(current->value);
        }

        bool finished() {
            return current == nullptr;
        }

        void next() {
            current = current->next;
        }
    };
    friend LinkedListIterator;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        _size = 0;
    }

    ~LinkedList() {
        for (auto item = head; item != nullptr;) {
            auto next_item = item->next;
            delete item->value;
            delete item;
            item = next_item;
        }
    }

    void push_back(const T& item) {
        _push_back(new T(item));
    }

    void push_back(T&& item) {
        _push_back(new T(std::move(item)));
    }

    LinkedListIterator begin() {
        return LinkedListIterator(this);
    }

    [[nodiscard]] SizeType size() const {
        return _size;
    }

    void insert(LinkedList& list) {
        for (auto i = list.begin(); !i.finished(); i.next()) {
            push_back(i.get());
        }
    }

    bool contains(const T& item) {
        for (auto i = begin(); !i.finished(); i.next()) {
            if (i.get() == item) return true;
        }
        return false;
    }

    [[nodiscard]] bool empty() const {
        return _size == 0;
    }

    T& at(const SizeType idx) {
        if (idx > _size - 1) {
            throw std::out_of_range("Index out of range for linked list.");
        }

        int i = 0;
        for (auto val = begin(); !val.finished(); val.next()) {
            if (i == idx) return val.get();
            ++i;
        }

        assert(false);
    }

private:
    void _push_back(T* item) {
        auto node = new Element{.value = item, .previous = tail, .next = nullptr};

        // Update previous item's next pointer to point to the new node
        if (node->previous != nullptr) node->previous->next = node;

        // Update the head and tail
        if (head == nullptr) head = node;
        tail = node;

        // Increment the linked list's size
        ++_size;
    }
};
