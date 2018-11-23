//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//FSMList.h

#include "FSMNode.cpp"

class List {
  TerminalInterface *OutInt;
  Node *head;
  Node *ea;

public:
  List(TerminalInterface *);
  ~List();
  int entradaM025();
  int entradaM050();
  int entradaM100();
  int entradaDEV();
  void entradaMEET();
  void entradaETIRPS();
  int getEstadoAtual();
};
