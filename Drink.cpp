// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Drink.cpp

#include "Drink.h"

Drink::Drink(string newName, int newPrice) {
  price = newPrice;
  name = newName;
}

Drink::~Drink() {}

int Drink::getPrice() { return price; }

string Drink::getName() { return name; }

void Drink::setPrice(int newPrice) { price = newPrice; }

void Drink::setName(string newName) { name = newName; }
