#include <iostream>
using namespace std;

#ifndef NodeT_h
#define NodeT_h

class NodeT{
    public:
        //Constructor
        NodeT(int data);
        //Setters
        void setData(int data);
        void setLeft(NodeT *left);
        void setRight(NodeT *right);
        //Getters
        int getData();
        NodeT* getLeft();
        NodeT* getRight();
    private:
        int data;
        NodeT *left;
        NodeT *right;
};

//Constructor
NodeT::NodeT(int data){
    this->data = data;
    left = NULL;
    right = NULL;
}

//Setters
void NodeT::setData(int data){
    this->data = data;
}

void NodeT::setLeft(NodeT *left){
    this->left = left;
}

void NodeT::setRight(NodeT *right){
    this->right = right;
}

//Getters
int NodeT::getData(){
    return data;
}

NodeT* NodeT::getLeft(){
    return left;
}

NodeT* NodeT::getRight(){
    return right;
}

#endif