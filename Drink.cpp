// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Drink.cpp

#include "Drink.h"

Stock::Drink(string newName, int newPrice) {
  price = newPrice;
  name = newName;
}

Stock::~Drink() {}

int Stock::getPrice(){
  return price;
}

string Stock::getName(){
  return string;
}

void Stock::setPrice(int newPrice){
  price = newPrice;
}

void Stock::setName(string newName){
  name = newName;
}
