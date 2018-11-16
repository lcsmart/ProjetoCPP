/*
   File List.h
   Advertising

 */

#include "Node.cpp"

class List {

  int numElem;
  Node *head;

public:
  List();
  ~List();
  int getNumElem();
  void insertionNode(Node *func);
  void switchLasttofirst();
  Node* getLastnodeaddress();
  Node* getFirstnodeaddress();
  int removeLastnode(int);
  void listAll();
  void organizePosition();
  void updateHead();
  void updateNodeaddress(Node *, Node*);
};
