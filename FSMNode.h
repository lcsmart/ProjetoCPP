//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//FSMNode.h

#include <iostream>
#include <string>

using namespace std;

class Node {
  int state;
  Node *next;

public:
  Node(int sta);
  Node *getNext();
  void setNext(Node *nxt);
  int getState();
};
