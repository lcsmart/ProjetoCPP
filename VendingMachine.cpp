// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// VendingMachine.cpp

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

#include "OutputInterface.cpp"
#include "TerminalInterface.cpp"

#include "AdvertisingDisplay.cpp"

#include "Stock.cpp"

#include "FSMList.cpp"

#define PC

main() {
#ifdef PC
  TerminalInterface *OutInterface = new TerminalInterface();
#endif
}
