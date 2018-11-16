//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingList.h

#include "AdvertisingNode.cpp"

class AdvertisingList {

  int numElem;
  AdvertisingNode *head;

public:
  AdvertisingList();
  ~AdvertisingList();
  int getNumElem();
  void insertionNode(AdvertisingNode *func);
  void switchLasttofirst();
  AdvertisingNode* getLastnodeaddress();
  AdvertisingNode* getFirstnodeaddress();
  int removeLastnode(int);
  void listAll();
  void organizePosition();
  void updateHead();
  void updateNodeAddress(AdvertisingNode *, AdvertisingNode*);
};
