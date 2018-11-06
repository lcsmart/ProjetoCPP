/*
File FSMNode.h
*/

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
