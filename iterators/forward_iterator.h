#ifndef FORWARD_ITERATOR_H
#define FORWARD_ITERATOR_H

#include "../iterator.h"
#include <stdexcept>

template <typename T> 
class ForwardIterator : public Iterator<T> {
    public:
        ForwardIterator() : Iterator<T>() {};
        ForwardIterator(Node<T> *node) : Iterator<T>(node) {};

        ForwardIterator<T> operator=(ForwardIterator<T> other) {
            this->current = other.current;
            return *this;
        }

        bool operator!=(ForwardIterator<T> other) {
            return this->current != other.current;
        }

        ForwardIterator<T> operator++() {
            if(!this->current) {
                throw runtime_error(string("nullptr does not have next element."));
            } else {
                this->current = this->current->next;
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