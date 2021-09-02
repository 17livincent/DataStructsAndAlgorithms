/**
 *  @file linkedlist.cpp
 *  @author Vincent Li
 *  Implementation of a linked list.
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <cassert>
#include "linkedlist.h"

void LinkedList::addNode(LLNode<short>* head, LLNode<short>* n) {
    LLNode<short>* scan = head;
    
    // find the last node
    while(scan->next != NULL) {
        scan = scan->next;
    }

    // add to next
    scan->next = n;
}

void LinkedList::insertNode(LLNode<short>** head, LLNode<short>* n, int index) {
    LLNode<short>* scan = *head;
    int countIndex = 0;
    if(index == 0) {
        n->next = *head;
        *head = n;
    }
    else {
        while(scan->next != NULL && countIndex != index - 1) {  // stop at the last node or the one right before the desired index
            scan = scan->next;
            countIndex++;
        }
        // Make sure the wanted index is reached.
        // If not, then the wanted index is too large.
        assert(countIndex == index - 1);

        n->next = scan->next;   // n's next is scan's old next
        scan->next = n; // scan's next is n
    }
}

void LinkedList::deleteNode(LLNode<short>** head, int index) {
    LLNode<short>* scan = *head;
    int countIndex = 0;
    if(index == 0) {    // index is of head
        scan = *head;   
        *head = scan->next; // reassign head
        delete(scan);   // delete head
    }
    else {
        while(scan->next != NULL && countIndex != index - 1) {  // stop at the last node or the one right before the desired index
            scan = scan->next;
            countIndex++;
        }
        // Make sure the wanted index is reached.
        // If not, then the wanted index is too large.
        assert(countIndex == index - 1);

        LLNode<short>* toDelete = scan->next;    // mark to delete
        scan->next = scan->next->next;  // skip the one to delete
        delete(toDelete);
    }
}

void LinkedList::printLL(LLNode<short>* head) {
    LLNode<short>* node = head;
    std::cout << "List: ";
    while(node != NULL) {
        if(node->next == NULL) {
            std::cout << node->value;
        }
        else {
            std::cout << node->value << ", ";
        }
        node = node->next;
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    LinkedList ll;

    // create a node
    LLNode<short>* n0 = new LLNode<short>(0);

    // assign head
    std::cout << "Initialized linked list" << std::endl;
    LLNode<short>* head = n0;
    ll.printLL(head);

    // add a few
    std::cout << "Add nodes" << std::endl;
    LLNode<short>* n1 = new LLNode<short>(1);
    ll.addNode(head, n1);
    LLNode<short>* n2 = new LLNode<short>(2);
    ll.addNode(head, n2);
    LLNode<short>* n3 = new LLNode<short>(3);
    ll.addNode(head, n3);
    ll.printLL(head);

    // insert a few
    std::cout << "Insert nodes" << std::endl;
    LLNode<short>* n4 = new LLNode<short>(4);
    ll.insertNode(&head, n4, 0);    // insert at head
    LLNode<short>* n5 = new LLNode<short>(5);
    ll.insertNode(&head, n5, 2);    // insert in the middle
    LLNode<short>* n6 = new LLNode<short>(6);
    ll.insertNode(&head, n6, 6);
    ll.printLL(head);

    // delete all
    std::cout << "Delete nodes" << std::endl;
    ll.deleteNode(&head, 0);    // delete at head
    ll.printLL(head);
    ll.deleteNode(&head, 1);    // delete in the middle
    ll.printLL(head);
    ll.deleteNode(&head, 4);    // delete at end
    ll.printLL(head);
    ll.deleteNode(&head, 0);
    ll.deleteNode(&head, 0);
    ll.deleteNode(&head, 0);
    ll.deleteNode(&head, 0);
    ll.printLL(head);
    assert(head == NULL);

    return 0;
}