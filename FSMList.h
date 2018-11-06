

#include "FSMNode.cpp"

class List {

  int numElem;
  Node *head;
  Node *ea;

public:
  List();
  ~List();
  // int getNumElem();
  // void insertionSort(Node *func); // Em ordem crescente da matricula
  //  int removeNode(int sta);        // Por numero de matricula
  int entradaM025();
  int entradaM050();
  int entradaM100();
  int entradaDEV();
  void entradaMEET();
  void entradaETIRPS();
  int getEstadoAtual();
};
