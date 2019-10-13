#include <iostream>
#include "stack"
#include "queue"
#include "NodeT.h"
#include <algorithm>

using namespace std;

#ifndef BST_h
#define BST_h

class BST
{
public:
    //clase
    BST();
    ~BST();
    bool search(int data);
    void add(int data);
    void remove(int data);
    void print(int x);
    void printLeaves();
    //T escrita
    void printLeavesCHR();
    int count();
    //T 07
    int height();
    vector<int> ancestors(int data);
    int whatLevelamI(int data);
    //T 08
    int maxWidth();
    int nearstRelative(int n1, int n2);
    BST(const BST &copy);
    bool operator==(const BST &ABB); 
    queue<int> toQueue();            

private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT *r);
    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void libera(NodeT *r);
    void printLeaves(NodeT *r);
    //T 07
    void levelxlevel();
    //T 08 Helpers
    int maxWidthHelper(NodeT *r);
    void operatorHelper(NodeT *r1, NodeT *r2, bool &bVal);
    void addNodes(NodeT *r1, NodeT *r2);
    void toQueueHelper(NodeT *r, queue<int> &q);
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

void BST::printLeaves(NodeT *r)
{
    if (r != NULL)
    {
        if (r->getLeft() == NULL && r->getRight() == NULL)
        {
            cout << r->getData() << " ";
        }
        else
        {
            printLeaves(r->getLeft());
            printLeaves(r->getRight());
        }
    }
}

//T 07
void BST::levelxlevel()
{
    if (root == NULL)
        return;

    queue<NodeT *> q;
    q.push(root);
    while (!q.empty())
    {
        NodeT *temp = q.front();
        cout << temp->getData() << " ";
        q.pop();

        if (temp->getLeft() != NULL)
        {
            q.push(temp->getLeft());
        }
        if (temp->getRight() != NULL)
        {
            q.push(temp->getRight());
        }
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
    case 4:
        printLeaves(root);
        break;
    case 5:
        levelxlevel();
        break;
    }
    cout << endl;
}

//T Escrita
void BST::printLeavesCHR()
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

int BST::count()
{
    if (root == NULL)
        return 0;

    int iCount = 0;
    stack<NodeT *> s;
    NodeT *temp = root;

    while (temp != NULL || s.empty() == false)
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->getLeft();
        }
        temp = s.top();
        s.pop();
        iCount++;
        temp = temp->getRight();
    }
    return iCount;
}

//T 07
int BST::height()
{
    if (root == NULL)
        return 0;

    queue<NodeT *> q;
    q.push(root);
    int iCount = 0;

    while (!q.empty())
    {
        int size = q.size();
        while (size > 0)
        {
            NodeT *temp = q.front();
            q.pop();

            if (temp->getLeft() != NULL)
            {
                q.push(temp->getLeft());
            }

            if (temp->getRight() != NULL)
            {
                q.push(temp->getRight());
            }
            size--;
        }
        iCount++;
    }
    return iCount;
}

vector<int> BST::ancestors(int data)
{
    NodeT *curr = root;
    stack<int> s;
    vector<int> ancestors;

    while (curr != NULL)
    {

        if (curr->getData() == data)
        {
            break;
        }
        s.push(curr->getData());
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }

    while (!s.empty())
    {
        int value = s.top();
        ancestors.push_back(value);
        s.pop();
    }
    return ancestors;
}

int BST::whatLevelamI(int data)
{
    NodeT *curr = root;
    int height = 0;
    while (curr != NULL)
    {
        height++;
        if (curr->getData() == data)
        {
            return height;
        }
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    return -1;
}

//T 08
//Max Width of a level
int BST::maxWidth()
{
    return maxWidthHelper(root);
}

int BST::maxWidthHelper(NodeT *r)
{
    if (root == NULL)
        return 0;

    int iR = 0;

    queue<NodeT *> q;
    q.push(root);
    while (!q.empty())
    {
        int iCount = q.size();

        if (iR < iCount)
        {
            iR = iCount;
        }

        while (iCount--)
        {
            NodeT *curr = q.front();
            q.pop();
            if (curr->getLeft() != NULL)
            {
                q.push(curr->getLeft());
            }
            if (curr->getRight() != NULL)
            {
                q.push(curr->getRight());
            }
        }
    }
    return iR;
}

//Nearest relative between two nodes
int BST::nearstRelative(int n1, int n2)
{
    NodeT *curr = root;
    int iMax, iMin;

    if (n1 > n2)
    {
        iMax = n1;
        iMin = n2;
    }
    else
    {
        iMax = n2;
        iMin = n1;
    }

    if (iMax == iMin)
    {
        return iMax;
    }

    if (iMin < curr->getData() && iMax > curr->getData())
    {
        return curr->getData();
    }

    while (iMax < curr->getData() && iMin < curr->getData())
    {
        curr = curr->getLeft();
    }

    while (iMax > curr->getData() && iMin > curr->getData())
    {
        curr = curr->getRight();
    }

    return curr->getData();
}

//Copy constructor
BST::BST(const BST &copy)
{
    NodeT *curr2 = copy.root;

    if (curr2 == NULL)
    {
        root = NULL;
    }
    else
    {
        root = new NodeT(curr2->getData());
        NodeT *curr1 = root;
        addNodes(curr1, curr2);
    }
}

void BST::addNodes(NodeT *r1, NodeT *r2)
{
    if (r2 == NULL)
    {
        return;
    }

    if (r2->getLeft() != NULL && r2->getRight() != NULL)
    {
        r1->setLeft(new NodeT(r2->getLeft()->getData()));
        r1->setRight(new NodeT(r2->getRight()->getData()));

        addNodes(r1->getLeft(), r2->getLeft());
        addNodes(r1->getRight(), r2->getRight());
    }

    else if (r2->getLeft() != NULL && r2->getRight() == NULL)
    {
        r1->setLeft(new NodeT(r2->getLeft()->getData()));
        addNodes(r1->getLeft(), r2->getLeft());
    }

    else if (r2->getLeft() == NULL && r2->getRight() != NULL)
    {
        r1->setRight(new NodeT(r2->getRight()->getData()));
        addNodes(r1->getRight(), r2->getRight());
    }
}

//Operator ==
bool BST::operator==(const BST &ABB)
{
    NodeT *curr1 = root;
    NodeT *curr2 = ABB.root;
    bool bVal = true;

    if (curr1 == NULL && curr2 == NULL)
    {
        return true;
    }
    else
    {
        operatorHelper(curr1, curr2, bVal);
        return bVal;
    }
}

void BST::operatorHelper(NodeT *r1, NodeT *r2, bool &bVal)
{
    if (bVal == false)
    {
        return;
    }
    else if (r1 == NULL && r2 == NULL)
    {
        return;
    }
    else if ((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 == NULL))
    {
        bVal = false;
        return;
    }
    else if (r1->getData() != r2->getData())
    {
        bVal = false;
        return;
    }
    operatorHelper(r1->getLeft(), r2->getLeft(), bVal);
    operatorHelper(r1->getRight(), r2->getRight(), bVal);
}

//Returns a queue with nodes ordered from high to low
queue<int> BST::toQueue()
{
    queue<int> iQ;
    NodeT *curr = root;
    toQueueHelper(curr, iQ);
    return iQ;
}

void BST::toQueueHelper(NodeT *r, queue<int> &q)
{
    if (r != NULL)
    {
        toQueueHelper(r->getRight(), q);
        q.push(r->getData());
        toQueueHelper(r->getLeft(), q);
    }
}

#endif