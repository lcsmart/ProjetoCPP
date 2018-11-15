/*
   File Node.cpp
   Advertising

 */

#include "Node.h"

// Constructor - initializes the node
//
Node::Node() { next = 0; }

string Node::getAdvertising() { return advertising; }

int Node::getPosition() { return position; }

// getNext returns a pointer to the next node in the linked list
//
Node *Node::getNext() { return next; }

void Node::setAdvertising(string novoAdvertising) {
  advertising = novoAdvertising;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node *nxt) { next = nxt; }

void Node::setPosition(int pos) { position = pos; }
