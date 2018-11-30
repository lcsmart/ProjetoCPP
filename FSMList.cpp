// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// FSMList.cpp

#include "FSMList.h"
#ifdef TERMINALLINUX

//construtor que inicializa a máquina de estados
List::List(TerminalInterface *NewOutInterface) {
  OutInt = NewOutInterface;
  Node *n;
  Node *t;
  int count = 0;
  n = new Node(count);
  head = n;
  t = n;
  ea = head;
  for (count = 25; count < 175; count += 25) {
    n = new Node(count);
    t->setNext(n);
    t = n;
  }
}
#endif
#ifdef EMBEDDEDTERMINAL
List::List(EmbeddedInterface *NewOutInterface) {
  OutInt = NewOutInterface;
  Node *n;
  Node *t;
  int count = 0;
  n = new Node(count);
  head = n;
  t = n;
  ea = head;
  for (count = 25; count < 175; count += 25) {
    n = new Node(count);
    t->setNext(n);
    t = n;
  }
}
#endif

//destrutor da máquina de estados
List::~List() {
  Node *cursor = head;
  while (head) {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

//Funções que correspondem as entradas
int List::entradaM025() {
  int change;
  int entrada = 25;
  int state;
  state = ea->getState();
  switch (state) {
  case 0:
  case 25:
  case 50:
  case 75:
  case 100:
  case 125:
    ea = ea->getNext();
    return 0;
    break;
  default:
    change = entrada + state - 150;
    return change;
    break;
  }
}

int List::entradaM050() {
  int change;
  int entrada = 50;
  int state;
  state = ea->getState();
  switch (state) {
  case 0:
  case 25:
  case 50:
  case 75:
  case 100:
    ea = ea->getNext();
    ea = ea->getNext();
    return 0;
    break;
  case 125:
    change = entrada + state - 150;
    ea = ea->getNext();
    return change;
    break;
  default:
    change = entrada + state - 150;
    return change;
    break;
  }
}

int List::entradaM100() {
  int change;
  int entrada = 100;
  int state;
  state = ea->getState();
  change = entrada + state - 150;
  switch (state) {
  case 0:
  case 25:
  case 50:
    ea = ea->getNext();
    ea = ea->getNext();
    ea = ea->getNext();
    ea = ea->getNext();
    return 0;
    break;
  case 75:
    ea = ea->getNext();
    ea = ea->getNext();
    ea = ea->getNext();
    return change;
    break;
  case 100:
    ea = ea->getNext();
    ea = ea->getNext();
    return change;
    break;
  case 125:
    ea = ea->getNext();
    return change;
    break;
  default:
    return change;
    break;
  }
}

int List::entradaDEV() {
  int state;
  state = ea->getState();
  ea = head;
  return state;
}

void List::entradaMEET() {
  int state;
  state = ea->getState();
  switch (state) {
  case 0:
  case 25:
  case 50:
  case 75:
  case 100:
  case 125:
    OutInt->displayMessage("Saldo Insuficiente");
    usleep(2000000);
    break;
  default:
    OutInt->displayMessage("Obrigado pela compra!");
    usleep(2000000);
    removeMeet();
    ea = head;
    break;
  }
}

void List::entradaETIRPS() {
  int state;
  state = ea->getState();
  switch (state) {
  case 0:
  case 25:
  case 50:
  case 75:
  case 100:
  case 125:
    OutInt->displayMessage("Saldo Insuficiente");
    usleep(2000000);
    break;
  default:
    OutInt->displayMessage("Obrigado pela compra!");
    usleep(2000000);
    removeEtirps();
    ea = head;
    break;
  }
}

//retorna estado atual
int List::getEstadoAtual() {
  int state;
  state = ea->getState();
  return state;
}
