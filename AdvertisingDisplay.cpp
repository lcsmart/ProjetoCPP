// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// AdvertisingDisplay.cpp

#include "AdvertisingList.cpp"
#include "AdvertisingDisplay.h"


AdvertisingDisplay::AdvertisingDisplay(TerminalInterface *NewOutInt) {
  OutInt = NewOutInt;
  time(&lastTimer);
  counter = 0;
  countAdTime = 1;
}

/*AdvertisingDisplay::AdvertisingDisplay(EmbeddedInterface *NewOutInt) {
  OutInt = NewOutInt;
  time(&lastTimer);
  counter = 0;
  countAdTime = 1;
}*/

AdvertisingDisplay::~AdvertisingDisplay() {}

void AdvertisingDisplay::showAd() {
  time(&timer);
  if (difftime(timer, lastTimer) > 1) {
    countAdTime--;
    if (((counter == 3 && random() % 4 == 0) ||
        (counter == 4 && random() % 3 == 0) || (counter == 5 && random() % 2 ==0) || (counter ==6)) && countAdTime == 0) {
          counter = 0;
          countAdTime = 1;
          time(&lastTimer);
          OutInt->displayMessage(asctime(localtime(&timer)));
    } else if (countAdTime == 0){
      counter++;
      OutInt->displayMessage(getCurrentNode());
      AdvertisingList::switchLasttofirst();
      countAdTime = 2;
      time(&lastTimer);
    }
  }
}
