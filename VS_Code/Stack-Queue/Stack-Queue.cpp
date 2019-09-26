#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

bool validateN(string d){
    for (int i = 0;i<d.length();i++){
    if (d[i] == '0' || d[i] == '1' || d[i] == '2' || d[i] == '3' || d[i] == '4' || d[i] == '5' || d[i] == '6' || d[i] == '7' || d[i] == '8' || d[i] == '9'){
        return true;
        }
    }
    return false;
}

bool validateO(string d){
    if (d == "+" || d == "-" || d == "*" || d == "/"){
        return true;
    }else {
        return false;
    }
}

int operations(int x, int y, string d){
    int result;
    if (d == "+"){
        result = y+x;
        return result;
    }
    if (d == "-"){
        result = y-x;
        return result;
    }
    if (d == "*"){
        result = y*x;
        return result;
    }
    if (d == "/"){
        result = y/x;
        return result;
    }
    return 0;
}


int main() {
  string d,data;
  stack<int> stack;
  queue<int> queue;
  priority_queue<int, vector<int>, greater<int> > pQueue;

  int sX=0,sY=0;
  int qX=0,qY=0;
  int pX=0,pY=0;

 
  std::getline(cin, data);
  while (data != "#") {
    stringstream ss;
    ss << data;
    while (ss >> d){
        if (validateN(d)==true){
            int n = stoi(d);
            stack.push(n);
            queue.push(n);
            pQueue.push(n);
        }else if (validateO(d)==true){
            //stack
            sX = stack.top();
            stack.pop();
            sY = stack.top();
            stack.pop();
            int result1 = operations(sX,sY,d);
            stack.push(result1);

            //queue
            qX = queue.front();
            queue.pop();
            qY = queue.front();
            queue.pop();
            int result2 = operations(qX,qY,d);
            queue.push(result2);

            
            //Priority Queue
            pX = pQueue.top();
            pQueue.pop();
            pY = pQueue.top();
            pQueue.pop();
            int result3 = operations(pX,pY,d);
            pQueue.push(result3);
            
        }
    }
    cout<<stack.top()<<" "<<queue.front()<<" "<<pQueue.top()<<endl;
    stack.pop();
    queue.pop();
    pQueue.pop();
    
    std::getline(cin, data); 
  }
}