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

    arbol.printLeaves();
    cout<<arbol.count()<<endl;
    cout<<arbol.height()<<endl;
    cout<< "Height is: "<<arbol.whatLevelamI(7)<<endl;
    for (int i : arbol.ancestors(7)) {
        cout << i << " ";
    }
    cout << endl;
    arbol.print(5);

    

    return 0;
}