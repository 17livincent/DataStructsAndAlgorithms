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
        template <typename T>
        void inOrderTraversal(BTNode<T>* root);

        /**
         *  Traverse and print the binary tree pre order (root, left, right).
         */
        template <typename T>
        void preOrderTraversal(BTNode<T>* root);

        /**
         *  Traverse and print the binary tree post order (left, right, root).
         */
        template <typename T>
        void postOrderTraversal(BTNode<T>* root);

        /**
         *  Use depth-first search to find the first node with the target value.
         */
        template <typename T>
        BTNode<char>* depthFirstSearch(BTNode<T>* root, T target);

        /**
         *  Use breadth-first search to find the first node with the target value.
         */
        template <typename T>
        BTNode<char>* breadthFirstSearch(BTNode<T>* root, T target);
        
};


#endif  // BINARYTREE