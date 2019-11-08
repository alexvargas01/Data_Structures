#include <iostream>
#include <vector>
using namespace std;

#ifndef Priority_h
#define Priority_h

class Priority{
    public:
        //Constructors
        Priority();
        Priority(bool);
        //Methods
        bool push(int);
        void pop();
        int top();
        int size();
        bool empty();
    private:
        vector<int> data;
        bool bPriority;
        int iSize;

};

//Constructors
Priority::Priority(){
    data.push_back(0);
    bPriority=true;
    iSize=1;
}

Priority::Priority(bool Priority2){
    data.push_back(0);
    bPriority=Priority2;
    iSize=1;
}

int Priority::top(){
    if (data.size()>1){
        return data[1];
    }else{
        return 0;
    }
}

int Priority::size(){
    return iSize-1;
}

bool Priority::empty(){
    if (iSize == 1){
        return true;
    }else{
        return false;
    }
}






#endif