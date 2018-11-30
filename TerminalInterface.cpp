//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//TerminalInterface.cpp

#include "TerminalInterface.h"

TerminalInterface::TerminalInterface() {
}

TerminalInterface::~TerminalInterface() {
}

//Definicao da Funcao Abstrata para Interface Terminal
void TerminalInterface::displayMessage(string message){
  cout << "(---------------Display---------------)" << endl << message << endl << "(---------------Display---------------)" << endl;
}
