//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingNode.h

#include <iostream>
#include <string>

 using namespace std;

class AdvertisingNode {
        int position;
        string advertising;
        AdvertisingNode* next;
public:
        AdvertisingNode();
        string getAdvertising();
        int getPosition();
        AdvertisingNode* getNext();
        void setAdvertising (string);
        void setNext(AdvertisingNode* nxt);
        void setPosition(int);
};
