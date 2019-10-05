#include <iostream>
#include "stack"
#include "NodeT.h"

using namespace std;

#ifndef BST_h
#define BST_h

class BST
{
public:
    BST();
    ~BST();
    bool search(int data);
    void add(int data);
    void remove(int data);
    void print(int x);
    void printLeaves();
    int count();

private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);
    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void libera(NodeT *r);
};

BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    libera(root);
}

void BST::libera(NodeT *r)
{
    if (r != NULL)
    {
        libera(r->getLeft());
        libera(r->getRight());
        delete r;
    }
}

bool BST::search(int data)
{
    NodeT *curr = root;
    while (curr != NULL)
    {
        if (curr->getData() == data)
        {
            return true;
        }
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    return false;
}

void BST::add(int data)
{
    NodeT *father = NULL;
    NodeT *curr = root;

    while (curr != NULL)
    {
        father = curr;
        if (curr->getData() == data)
        {
            return;
        }
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    if (father == NULL)
    {
        root = new NodeT(data);
    }
    else
    {
        (father->getData() > data) ? father->setLeft(new NodeT(data)) : father->setRight(new NodeT(data));
    }
}

int BST::howManyChildren(NodeT *r)
{
    int cont = 0;
    if (r->getLeft() != NULL)
    {
        cont++;
    }
    if (r->getRight() != NULL)
    {
        cont++;
    }
    return cont++;
}

int BST::pred(NodeT *r)
{
    NodeT *curr = r->getLeft();
    while (curr->getRight() != NULL)
    {
        curr = curr->getRight();
    }
    return curr->getData();
}

int BST::succ(NodeT *r)
{
    NodeT *curr = r->getRight();
    while (curr->getLeft() != NULL)
    {
        curr = curr->getLeft();
    }
    return curr->getData();
}

void BST::remove(int data)
{
    NodeT *curr = root;
    NodeT *father = NULL;

    while (curr != NULL && curr->getData() != data)
    {
        father = curr;
        curr = (curr->getData() > data ? curr->getLeft() : curr->getRight());
    }
    if (curr == NULL)
    {
        return;
    }

    int c = howManyChildren(curr);
    switch (c)
    {
    case 0:
        if (father == NULL)
        {
            root = NULL;
        }
        else
        {
            if (father->getData() > data)
            {
                father->setLeft(NULL);
            }
            else
            {
                father->setRight(NULL);
            }
        }
        delete curr;
        break;

    case 1:
        if (father == NULL)
        {
            if (curr->getLeft() != NULL)
            {
                root = curr->getLeft();
            }
            else
            {
                root = curr->getRight();
            }
        }
        else
        {
            if (father->getData() > data)
            {
                if (curr->getLeft() != NULL)
                {
                    father->setLeft(curr->getLeft());
                }
                else
                {
                    father->setLeft(curr->getRight());
                }
            }
            else
            {
                if (curr->getLeft() != NULL)
                {
                    father->setRight(curr->getLeft());
                }
                else
                {
                    father->setRight(curr->getRight());
                }
            }
        }
        delete curr;
        break;

    case 2:
        int x = succ(curr);
        remove(x);
        curr->setData(x);
        break;
    }
}

void BST::preOrder(NodeT *r)
{
    if (r != NULL)
    {
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r)
{
    if (r != NULL)
    {
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r)
{
    if (r != NULL)
    {
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::print(int x)
{
    switch (x)
    {
    case 1:
        preOrder(root);
        break;
    case 2:
        inOrder(root);
        break;
    case 3:
        postOrder(root);
        break;
    }
    cout << endl;
}

void BST::printLeaves()
{
    // if the tree is empty
    if (root == NULL)
    {
        return;
    }
    stack<NodeT *> s;
    NodeT *temp = root;
    while (temp != NULL || s.empty() == false)
    {
        //Reach left most node
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->getLeft();
        }
        //temp is NULL
        temp = s.top();
        s.pop();
        //print the leave
        if (temp != NULL && temp->getRight() == NULL && temp->getLeft() == NULL)
        {
            cout << temp->getData() << " ";
        }
        temp = temp->getRight();
    }
    cout << endl;
}

int BST::count(){
    if (root == NULL) return 0;

    int iCount = 0;
    stack<NodeT *> s;
    NodeT *temp = root;

    while (temp!=NULL || s.empty()==false){
        while (temp!=NULL){
            s.push(temp);
            temp = temp->getLeft();
        }
        temp=s.top();
        s.pop();
        iCount++;
        temp=temp->getRight();
    }
    return iCount;
}

#endif