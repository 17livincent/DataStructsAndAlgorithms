/**
 *  @file linkedlist.h
 *  @author Vincent Li
 *  Implementation of a linked list.
 */

#pragma once
#ifndef LINKEDLIST
#define LINKEDLIST

#include <cstddef>

template <typename T>
struct LLNode {
    LLNode(const T &v) : value{v}, next{NULL} {}
    T value;
    LLNode* next;
};

class LinkedList {
    public:
        /**
         *  Add the node @param n to the back of the linked list pointed to by @param head.
         */
        template <typename T>
        void addNode(LLNode<T>* head, LLNode<T>* n);

        /**
         *  Insert the node @param n into the @param index location.
         */
        template <typename T>
        void insertNode(LLNode<T>** head, LLNode<T>* n, int index);

        /**
         *  Delete the node at the @param index location.
         */
        template <typename T>
        void deleteNode(LLNode<T>** head, int index);

        /**
         *  Print the linked list pointed to by @param head.
         */
        template <typename T>
        void printLL(LLNode<T>* head);
};

#endif  // LINKEDLIST