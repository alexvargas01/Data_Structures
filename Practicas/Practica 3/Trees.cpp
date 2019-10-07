#include <iostream>
#include "BST.h"

using namespace std;

int main(){
    BST arbol;

    arbol.add(30);
    arbol.add(25);
    arbol.add(54);
    arbol.add(69);
    arbol.add(-30);
    arbol.add(7);
    arbol.add(0);
    arbol.add(29);
    arbol.add(40);

    cout<<"preOrder: ";
    arbol.print(1);
    cout<<"inOrder: ";
    arbol.print(2);
    cout<<"postOrder: "; 
    arbol.print(3);

    cout<<"Leaves are: ";
    arbol.printLeavesCHR();
    cout<<"# of Nodes: " <<arbol.count()<<endl;
    cout<<"Height of tree: "<<arbol.height()<<endl;
    cout<< "Height of Node: "<<arbol.whatLevelamI(7)<<endl;
    cout<<"Ancestors of Node: ";
    for (int i : arbol.ancestors(7)) {
        cout << i << " ";
    }
    cout << endl;
    cout<<"Level x Level: ";
    arbol.print(5);

    

    return 0;
}