//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingNode.cpp

#include "AdvertisingNode.h"

// Constructor - initializes the node
//
AdvertisingNode::AdvertisingNode() { next = 0; }

string AdvertisingNode::getAdvertising() { return advertising; }

int AdvertisingNode::getPosition() { return position; }

// getNext returns a pointer to the next node in the linked list
//
AdvertisingNode *AdvertisingNode::getNext() { return next; }

void AdvertisingNode::setAdvertising(string novoAdvertising) {
  advertising = novoAdvertising;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void AdvertisingNode::setNext(AdvertisingNode *nxt) { next = nxt; }

void AdvertisingNode::setPosition(int pos) { position = pos; }
