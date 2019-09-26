#include <iostream>

using namespace std;

#include "LinkedList.h"


int main() {
  LinkedList<string> miLista;
  LinkedList<string> miLista2;

  miLista.addFirst("Hola");
  miLista.addFirst("Mundo!");
  miLista.addFirst("estudien");
  miLista.addFirst("para su EXAMEN");

  miLista.reverse();
   

  miLista2.addFirst("Hola");
  miLista2.addFirst("Mundo!");
  miLista2.addFirst("estudien");
  miLista2.addFirst("para su EXAMEN");


  miLista2.reverse();


  
  if (miLista == miLista2){
    cout<<"CSO"<<endl;
  }else {
    cout<<"12345"<<endl;
  }

  
  
  
  //miLista+=miLista2;
  miLista.print();

  LinkedList<string> miLista3 = miLista;

  miLista3.print();




  // for( int i = 0; i < miLista.getSize(); i++ ) {
  //   cout << miLista.get(i) << " ";
  // }
  // cout << endl;

  //miLista.print();
 

  //miLista.addLast("!!!!!!!");
  //miLista.print();

  // miLista.deleteFirst();
  // miLista.print();

  // miLista.del(1);
  // miLista.print();

  // miLista.deleteLast();
  // miLista.print();

  // miLista.deleteAll();
  // miLista.print();
  /*
  cout << miLista.get(0) << endl;

 // cout << miLista.set("LIMON",2) << endl;
  miLista.print();

 // miLista.change(1, 4);
  miLista.print();
  */

  return 0;
}