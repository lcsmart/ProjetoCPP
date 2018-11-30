// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Drink.cpp

#include "Drink.h"

//construtor das bebidas
Drink::Drink(string newName, int newPrice) {
  price = newPrice;
  name = newName;
}
//destrutor
Drink::~Drink() {}

// retorna o preço
int Drink::getPrice() { return price; }

//retorna o nome
string Drink::getName() { return name; }

//atualiza o preço
void Drink::setPrice(int newPrice) { price = newPrice; }

//atualiza o nome
void Drink::setName(string newName) { name = newName; }
