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
struct Node {
    Node(const T &v) : value{v}, next{NULL} {}
    T value;
    Node* next;
};

class LinkedList {
    public:
        /**
         *  Add the node @param n to the back of the linked list pointed to by @param head.
         */
        void addNode(Node<short>* head, Node<short>* n);

        /**
         *  Insert the node @param n into the @param index location.
         */
        void insertNode(Node<short>** head, Node<short>* n, int index);

        /**
         *  Delete the node at the @param index location.
         */
        void deleteNode(Node<short>** head, int index);

        /**
         *  Print the linked list pointed to by @param head.
         */
        void printLL(Node<short>* head);
};

#endif  // LINKEDLIST