//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//EmbeddedInterface.cpp

#include "EmbeddedInterface.h"

//Construtor da classe da Interface Embarcada
EmbeddedInterface::EmbeddedInterface() {
  display = lcdInit (2, 16, 4, 11, 10, 0, 1, 2, 3, 0, 0, 0, 0) ; //Inicializacao do display
  lcdHome(display);
  lcdClear(display);
  wiringPiSetup(); //Inicializa os Pinos
  pinMode(MOEDA25, INPUT);
  pinMode(MOEDA50, INPUT);
  pinMode(MOEDA100, INPUT);
  pinMode(DEVOLVER, INPUT);
  pinMode(ETIRPS, INPUT);
  pinMode(MEET, INPUT);
  pinMode(ATUALIZARFILA, INPUT);
  pinMode(REMOVERANUNCIO, INPUT);
  pinMode(SIM, INPUT);
  pinMode(NAO, INPUT);
  pinMode(MANUTENCAO, INPUT);
}

EmbeddedInterface::~EmbeddedInterface() {
}

//Definicao da Funcao Abstrata para Interface Embarcada
void EmbeddedInterface::displayMessage(string message){
  lcdHome(display);
  lcdClear(display);
  lcdPrintf(display, message.c_str());
}
