//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingNode.h

#include <iostream>
#include <string>

using namespace std;
// Classe dos Nodos que representam anuncios
template<typename T>
class AdvertisingNode {
        int position;
        T advertising;
        AdvertisingNode<T> *next;
public:
        AdvertisingNode();
        T getAdvertising();
        int getPosition();
        AdvertisingNode<T> *getNext();
        void setAdvertising (string);
        void setNext(AdvertisingNode<T> *nxt);
        void setPosition(int);
};
