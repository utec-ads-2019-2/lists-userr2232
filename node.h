#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : data(0), next(nullptr), prev(nullptr) {}
    Node(int data): data(data), next(nullptr), prev(nullptr) {}

    int killAllAfterThis() {
        int deleted = 0;
        if(this->next) deleted = 1 + this->next->killAllAfterThis();
        else deleted = 1;
        delete this;
        return deleted;
    }

    void killSelf() {
        delete this;
    }
};

#endif