//
// Created by thelo on 026 26 feb. 2021.
//

#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H

#include <iostream>
using namespace std;

template <class T>
class Node{
public:
    T *data;
    Node<T> *nxt;

    Node(){
        data = nullptr;
        nxt = nullptr;
    }
    Node(T *data){
        this->data = data;
        nxt = nullptr;
    }
};

template <class T>
class SimpleList{
public:
    Node<T> *first;
    Node<T> *last;

    SimpleList<T>() {
        first = nullptr;
        last = nullptr;
    }

    void append(T *data){
        if (data != nullptr) {
            Node<T> node = new Node<T>(data);
            if (first == nullptr) {
                first = node;
                last = node;
            } else {
                last->nxt = node;
                last = node;
            }
        }
    }

    T* erraseFirst(){
        if (first != nullptr) {
            Node<T> *ptrDeleted = first;
            first = first->nxt;
            first->nxt = nullptr;
            return ptrDeleted;
        } else
            return nullptr;
    }

    T* erraseLast(){
        if (first != nullptr) {
            if (first == last)
                return erraseFirst();
            Node<T> *ptr = first;
            while (ptr->nxt->nxt != nullptr)
                ptr = ptr->nxt;
            Node<T> *ptrDeleted = ptr->nxt;
            ptr->nxt = nullptr;
            last = ptr;
            return ptrDeleted;
        } else
            return nullptr;

    }
};

template <class T>
class Queue : public SimpleList<T> {
public:
    Queue() {
        this->first = nullptr;
        this->last = nullptr;
    }

    T* pop(){
        return this->erraseFirst();
    }
};

template <class T>
class Stack : public SimpleList<T> {
public:
    Stack() {
        this->first = nullptr;
        this->last = nullptr;
    }

    T* pop(){
        return this->erraseLast();
    }
};

#endif //LISTA_LISTA_H
