//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//Drink.h

class Drink{
  string name;
  int price;
public:
  Drink();
  Drink(string, int);
  ~Drink();
  int getPrice();
  string getName();
  void setPrice(int);
  void setName(string);
};
