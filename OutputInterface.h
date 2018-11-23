//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//OutputInterface.h

class OutputInterface {
public:
  OutputInterface();
  ~OutputInterface();
  virtual void displayMessage() = 0;
};
