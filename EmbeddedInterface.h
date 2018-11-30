//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//EmbeddedInterface.h

//Definicao dos Pinos GPIO
#define MOEDA25 1
#define MOEDA50 2
#define MOEDA100 3
#define DEVOLVER 4
#define ETIRPS 5
#define MEET 6
#define ATUALIZARFILA 7
#define REMOVERANUNCIO 8
#define SIM 9
#define NAO 10
#define MANUTENCAO 11

#include <iostream>
#include <string>

using namespace std;

//Classe da Interface Embarcada
class EmbeddedInterface{
  int display;
public:
  EmbeddedInterface();
  ~EmbeddedInterface();
  void displayMessage(string message);
};
