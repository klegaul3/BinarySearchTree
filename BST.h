
#ifndef BST_H
#define BST_H

#include "BinaryNode.h"

template <typename T>
class BST
{
public:
    BST();
    ~BST();

    void remove(T item);
    void insert(T item);
    BinaryNode<T> *find(T item);
    BinaryNode<T> *findMin(BinaryNode<T> *t);
    BinaryNode<T> *findMax(BinaryNode<T> *t);

    int getNumberOfNodes();
    int getHeight();
    int getMinHeight();

private:
    void remove(T item, BinaryNode<T> *t);
    void insert(T item, BinaryNode<T> *&t);
    BinaryNode<T> *find(T item, BinaryNode<T> *t);

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
BinaryNode<T> *BST<T>::find(T item)
{
    find(item, root);
}

template <typename T>
BinaryNode<T> *findMin(BinaryNode<T> *t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->left == nullptr)
        return t;
    return findMin(t->left);
}

template <typename T>
BinaryNode<T> *findMax(BinaryNode<T> *t)
{
    if (t == nullptr)
        return nullptr;
    else if (t->right == nullptr)
        return t;
    return findMin(t->right);
}

// Private Methods
template <typename T>
void BST<T>::remove(T item, BinaryNode<T> *t)
{
    if (t == nullptr)
        return;

    if (item < t->data)
    {
        remove(item, t->left);
    }
    else if (item > t->data)
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
void insert(T item, BinaryNode<T> *&t)
{
    if (t == nullptr) {
        t = new BinaryNode<T>(item);
    } else if (item < t->data) {
        insert(item, t->left);
    } else if (item > t->data) {
        insert(item, t->right);
    }
}

template <typename T>
BinaryNode<T> *find(T item, BinaryNode<T> *t)
{
    if (t == nullptr) {
        return nullptr;
    } else if (item < t->data) {
        return find(item, t->left);
    } else if (item > t->data) {
        return find(item t->right);
    } else {
        return t;
    }
}

#endif