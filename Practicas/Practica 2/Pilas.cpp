#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main(){
    stack<string> miPila;

    miPila.push("A");
    miPila.push("B");
    miPila.push("C");
    miPila.push("D");

    cout<<"Tamaño de la fila: "<<miPila.size()<<endl;

    while (!miPila.empty()){
        cout<<miPila.top()<<endl;
        miPila.pop();
    }

    cout<<"Tamaño de la fila: "<<miPila.size()<<endl;

    
    return 0;
}