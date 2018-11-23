// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Stock.cpp
#include "Drink.cpp"
#include "Stock.h"

Stock::Stock() {
  Etirps = new Drink("Etirps", 150);
  Meet = new Drink("Meet", 150);
  meetCount = 0;
  etirpsCount = 0;
}

Stock::~Stock() {
  delete Etirps;
  delete Meet;
}

void Stock::addMeet(int newMeets) { meetCount = meetCount + newMeets; }

void Stock::removeMeet() { if(meetCount > 0)meetCount--;
else cout << "Nao ha meets em estoque" << endl; }

int Stock::getMeetCount() { return meetCount; }

void Stock::addEtirps(int newEtirps) { etirpsCount = etirpsCount + newEtirps; }

void Stock::removeEtirps() { if(etirpsCount>0)etirpsCount--;
else cout << "Nao ha etirps em estoque" << endl;}

int Stock::getEtirpsCount() { return etirpsCount; }
