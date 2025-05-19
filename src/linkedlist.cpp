#include "linkedlist.h"
#include <cassert>
#include <stdexcept>

using namespace std;

template<typename T>
LinkedList<T>::LinkedListIterator::LinkedListIterator(LinkedList *list) {
    current = list->head;
}

template<typename T>
T &LinkedList<T>::LinkedListIterator::get() {
    if (finished()) {
        throw out_of_range("Reached end of linked list.");
    }
    return *current;
}

template<typename T>
void LinkedList<T>::LinkedListIterator::next() {
    current = current->next;
}


template<typename T>
bool LinkedList<T>::LinkedListIterator::finished() {
    return current == nullptr;
}

template<typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
    _size = 0;
}

template<typename T>
LinkedList<T>::~LinkedList() {
    for (auto item = head; item != nullptr;) {
        auto next_item = item->next;
        delete item;
        item = next_item;
    }
}

template<typename T>
void LinkedList<T>::push_back(const T &item) {
    auto node = new Element{.value = &item, .previous = tail, .next = nullptr};

    // Update previous item's next pointer to point to the new node
    if (node->previous != nullptr) node->previous->next = node;

    // Update the head and tail
    if (head == nullptr) head = node;
    tail = node;

    // Increment the linked list's size
    ++_size;
}

template<typename T>
typename LinkedList<T>::LinkedListIterator LinkedList<T>::begin() {
    return LinkedListIterator(this);
}

template<typename T>
typename LinkedList<T>::SizeType LinkedList<T>::size() const {
    return _size;
}

template<typename T>
void LinkedList<T>::insert(LinkedList& list) {
    for (auto i = list.begin(); !i.finished(); i.next()) {
        push_back(i.get());
    }
}

template<typename T>
bool LinkedList<T>::contains(const T &item) {
    for (auto i = begin(); !i.finished(); i.next()) {
        if (i.get() == item) return true;
    }
    return false;
}

template<typename T>
bool LinkedList<T>::empty() const {
    return _size == 0;
}

template<typename T>
T &LinkedList<T>::at(const SizeType idx) {
    if (idx > _size - 1) {
        throw out_of_range("Index out of range for linked list.");
    }

    int i = 0;
    for (auto val = begin(); !val.finished(); val.next()) {
        if (i == idx) return val.get();
        ++i;
    }

    assert(false);
}
