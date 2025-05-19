#pragma once

#include <cstddef>

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
        explicit LinkedListIterator(LinkedList* list);
        ~LinkedListIterator() = default;

        T& get();
        bool finished();
        void next();
    };
    friend LinkedListIterator;

    LinkedList();
    ~LinkedList();

    void push_back(const T &item);
    LinkedListIterator begin();
    [[nodiscard]] SizeType size() const;
    void insert(LinkedList& list);
    bool contains(const T& item);
    [[nodiscard]] bool empty() const;
    T& at(SizeType idx);
};
