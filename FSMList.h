//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//FSMList.h

#include "FSMNode.cpp"
//Lista que corresponde a máquina de estados
class List: public Stock{
  #ifdef TERMINALLINUX
  TerminalInterface *OutInt;
  #endif
  #ifdef EMBEDDEDTERMINAL
  EmbeddedInterface *OutInt;
  #endif
  Node *head;
  Node *ea;

public:
  #ifdef TERMINALLINUX
  List(TerminalInterface *);
#endif
  #ifdef EMBEDDEDTERMINAL
  List(EmbeddedInterface *);
  #endif
  ~List();
  int entradaM025();
  int entradaM050();
  int entradaM100();
  int entradaDEV();
  void entradaMEET();
  void entradaETIRPS();
  int getEstadoAtual();
};
