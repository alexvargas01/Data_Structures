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

bool Priority::push (int num){
    data.push_back(num);
    

}



#endif