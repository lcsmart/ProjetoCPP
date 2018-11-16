//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingList.cpp

#include "AdvertisingList.h"

AdvertisingList::AdvertisingList() {
  head = 0;
  numElem = 0;
}

AdvertisingList::~AdvertisingList() {
  AdvertisingNode *cursor = head;
  while (head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

int AdvertisingList::getNumElem() { return numElem; }

void AdvertisingList::insertionNode(AdvertisingNode *func) { // int mat, string nom, float sal, int
                                       // horas, float dec, char sta, int quad)
                                       // {
  numElem = 1;
  AdvertisingNode *p = head;
  AdvertisingNode *q = head;
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
int AdvertisingList::removeLastnode(int count) {
  numElem += count;
  int result;
  AdvertisingNode *p = head;
  AdvertisingNode *q = head;
  AdvertisingNode *t = head;

  if (head == 0)
    result = 0;
  // Não existem Nodos na lista
  else {
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
      result = t->getPosition();
      delete t;
      numElem = numElem - 1;
      // Há somente 1 Nodo na Lista
    } else {
      t->setNext(q);
      result = p->getPosition();
      delete p;
      numElem = numElem - 1;
      // Ultimo Nodo deletado e o Próximo aponta para 0
    }
    return result;
  }
}

void AdvertisingList::listAll() {
  AdvertisingNode *aux = head;

  cout << "Lista de Propagandas" << endl << "------------------" << endl;
  while (aux != 0) {
    cout << "Posição        : " << aux->getPosition() << endl;
    cout << "Propaganda             : " << aux->getAdvertising() << endl;
    cout << "----------------------------" << endl;
    aux = aux->getNext();
  }
}

void AdvertisingList::switchLasttofirst() {
  int count = 1;
  AdvertisingNode *p = head;
  AdvertisingNode *q = head;
  AdvertisingNode *t = head;

  if (head == 0) {
    cout << "Não há propagandas na lista" << endl;
  } else if (head->getNext() == 0) {
    cout << "Só há uma propaganda na lista" << endl;
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

    t->setNext(q);
    p->setPosition(1);
    p->setNext(head);
    head = p;
  }
}
AdvertisingNode *AdvertisingList::getLastnodeaddress() {
  AdvertisingNode *address;
  AdvertisingNode *p = head;
  AdvertisingNode *q = head;

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

AdvertisingNode *AdvertisingList::getFirstnodeaddress() {
  AdvertisingNode *address;
  address = head;
  return address;
}

void AdvertisingList::updateHead() { head = 0; }

void AdvertisingList::organizePosition() {
  int count = 1;
  AdvertisingNode *p = head;
  AdvertisingNode *q = head;
  if (head == 0) {
    cout << "Fila 1 Vazia" << endl;
  } else {
    while (q != 0) {
      p = q;
      p->setPosition(count);
      q = p->getNext();
      count += 1;
    }
  }
}
void AdvertisingList::updateNodeAddress(AdvertisingNode *address1, AdvertisingNode *address2) {
  if (address1 == 0) {
    head = address2;
  } else {
    address1->setNext(address2);
  }
}
