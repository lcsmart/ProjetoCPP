//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingNode.cpp

#include "AdvertisingNode.h"

// Construtor inicializa o Nodo
//
template<typename T>
AdvertisingNode<T>::AdvertisingNode() { next = 0; }

// Retorna a propaganda
template<typename T>
T AdvertisingNode<T>::getAdvertising() { return advertising; }

// Retorna a posição do Nodo na Fila.
template<typename T>
int AdvertisingNode<T>::getPosition() { return position; }

// getNext retorna o ponteiro que aponta para o próximo nodo da Fila.
template<typename T>
AdvertisingNode<T> *AdvertisingNode<T>::getNext() { return next; }

// setAdvertising muda a propaganda para uma nova propaganda.
template<typename T>
void AdvertisingNode<T>::setAdvertising(string novoAdvertising) {
  advertising = novoAdvertising;
}

// setNext muda o ponteiro que aponta/apontava para o próximo nodo da Fila
template<typename T>
void AdvertisingNode<T>::setNext(AdvertisingNode *nxt) { next = nxt; }

// atualiza a posição do nodo na fila
template<typename T>
void AdvertisingNode<T>::setPosition(int pos) { position = pos; }
