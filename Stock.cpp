// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Stock.cpp

#include "Stock.h"
#include "Drink.cpp"

Stock::Stock() {}

Stock::~Stock() {}

void addMeet(int newMeets){
  meetCount = meetCount+newMeets;
}

void removeMeet(){
  meetCount--;
}

int getMeetCount(){
  return meetCount;
}

void addEtirps(int newEtirps){
  EtirpsCount = EtirpsCount+newEtirps;
}

void removeEtirps(){
  EtirpsCount--;
}

int getEtirpsCount(){
  return EtirpsCount;
}
