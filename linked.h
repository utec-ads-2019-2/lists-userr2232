#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}
        ~LinkedList() { }

        T front() {
            if(!this->head) {
                throw runtime_error(string("This list does not have any nodes."));
            } else {
                return this->head->data;
            }
        }

        T back() {
            if(!this->head) {
                throw runtime_error(string("This list does not have any nodes."));
            } else {
                return this->tail->data;
            }
        }

        void push_front(T value) {
            Node<T>* n = new Node<T>(value);
            if(this->head) {
                n->next = this->head;
                this->head->prev = n;
            } else {
                this->tail = n;
            }
            this->head = n;
            this->nodes++;
        }

        void push_back(T value) {
            Node<T> *n = new Node<T>(value);
            if(!this->head) {
                this->head = n;
            } else {
                n->prev = this->tail;
                this->tail->next = n;
            }
            this->tail = n;
            this->nodes++;
        }

        void pop_front() {
            if(this->head) {
                Node<T>* tmp = this->head;
                this->head = this->head->next;
                tmp->killSelf();
                tmp = nullptr;
                this->nodes--;
            }
        }

        void pop_back() {
            Node<T>* tmp = this->head;
            while(tmp && tmp->next && tmp->next->next)
                tmp = tmp->next;
            if(tmp && tmp->next) {
                tmp->next->killSelf();
                tmp->next = nullptr;
            }
            this->tail = tmp;
            this->nodes--;
        }

        T operator[](int index) {
            if(index >= this->nodes) {
                throw runtime_error(string("Index out of bounds."));
            } else {
                Node<T>* current = this->head;
                while(index--)
                    current = current->next;
                return current->data;
            }
        }

        bool empty() {
            return this->nodes == 0;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            this->tail = nullptr;
            this->nodes -= this->head->killAllAfterThis();
            this->head = nullptr;
        }

        void sort() {
            Node<T> *current = this->head;
            T* aux = new T[this->nodes];
            for(int i = 0; i < this->nodes; ++i) {
                aux[i] = current->data;
                current = current->next;
            }
            std::sort(aux, aux + this->nodes);
            current = this->head;
            for(int i = 0; i < this->nodes; ++i) {
                current->data = aux[i];
                current = current->next;
            }
            delete [] aux;
        }
    
        void reverse() {
            reverse(this->head);
        }

        void reverse(Node<T>* current) {
            if(!current) return;
            if(!current->next) {
                this->head = current;
                return;
            }
            reverse(current->next);
            this->tail->prev = this->tail->next;
            this->tail->next = current;
            this->tail = current;
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            if(this->tail)
                return BidirectionalIterator<T>(this->tail->next);
            else
                return BidirectionalIterator<T>(this->head);
        }

        void merge(LinkedList<T> list) {
            if(list.empty()) return;
            if(!this->size()) {
                this->head = list.head;
            } else {
                this->tail->next = list.head;
            }
            this->tail = list.tail;
            this->head->prev = this->tail;
            this->nodes += list.size();
        }
};

#endif