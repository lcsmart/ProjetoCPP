// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Stock.cpp
#include "Drink.cpp"
#include "Stock.h"

Stock::Stock() {
  Ertips = new Drink("Ertips", 150);
  Meet = new Drink("Meet", 150);
}

Stock::~Stock() {
  delete Ertips;
  delete Meet;
}

void Stock::addMeet(int newMeets) { meetCount = meetCount + newMeets; }

void Stock::removeMeet() { meetCount--; }

int Stock::getMeetCount() { return meetCount; }

void Stock::addEtirps(int newEtirps) { ertipsCount = ertipsCount + newEtirps; }

void Stock::removeEtirps() { ertipsCount--; }

int Stock::getErtipsCount() { return ertipsCount; }
