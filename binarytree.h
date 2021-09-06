/**
 *  @file binarytree.h
 *  @author Vincent Li
 *  Implementation of a binary tree.
 */

#pragma once
#ifndef BINARYTREE
#define BINARYTREE

template <typename T>
struct BTNode {
    BTNode(const T &v) : value{v}, left{NULL}, right{NULL} {}
    T value;
    BTNode* left;
    BTNode* right;
};

class BinaryTree {
    public:
        /**
         *  Traverse and print the binary tree in order (left, root, right).
         */
        void inOrderTraversal(BTNode<char>* root);

        /**
         *  Traverse and print the binary tree pre order (root, left, right).
         */
        void preOrderTraversal(BTNode<char>* root);

        /**
         *  Traverse and print the binary tree post order (left, right, root).
         */
        void postOrderTraversal(BTNode<char>* root);

        /**
         *  Use depth-first search to find the first node with the target value.
         */
        BTNode<char>* depthFirstSearch(BTNode<char>* root, char target);

        /**
         *  Use breadth-first search to find the first node with the target value.
         */
        BTNode<char>* breadthFirstSearch(BTNode<char>* root, char target);
        
};


#endif  // BINARYTREE