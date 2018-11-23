//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//Stock.h

class Stock{
  Drink *Ertips = new Drink(Ertips, 150);
  Drink *Meet = new Drink(Meet, 150);
  int meetCount;
  int ertipsCount;

public:
  void addMeet(int);
  void removeMeet();
  int getMeetCount();

  void addEtirps(int);
  void removeEtirps();
  int getErtipsCount();
};
