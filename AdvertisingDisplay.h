//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingDisplay.h

class AdvertisingDisplay: public AdvertisingList{

  TerminalInterface *OutInt;
  //EmbeddedInterface *OutInt;

  int countAdTime;
  int counter;
  time_t timer, lastTimer;
public:
  AdvertisingDisplay(TerminalInterface*);
  //AdvertisingDisplay(EmbeddedInterface*);
  ~AdvertisingDisplay();
  void showAd();
};
