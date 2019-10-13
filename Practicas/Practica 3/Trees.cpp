#include <iostream>
#include "BST.h"
#include <queue>
#include <stack>

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

    BST arbol2;

    
    arbol2.add(18);
    arbol2.add(11);
    arbol2.add(21);
    arbol2.add(4);
    arbol2.add(13);
    arbol2.add(19);
    arbol2.add(26);
    arbol2.add(2);
    arbol2.add(10);
    arbol2.add(17);
    arbol2.add(24);
    arbol2.add(14);    

    
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

    cout<<"Max Width: ";
    cout<<arbol.maxWidth()<<endl;
    

   cout<<endl;
   if (arbol == arbol2){
       cout<<"EI"<<endl;
   }else {
       cout<<"Nel prro"<<endl;
   }
    cout<<"Nearest is: ";
    cout<<arbol2.nearstRelative(24,26)<<endl;

    queue<int> result;
    result = arbol.toQueue();

    cout<<"Queue is: ";
    while (!result.empty()){
        cout<<result.front()<<" ";
        result.pop();
    }
    cout<<"\n";
  



    return 0;
}