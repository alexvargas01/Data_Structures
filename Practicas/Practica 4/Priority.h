#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#ifndef Priority_h
#define Priority_h

class Priority
{
public:
    //Constructors
    Priority();
    Priority(bool);
    //Methods
    void push(int);
    void pop();
    int top();
    int size();
    bool empty();

private:
    vector<int> data;
    bool bPriority;
    int iSize;
    void balancePQ();
};

//Constructors
Priority::Priority()
{
    data.push_back(0);
    bPriority = true;
    iSize = 1;
}

Priority::Priority(bool Priority2)
{
    data.push_back(0);
    bPriority = Priority2;
    iSize = 1;
}

void Priority::push(int num)
{
    data.push_back(num);
    iSize++;
    if (iSize > 2)
    {
        balancePQ();
    }
    else
    {
        return;
    }
}

void Priority::pop()
{
    if (data.size() > 4)
    {
        data[1] = data[data.size() - 1];
        data.pop_back();
        balancePQ();
    }
    else if (data.size() <= 4)
    {
        data.pop_back();
    }
    else
    {
        return;
    }
    iSize--;
}

int Priority::top()
{
    if (data.size() > 1)
    {
        return data[1];
    }
    else
    {
        return 0;
    }
}

int Priority::size()
{
    return iSize - 1;
}

bool Priority::empty()
{
    if (iSize == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Priority::balancePQ()
{
    int pivot = (iSize - 1) / 2;
    int leftN, rightN;
    int iVar, aux;

    if (bPriority == true)
    {
        while (pivot >= 1)
        {
            leftN = pivot * 2;

            if (pivot * 2 + 1 <= iSize - 1)
            {
                rightN = 2 * pivot + 1;
            }
            else
            {
                rightN = leftN;
            }

            if (data[rightN] < data[leftN])
            {
                iVar = leftN;
            }
            else
            {
                iVar = rightN;
            }

            if (data[pivot] < data[iVar])
            {
                swap(data[pivot], data[iVar]);
            }
            pivot--;
        }
    }
    else
    {
        while (pivot >= 1)
        {
            leftN = pivot * 2;

            if (pivot * 2 + 1 <= iSize - 1)
            {
                rightN = 2 * pivot + 1;
            }
            else
            {
                rightN = leftN;
            }

            if (data[rightN] > data[leftN])
            {
                aux = leftN;
            }
            else
            {
                aux = rightN;
            }

            if (data[pivot] > data[aux])
            {
                swap(data[pivot], data[aux]);
            }
            pivot--;
        }
    }
}

#endif