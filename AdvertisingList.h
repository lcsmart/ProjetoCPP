//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingList.h

#include "AdvertisingNode.cpp"
//classe das listas que ligam os nodos que representam anúncios
template<typename T>
class AdvertisingList {
  int numElem;
  AdvertisingNode<T> *head;

//funções da lista
public:
  AdvertisingList();
  ~AdvertisingList();
  int getNumElem();
  void insertionNode(AdvertisingNode<T> *func);
  void switchLasttofirst();
  AdvertisingNode<T> *getLastnodeaddress();
  AdvertisingNode<T> *getFirstnodeaddress();
  void removeLastnode();
  void removeFirstNode();
  void listAll();
  void organizePosition();
  void updateHead();
  void updateNodeAddress(AdvertisingNode<T> *, AdvertisingNode<T> *);
  string getCurrentNode();
  string getLastNode();
};
