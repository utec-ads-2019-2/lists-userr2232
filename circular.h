#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            // TODO
        }

        T back() {
            // TODO
        }

        void push_front(T value) {
            // TODO
        }

        void push_back(T value) {
            // TODO
        }

        void pop_front() {
            // TODO
        }

        void pop_back() {
            // TODO
        }

        T operator[](int index) {
            // TODO
        }

        bool empty() {
            // TODO
        }

        int size() {
            // TODO
        }

        void clear() {
            // TODO
        }

        void sort() {
            // TODO
        }
    
        void reverse() {
            // TODO
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            // TODO
        }

	    BidirectionalIterator<T> end() {
            // TODO
        }

        void merge(CircularLinkedList<T> list) {
            // TODO
        }
};

#endif