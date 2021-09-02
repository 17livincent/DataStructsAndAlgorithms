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
        void addNode(LLNode<short>* head, LLNode<short>* n);

        /**
         *  Insert the node @param n into the @param index location.
         */
        void insertNode(LLNode<short>** head, LLNode<short>* n, int index);

        /**
         *  Delete the node at the @param index location.
         */
        void deleteNode(LLNode<short>** head, int index);

        /**
         *  Print the linked list pointed to by @param head.
         */
        void printLL(LLNode<short>* head);
};

#endif  // LINKEDLIST