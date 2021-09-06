/**
 *  @file binarytree.cpp
 *  @author Vincent Li
 *  Implementation of a binary tree.
 */

#include <cstdlib>
#include <cstddef>
#include <iostream>
#include <cassert>
#include <stack>
#include <queue>
#include "binarytree.h"

template <typename T>
void BinaryTree::inOrderTraversal(BTNode<T>* root) {
    // use a stack
    std::stack<BTNode<T>*> st;

    BTNode<T>* current = root;

    std::cout << "Tree: ";

    while(!st.empty() || current != NULL) {
        if(current != NULL) {   // if current exists, push to stack and move left
            st.push(current);
            current = current->left;
        }
        else {  // if not, go back up and move right
            current = st.top();
            st.pop();
            std::cout << current->value << " ";
            current = current->right;
        }
        
    }

    std::cout << std::endl;
}

template <typename T>
void BinaryTree::preOrderTraversal(BTNode<T>* root) {
    // use a stack
    std::stack<BTNode<T>*> st;

    BTNode<T>* current = root;
    st.push(current);

    std::cout << "Tree: ";

    while(!st.empty()) {
        // move the top of st1 to st2 and pop st1
        current = st.top();
        st.pop();
        std::cout << current->value << " ";

        // push the left and right children of current to st1, if either exist
        if(current->right != NULL) st.push(current->right);
        if(current->left != NULL) st.push(current->left);
        
    }

    std::cout << std::endl;
}

template <typename T>
void BinaryTree::postOrderTraversal(BTNode<T>* root) {
    // use two stacks
    std::stack<BTNode<T>*> st1;
    std::stack<BTNode<T>*> st2;

    BTNode<T>* current = root;
    st1.push(current);

    std::cout << "Tree: ";

    while(!st1.empty()) {
        // move the top of st1 to st2 and pop st1
        current = st1.top();
        st1.pop();
        st2.push(current);

        // push the left and right children of current to st1, if either exist
        if(current->left != NULL) st1.push(current->left);
        if(current->right != NULL) st1.push(current->right);
    }

    // print st2
    while(!st2.empty()) {
        std::cout << st2.top()->value << " ";
        st2.pop();
    }

    std::cout << std::endl;
}

template <typename T>
BTNode<char>* BinaryTree::depthFirstSearch(BTNode<T>* root, T target) {
    // use a stack
    std::stack<BTNode<T>*> st;

    BTNode<T>* current = root;
    st.push(current);

    while(!st.empty()) {
        // move the top of st1 to st2 and pop st1
        current = st.top();
        st.pop();

        if(current->value == target) {
            break;
        }

        // push the left and right children of current to st1, if either exist
        if(current->right != NULL) st.push(current->right);
        if(current->left != NULL) st.push(current->left);
    }

    return current;
}

template <typename T>
BTNode<char>* BinaryTree::breadthFirstSearch(BTNode<T>* root, T target) {
    // use a stack
    std::queue<BTNode<T>*> q;

    BTNode<T>* current = root;
    q.push(current);

    while(!q.empty()) {
        // move the top of st1 to st2 and pop st1
        current = q.front();
        q.pop();

        if(current->value == target) {
            break;
        }

        // push the left and right children of current to st1, if either exist
        if(current->left != NULL) q.push(current->left);
        if(current->right != NULL) q.push(current->right);
    }

    return current;
}

int main(int argc, char** argv) {
    BinaryTree BT;

    /*
           A
          / \
         B   C
        /   / \
        D   E  F
    */

    // create nodes
    BTNode<char> n0 = BTNode<char>('A');
    BTNode<char> n1 = BTNode<char>('B');
    BTNode<char> n2 = BTNode<char>('C');
    BTNode<char> n3 = BTNode<char>('D');
    BTNode<char> n4 = BTNode<char>('E');
    BTNode<char> n5 = BTNode<char>('F');

    // create tree
    n0.left = &n1; n0.right = &n2;  // A
    n1.left = &n3; n1.right = NULL; // B
    n2.left = &n4; n2.right = &n5;  // C

    // assign root
    BTNode<char>* root = &n0;

    // test traversals
    BT.inOrderTraversal(root);  // want to see: D B A E C F
    BT.postOrderTraversal(root);    // want to see: D B E F C A
    BT.preOrderTraversal(root); // want to see: A B D C E F

    // test DFS
    std::cout << "Found " << BT.depthFirstSearch(root, 'A')->value << std::endl;
    std::cout << "Found " << BT.depthFirstSearch(root, 'F')->value << std::endl;

    // test BFS
    std::cout << "Found " << BT.breadthFirstSearch(root, 'A')->value << std::endl;
    std::cout << "Found " << BT.breadthFirstSearch(root, 'F')->value << std::endl;

    return 0;
}