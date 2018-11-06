/*
   File FSMNode.cpp
*/
#include "FSMNode.h"
// Constructor - initializes the node
//
Node::Node(int sta) {
  state = sta;
  next = 0;
}
// getNext returns a pointer to the next node in the linked list
//
Node *Node::getNext() { return next; }
// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node *nxt) { next = nxt; }

int Node::getState() { return state; }
