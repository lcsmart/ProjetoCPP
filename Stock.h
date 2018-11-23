// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Stock.h

class Stock {
  Drink *Ertips;
  Drink *Meet;
  int meetCount;
  int ertipsCount;

public:
  Stock();
  ~Stock();
  void addMeet(int);
  void removeMeet();
  int getMeetCount();

  void addEtirps(int);
  void removeEtirps();
  int getErtipsCount();
};
