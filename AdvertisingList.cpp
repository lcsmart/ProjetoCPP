//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingList.cpp

#include "AdvertisingList.h"
// construtor inicizalia a lista sem nodos com o ponteiro head apontando para 0.
template<typename T>
AdvertisingList<T>::AdvertisingList() {
  head = 0;
  numElem = 0; // número de nodos na fila.
}

//destrutor, deleta todos os nodos da fila e ao final faz o ponteiro head apontar para 0.
template<typename T>
AdvertisingList<T>::~AdvertisingList() {
  AdvertisingNode<T> *cursor = head;
  while (head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

// retorna o número de nodos na fila.
template<typename T>
int AdvertisingList<T>::getNumElem() { return numElem; }

// Adiciona um nodo a fila.
template<typename T>
void AdvertisingList<T>::insertionNode(AdvertisingNode<T> *func) {
  numElem = 1;
  AdvertisingNode<T> *p = head;
  AdvertisingNode<T> *q = head;
  if (head == 0) {
    head = func;
    func->setPosition(numElem);
    // head = new Node(string);
  } else {
    while (q != 0) {
      numElem += 1;
      p = q;
      q = p->getNext();
    }
    p->setNext(func);
    func->setPosition(numElem);
    // func = new Node(string)
    // p->setNext(func)
  }
}

//remove o último nodo da fila
template<typename T>
 void AdvertisingList<T>::removeLastnode() {
  AdvertisingNode<T> *p = head;
  AdvertisingNode<T> *q = head;
  AdvertisingNode<T> *t = head;

  if (head == 0){
    numElem = 0;
    // Não existem Nodos na lista
  }else {
    q = p->getNext();
    p = t->getNext();
    while (q != 0) {
      p = q;
      q = p->getNext();
      if (q != 0) {
        t = t->getNext();
      }
    }
    if (t == head && p == 0) {
      head = 0;
      delete t;
      organizePosition();
      // Há somente 1 Nodo na Lista
    } else {
      t->setNext(q);
      delete p;
      organizePosition();
      // Ultimo Nodo deletado e o Próximo aponta para 0
    }
  }
}

//remove o primeiro nodo da fila
template<typename T>
void AdvertisingList<T>::removeFirstNode(){
    AdvertisingNode<T> *p = head;
    if (head == 0){
     // não há nodos na lista
    } else if (head->getNext() == 0){ // há somente um nodo na lista
      delete head;
      head = 0;
      numElem = numElem - 1;
    } else {
      head = head->getNext();
      delete p;
      organizePosition();
    }
}

//lista todas as propagandas da fila.
template<typename T>
void AdvertisingList<T>::listAll() {
  AdvertisingNode<T> *aux = head;

  cout << "Lista de Propagandas" << endl << "------------------" << endl;
  while (aux != 0) {
    cout << "Posição        : " << aux->getPosition() << endl;
    cout << "Propaganda             : " << aux->getAdvertising() << endl;
    cout << "----------------------------" << endl;
    aux = aux->getNext();
  }
}

// pega o primeiro nodo da fila e o coloca em ultimo na fila.
template<typename T>
void AdvertisingList<T>::switchLasttofirst() {
  int count = 1;
  AdvertisingNode<T> *p = head;
  AdvertisingNode<T> *q = head;
  AdvertisingNode<T> *t = head;

  if (head == 0) {
    //cout << "Não há propagandas na lista" << endl;
  } else if (head->getNext() == 0) {
    //cout << "Só há uma propaganda na lista" << endl;
  } else {
    q = p->getNext();
    p = t->getNext();
    while (q != 0) {
      count += 1;
      p = q;
      q = p->getNext();
      t->setPosition(count);
      if (q != 0) {
        t = t->getNext();
      }
    }

    p->setNext(head);
    head = head->getNext();
    t= p->getNext();
    t->setNext(q);
    organizePosition();


  }
}
//Pega o endereço do ultimo nodo da fila (retorna um ponteiro)
template<typename T>
AdvertisingNode<T> *AdvertisingList<T>::getLastnodeaddress() {
  AdvertisingNode<T> *address;
  AdvertisingNode<T> *p = head;
  AdvertisingNode<T> *q = head;

  if (head == 0) {
    address = head;
  } else if (head->getNext() == 0) {
    address = head;
  } else {
    q = p->getNext();
    while (q != 0) {
      p = q;
      q = p->getNext();
    }
  }
  address = p;
  return address;
}

//Pega o endereço do primeiro nodo da fila (retorna um ponteiro)
template<typename T>
AdvertisingNode<T> *AdvertisingList<T>::getFirstnodeaddress() {
  AdvertisingNode<T> *address;
  address = head;
  return address;
}

//Atualiza o ponteiro head da fila (faz ele apontar para 0)
template<typename T>
void AdvertisingList<T>::updateHead() { head = 0; }

//Organiza o número inteiro que corresponde a posição do Nodo na fila.
template<typename T>
void AdvertisingList<T>::organizePosition() {
  numElem = 0;
  int count = 1;
  AdvertisingNode<T> *p = head;
  AdvertisingNode<T> *q = head;
  if (head == 0) {
    cout << "Fila 1 Vazia" << endl;
  } else {
    while (q != 0) {
      p = q;
      p->setPosition(count);
      q = p->getNext();
      count += 1;
      numElem += 1;
    }
  }
}
//função utilizada para juntar as filas.
template<typename T>
void AdvertisingList<T>::updateNodeAddress(AdvertisingNode<T> *address1, AdvertisingNode<T> *address2) {
  if (address1 == 0) {
    head = address2;
  } else {
    address1->setNext(address2);
  }
}
//retorna o anuncio do nodo atual.
template<typename T>
string AdvertisingList<T>::getCurrentNode(){
  return head->getAdvertising();
}

//retorna o anuncio do último nodo da fila.
template<typename T>
string AdvertisingList<T>::getLastNode(){
  AdvertisingNode<T> *p = getLastnodeaddress();
  return p->getAdvertising();
}
