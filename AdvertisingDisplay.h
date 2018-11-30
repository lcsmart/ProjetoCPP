//UFSC 2018.2
//C++ para Sistemas Embarcados
//Lucas Martins e Rafael Valente
//Projeto Final - Vending Machine
//AdvertisingDisplay.h

//Classe que controla a exibicao de propagandas no display
template<typename T>
class AdvertisingDisplay: public AdvertisingList<T>{
  #ifdef TERMINALLINUX
  TerminalInterface *OutInt;
  #endif
  #ifdef EMBEDDEDTERMINAL
  EmbeddedInterface *OutInt;
  #endif
  int countAdTime;
  int counter;
  time_t timer, lastTimer;
public:
  #ifdef TERMINALLINUX
  AdvertisingDisplay(TerminalInterface*);
  #endif
  #ifdef EMBEDDEDTERMINAL
  AdvertisingDisplay(EmbeddedInterface*);
  #endif
  ~AdvertisingDisplay();
  void showAd();
};
