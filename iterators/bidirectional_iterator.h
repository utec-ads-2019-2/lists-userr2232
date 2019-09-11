#ifndef BIDIRECTIONAL_ITERATOR_H
#define BIDIRECTIONAL_ITERATOR_H

#include "../iterator.h"

template <typename T> 
class BidirectionalIterator : public Iterator<T> {
    public:
        BidirectionalIterator() : Iterator<T>() {};
        BidirectionalIterator(Node<T> *node) : Iterator<T>(node) {};

        BidirectionalIterator<T> operator=(BidirectionalIterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(BidirectionalIterator<T> other) {
            return this->current != other.current;
        }

        BidirectionalIterator<T> operator++() {
            if(!this->current) {
                throw runtime_error(string("nullptr does not have next element"));
            } else {
                this->current = this->current->next;
                return *this;
            }
        }

        BidirectionalIterator<T> operator--() {
            if(!this->current) {
                throw runtime_error(string("nullptr does not have previous element"));
            } else {
                this->current = this->current->prev;
                return *this;
            }
        }

        T operator*() {
            if(!this->current) {
                throw runtime_error(string("Trying to access an invalid address"));
            } else {
                return this->current->data;
            }
        }
};

#endif