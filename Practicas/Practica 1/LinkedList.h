#include <iostream>
#include "Node.h"

#ifndef LinkedList_h
#define LinkedList_h
using namespace std;

template <class T>
class LinkedList {
  public:
    //Constructor
    LinkedList();
    //Destructor
    ~LinkedList();  
    //Methods
    int getSize(); 
    bool isEmpty();
    void addFirst(T data);
    void deleteFirst();
    void addLast(T data);
    void deletelast();
    bool add(T data, int);
    void del(int);
    void print();
    int deleteAll();
    // get, set, change
    T get(int);
    T set(T data,int);
    bool change(int,int);
    //PRO 5
    void reverse();
    bool operator==(const LinkedList &LL);
    void operator+=(T data); 
    void operator+=(const LinkedList &LL);
    LinkedList(const LinkedList &LL); 
    void shift(int casillas); 
  private:
    Node<T> *head;
    int size;
    void deleteHelper();
};

//Constructor
template <class T>
LinkedList<T>::LinkedList() {
  head = NULL;
  size = 0;
}

//Destructor
template <class T>
LinkedList<T>::~LinkedList(){
  deleteHelper();
}

//Access
template <class T>
int LinkedList<T>::getSize() {
  return size;
}

//Methods
template <class T>
bool LinkedList<T>::isEmpty() {
  return ( head == NULL );
  // return ( size == 0 );

}

template <class T>
void LinkedList<T>::addFirst(T data){
  head = new Node<T>(data, head);
  size++;
}

template <class T>
void LinkedList<T>::deleteFirst(){
  if (!this->isEmpty()){
    Node<T> *curr = head;
    head = head->getNext();
    delete curr;
    size--;
  }
}

template <class T>
void LinkedList<T>::addLast(T data){
  if (this->isEmpty()){
    addFirst(data);
  } else {
    Node<T> *curr = head;
    while (curr->getNext() != NULL){
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data));
    size++;
  }
}

template <class T>
void LinkedList<T>::deletelast(){
  if (size <= 1){
    deleteFirst();
  }else {
    Node<T> *curr = head;
    while ( curr->getNext()->getNext() != NULL){
      curr = curr->getNext();
    }
    delete curr->getNext();
    curr->setNext(NULL);
    size--;
  }
}

template <class T>
bool LinkedList<T>::add(T data, int pos){
  if (pos>size){
    return false;
  }
  if (pos == 0){
    addFirst(data);
  } else if (pos == size){
    addLast(data);
  } else {
    Node<T> *curr = head;
    for (int i=1;i<pos;i++){
      curr = curr->getNext();
    }
    curr->setNext(new Node<T>(data, curr->getNext()));
    size++;
  }
  return true;
}

template <class T> 
void LinkedList<T>::del(int pos){
  if (pos<size){
    if (pos == 0){
      deleteFirst();
    } else if (pos == size-1){
      deletelast();
    } else {
      Node<T> *curr = head;
      for (int i=1;i<pos;i++){
        curr = curr->getNext();
      }
      Node<T> *temp = curr->getNext();
      curr->setNext(temp->getNext());
      delete temp;
      size--;
    }
  }
}



template <class T>
T LinkedList<T>::get(int pos){
  Node<T> *curr = head;
  for (int i=0;i<pos;i++){
    curr = curr->getNext();
  }
  return curr->getData();
}


/*
template <class T>
T LinkedList<T>::get(int iX){
  int iVar=0;

  if (!this->isEmpty()){
    if (iX < size && iX>=0){
      Node<T> *curr = head;
      while (iVar != iX){
        curr = curr->getNext();
        iVar++;
      }
      if (iVar == iX){
        return *curr;
      }
    }
  }
  return NULL;
}  
*/


template <class T>
T LinkedList<T>::set(T data,int pos){
  Node<T> *curr =head;
  for (int i = 0;i<pos;i++){
    curr = curr->getNext();
  }
  T temp = curr->getData();
  curr->setData(data);
  return temp;
}

/*
template <class T>
void LinkedList<T>::set(T data, int iX){
  Node<T> *curr = get(iX);
  if (curr != NULL){
    curr-> setData(data);
  }
}
*/


template <class T>
bool LinkedList<T>::change(int pos1,int pos2){
  if (pos1 == pos2){
    return true;
  }

  //TERNARIO CONDICION, luego va if y luego else
  int posMen = (pos1 < pos2) ? pos1 : pos2;
  int posMay = (pos1 > pos2) ? pos1 : pos2;

  Node<T> *curr = head;
  for (int i=0;i<posMen;i++){
    curr = curr->getNext();
  }

  Node<T> *curr2 = curr;
  for (int i=posMen;i<posMay;i++){
    curr2 = curr2->getNext();
  }

  T temp = curr->getData();
  curr->setData(curr2->getData());
  curr2->setData(temp);

  return true;
}

/*
template <class T>
bool LinkedList<T>::change(int pos1,int pos2){
  Node<T> *curr1 = get(pos1);
  Node<T> *curr2 = get(pos2);
  T temp;

  if (curr1 != NULL && curr2 != NULL){
    temp = curr1->getData();
    curr2->setData(temp);
    curr1->setData(curr2->getData());
    return true;
  }
  return false;
}
*/

template <class T>
void LinkedList<T>::print(){
  Node<T> *curr =head;
  while (curr != NULL){
    cout<<curr->getData()<<" ";
    curr = curr->getNext();
  }
  cout<<endl;
}

template <class T>
int LinkedList<T>::deleteAll(){
  int cant = size;
  deleteHelper();
  size = 0;
  return cant;
}

template <class T>
void LinkedList<T>::deleteHelper(){
  Node<T> *curr = head;
   while (!this->isEmpty()){
    head = head->getNext();
    delete curr;
    curr = head;
  }
}

template <class T>
void LinkedList<T>::reverse(){
  if ( size > 1){
    Node<T> *curr2=head-> getNext();
    Node<T> *curr3=head-> getNext() -> getNext();

    head->setNext(NULL);

    while (curr2->getNext() != NULL){
      curr2 -> setNext(head);
      head = curr2;
     curr2 = curr3;
     if (curr3 -> getNext() != NULL) {
        curr3 = curr3 -> getNext();
      } else {
        curr2 = curr3;
         curr2 -> setNext(head);
        head = curr2;
        break;
      }
    }
  }
}



template <class T>
bool LinkedList<T>::operator==(const LinkedList &LL)  {
  Node<T> *curr1 = head;
  Node<T> *curr2 = LL.head;

  while (curr1 != NULL || curr2 != NULL){
      if (curr1->getData() == curr2-> getData()){
        curr1 = curr1->getNext();
        curr2 = curr2->getNext();
    } else {
      return false;
    }
  }

  if (curr1 != NULL || curr2 != NULL){
    return false;
  }
  
  return true;
}

template <class T>
void LinkedList<T>::operator+=(T data){
  this-> addLast(data);
}

template <class T>
void LinkedList<T>::operator+=(const LinkedList &LL){
  Node<T> *curr = head;
  Node<T> *curr2 = LL.head;

  while (curr->getNext() != NULL){
    curr = curr->getNext();
  }

  /*
  while (curr2 != NULL){
    this->addLast(curr2->getData());
    curr2=curr2->getNext();
    size++;
  }
  */

  while (curr2 != NULL){
    curr->setNext(new Node<T>(curr2->getData()));
    curr2=curr2->getNext();
    curr=curr->getNext();
    size++;
  }
}

template <class T> 
LinkedList<T>::LinkedList(const LinkedList &LL){
  head = NULL;
  size = 0;
  
  Node<T> *curr2 = LL.head;

  /*
  while (curr != NULL){
    this->addLast(curr->getData());
    curr=curr->getNext();
    size++;
  }
  */
 
 head = (new Node<T>(curr2->getData()));
 Node<T> *curr1 = head;
 curr2=curr2->getNext();
 
  while (curr2 != NULL){
    curr1->setNext(new Node<T>(curr2->getData()));
    curr2=curr2->getNext();
    curr1=curr1->getNext();
    size++;
  }

}

template <class T>
void LinkedList<T>::shift(int casillas){
  int iS=0,iTemp1 = 0,iTemp2=0;
  int iTam=size;
  
  iS=casillas % size;

  Node<T> *curr1=head;
  Node<T> *curr2=head;
  
  if (iS == 0) {
    return;
  }

  if (iS<0){
    iS=iS+iTam;
  }
 
  while (iTemp2 != size-iS-1){
    curr2=curr2->getNext();
    iTemp2++;
  }
  curr1 = curr2 -> getNext();

  while (curr1->getNext() != NULL){
    curr1 = curr1->getNext();
  }

  curr1->setNext(head);
  head = curr2 -> getNext();
  curr2->setNext(NULL);
}


#endif