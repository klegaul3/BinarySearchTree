
#ifndef BST_H
#define BST_H

#include <iostream>
#include "BinaryNode.h"

template <typename T>
class BST
{
public:
    BST();
    ~BST();

    void remove(T item);
    void insert(T item);
    BinaryNode<T> *find(T item, long &checks);

    void preorderTraversal();
    void inorderTraversal();
    void postorderTraversal();

    int getNumberOfNodes();
    int getHeight();
    int getMinHeight();
    bool isEmpty();

private:
    void remove(T item, BinaryNode<T> *t);
    void insert(T item, BinaryNode<T> *&t);
    BinaryNode<T> *find(T item, BinaryNode<T> *t, long &checks);
    BinaryNode<T> *findMin(BinaryNode<T> *t);
    BinaryNode<T> *findMax(BinaryNode<T> *t);
    void preorderTraversal(BinaryNode<T> *t);
    void inorderTraversal(BinaryNode<T> *t);
    void postorderTraversal(BinaryNode<T> *t);
    

    BinaryNode<T> *root;
    int numberOfNodes;
    int height;
    int minHeight;
};

// definitions

//Constructor and Destructor
template <typename T>
BST<T>::BST() {
    root = nullptr;
    numberOfNodes = 0;
    height = 0;
    minHeight = 0;
}

template <typename T>
BST<T>::~BST() {
}

// Public Methods
template <typename T>
void BST<T>::remove(T item)
{
    remove(item, root);
}

template <typename T>
void BST<T>::insert(T item)
{
    insert(item, root);
}

template <typename T>
BinaryNode<T> *BST<T>::find(T item, long &checks)
{
    return find(item, root, checks);
}

template <typename T>
int BST<T>::getNumberOfNodes() {
    return numberOfNodes;
}

template <typename T>
int BST<T>::getHeight() {
    return height;
}

template <typename T>
int BST<T>::getMinHeight() {
    return minHeight;
}

template <typename T>
void BST<T>::preorderTraversal() {
    preorderTraversal(root);
}

template <typename T>
void BST<T>::inorderTraversal() {
    inorderTraversal(root);
}

template <typename T>
void BST<T>::postorderTraversal() {
    postorderTraversal(root);
}

template <typename T>
bool BST<T>::isEmpty() {
    return numberOfNodes == 0;
}

// Private Methods
template <typename T>
void BST<T>::remove(T item, BinaryNode<T> *t)
{
    if (t == nullptr)
        return;

    if (item.compare(t->data) < 0)
    {
        remove(item, t->left);
    }
    else if (item.compare(t->data) > 0)
    {
        remove(item, t->right);
    }
    else
    {
        BinaryNode<T> *oldNode;
        if (t->left == nullptr)
        {
            oldNode = t;
            t = t->right;
            delete oldNode;
            return;
        }
        else if (t->right == nullptr)
        {
            oldNode = t;
            t = t->left;
            delete oldNode;
            return;
        }

        oldNode = findMin(t->right);
        t->data = oldNode->data;
        remove(t->data, t->right);
    }
}

template <typename T>
void BST<T>::insert(T item, BinaryNode<T> *&t)
{
    if (t == nullptr) {
        t = new BinaryNode<T>(item);
        numberOfNodes++;
    } else if (item.compare(t->data) < 0) {
        insert(item, t->left);
    } else if (item.compare(t->data) > 0) {
        insert(item, t->right);
    }
}

template <typename T>
BinaryNode<T> *BST<T>::find(T item, BinaryNode<T> *t, long &checks)
{
    if (t == nullptr) {
        return nullptr;
    } else if (item.compare(t->data) < 0) {
        checks ++;
        return find(item, t->left, checks);
    } else if (item.compare(t->data) > 0) {
        checks += 2;
        return find(item, t->right, checks);
    } else {
        checks += 2;
        return t;
    }
}

template <typename T>
BinaryNode<T> *BST<T>::findMin(BinaryNode<T> *t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename T>
BinaryNode<T> *BST<T>::findMax(BinaryNode<T> *t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    return findMin(t->right);
}

template <typename T>
void BST<T>::preorderTraversal(BinaryNode<T> *t) {
    if (t == nullptr) {
        return;
    } else {
        std::cout << t->data << std::endl;
        preorderTraversal(t->left);
        preorderTraversal(t->right);
    }
}

template <typename T>
void BST<T>::inorderTraversal(BinaryNode<T> *t) {
    if (t == nullptr) {
        return;
    } else {
        inorderTraversal(t->left);
        std::cout << t->data << std::endl;
        inorderTraversal(t->right);
    }
}

template <typename T>
void BST<T>::postorderTraversal(BinaryNode<T> *t) {
    if (t == nullptr) {
        return;
    } else {
        postorderTraversal(t->left);
        postorderTraversal(t->right);
        std::cout << t->data << std::endl;
    }
}

#endif