/*
   File List.cpp
   Advertising

 */

#include "List.h"

List::List() {
  head = 0;
  numElem = 0;
}

List::~List() {
  Node *cursor = head;
  while (head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

int List::getNumElem() { return numElem; }

void List::insertionNode(Node *func) { // int mat, string nom, float sal, int
                                       // horas, float dec, char sta, int quad)
                                       // {
  numElem = 1;
  Node *p = head;
  Node *q = head;
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
int List::removeLastnode(int count) {
  numElem += count;
  int result;
  Node *p = head;
  Node *q = head;
  Node *t = head;

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

void List::listAll() {
  Node *aux = head;

  cout << "Lista de Propagandas" << endl << "------------------" << endl;
  while (aux != 0) {
    cout << "Posição        : " << aux->getPosition() << endl;
    cout << "Propaganda             : " << aux->getAdvertising() << endl;
    cout << "----------------------------" << endl;
    aux = aux->getNext();
  }
}

void List::switchLasttofirst() {
  int count = 1;
  Node *p = head;
  Node *q = head;
  Node *t = head;

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
Node *List::getLastnodeaddress() {
  Node *address;
  Node *p = head;
  Node *q = head;

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

Node *List::getFirstnodeaddress() {
  Node *address;
  address = head;
  return address;
}

void List::updateHead() { head = 0; }

void List::organizePosition() {
  int count = 1;
  Node *p = head;
  Node *q = head;
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
void List::updateNodeaddress(Node *address1, Node *address2) {
  if (address1 == 0) {
    head = address2;
  } else {
    address1->setNext(address2);
  }
}
