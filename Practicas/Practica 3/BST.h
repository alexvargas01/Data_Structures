#include <iostream>
#include "NodeT.h"

using namespace std;

#ifndef BST_h
#define BST_h

class BST{
    public:
        BST();
        ~BST();
        bool search(int data);
        void add(int data);


    private:
        NodeT *root;
};

BST::BST(){
    root = NULL;
}

bool BST::search(int data){
    NodeT *curr = root;
    while (curr != NULL){
        if (curr->getData() == data){
            return true;
        }
        curr = (curr->getData() > data) ? curr->getLeft():curr->getRight();
    }
    return false;
}

void BST::add(int data){
    NodeT *father = NULL;
    NodeT *curr = root;

    while (curr != NULL){
        father = curr;
        if (curr->getData() == data){
            return;
        }
        curr = (curr->getData() > data) ? curr->getLeft():curr->getRight();
    }

    if (father ==  NULL){
        root = new NodeT(data);
    } else {
        ( father->getData() > data ) ? father->setLeft(new NodeT(data)):father->setRight(new NodeT(data));
    }
}



#endif