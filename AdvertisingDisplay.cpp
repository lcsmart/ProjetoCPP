// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// AdvertisingDisplay.cpp

#include "AdvertisingList.cpp"
#include "AdvertisingDisplay.h"

//Construtor para Interface Terminal
#ifdef TERMINALLINUX
template<typename T>
AdvertisingDisplay<T>::AdvertisingDisplay(TerminalInterface *NewOutInt) {
  OutInt = NewOutInt;
  time(&lastTimer);
  counter = 0;
  countAdTime = 1;
}
#endif
//Construtor para Interface Embarcada
#ifdef EMBEDDEDTERMINAL
template<typename T>
AdvertisingDisplay<T>::AdvertisingDisplay(EmbeddedInterface *NewOutInt) {
  OutInt = NewOutInt;
  time(&lastTimer);
  counter = 0;
  countAdTime = 1;
}
  #endif

template<typename T>
AdvertisingDisplay<T>::~AdvertisingDisplay() {}

//Funcao que exibe os anuncios na interface
template<typename T>
void AdvertisingDisplay<T>::showAd() {
  if(AdvertisingList<T>::getNumElem()>0){
  time(&timer);
  if (difftime(timer, lastTimer) >= 1) {
    countAdTime--;
    if (((counter == 3 && random() % 4 == 0) ||
        (counter == 4 && random() % 3 == 0) || (counter == 5 && random() % 2 ==0) || (counter ==6)) && countAdTime == 0) {
          counter = 0;
          countAdTime = TEMPOTEMPO;
          OutInt->displayMessage(asctime(localtime(&timer)));
    } else if (countAdTime == 0){
      counter++;
      OutInt->displayMessage(AdvertisingList<T>::getCurrentNode());
      AdvertisingList<T>::switchLasttofirst();
      countAdTime = TEMPOANUNCIO;
    }
    time(&lastTimer);
  }
}
else {
  time(&timer);
  if (difftime(timer, lastTimer) >= 1) {
    countAdTime--;
    if (countAdTime == 0) {
          countAdTime = TEMPOTEMPO;
          time(&lastTimer);
          OutInt->displayMessage(asctime(localtime(&timer)));
    }
          time(&lastTimer);
  }
}
}
