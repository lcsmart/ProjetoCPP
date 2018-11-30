//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//FSMNode.cpp

#include "FSMNode.h"
//construtor inicializa os nodos
Node::Node(int sta) {
  state = sta;
  next = 0;
}

Node *Node::getNext() { return next; } //Retorna o ponteiro para o proximo elemento da lista

void Node::setNext(Node *nxt) { next = nxt; } //Atualiza o proximo elemento da lista

int Node::getState() { return state; } //Retorna o Estado Atual
