// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// Stock.h

//classe que representa o estoque de bebidas
class Stock {
  Drink *Etirps;
  Drink *Meet;
  int meetCount;
  int etirpsCount;

public:
  Stock();
  ~Stock();
  void addMeet(int);
  void removeMeet();
  int getMeetCount();

  void addEtirps(int);
  void removeEtirps();
  int getEtirpsCount();
};
