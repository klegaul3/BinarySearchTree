/*
Kyler Legault
Cosc 2030
Program 2
10/1/2022

Definition and implementation of the Node class
*/

#ifndef NODE_H
#define NODE_H

template <typename T>
class BinaryNode
{
public:
    BinaryNode()
    {
        left = nullptr;
        right = nullptr;
    }
    BinaryNode(T item)
    {
        left = nullptr;
        right = nullptr;
        data = item;
    }
    ~BinaryNode() {}

    BinaryNode<T> *left;
    BinaryNode<T> *right;
    T data;
};

#endif