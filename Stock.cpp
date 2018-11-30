// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Stock.cpp
#include "Drink.cpp"
#include "Stock.h"

//construtor com as bebidas que são disponiveis na máquina
Stock::Stock() {
  Etirps = new Drink("Etirps", 150);
  Meet = new Drink("Meet", 150);
  meetCount = 0;
  etirpsCount = 0;
}

//destrutor
Stock::~Stock() {
  delete Etirps;
  delete Meet;
}

//adiciona uma quantidade de Meets ao estoque
void Stock::addMeet(int newMeets) { meetCount = meetCount + newMeets; }

//remove um meet do estoque
void Stock::removeMeet() { if(meetCount > 0)meetCount--;
else cout << "Nao ha meets em estoque" << endl; }

//retorna quantos meets há no estoque
int Stock::getMeetCount() { return meetCount; }

//adiciona uma quantidade de Etirps ao estoque
void Stock::addEtirps(int newEtirps) { etirpsCount = etirpsCount + newEtirps; }

//remove um Etirps do estoque
void Stock::removeEtirps() { if(etirpsCount>0)etirpsCount--;
else cout << "Nao ha etirps em estoque" << endl;}

//retorna quantos Etirps há no estoque
int Stock::getEtirpsCount() { return etirpsCount; }
