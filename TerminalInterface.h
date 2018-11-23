//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//TerminalInterface.h

#include <iostream>
#include <string>

using namespace std;

class TerminalInterface{
public:
  TerminalInterface();
  ~TerminalInterface();
  void displayMessage(string message);
};
