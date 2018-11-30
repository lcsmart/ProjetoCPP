// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// VendingMachine.cpp

#define TERMINALLINUX
//#define EMBEDDEDTERMINAL

#define TEMPOANUNCIO 1
#define TEMPOTEMPO 1

#include <sys/file.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <lcd.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <time.h>
#include <wiringPi.h>

using namespace std;

#include "OutputInterface.cpp"

#ifdef TERMINALLINUX
#include "TerminalInterface.cpp"
#endif
#ifdef EMBEDDEDTERMINAL
#include "EmbeddedInterface.cpp"
#endif

#include "Stock.cpp"

#include "AdvertisingDisplay.cpp"

#include "FSMList.cpp"

void adOptions();
void addAd();
void removeAd();
void showAds();
char readInput();

void areYouSure();

void stockOptions();
void addEtirps();
void addMeet();
void removeEtirps();
void removeMeet();
void showStock();
void maintenance();

#ifdef TERMINALLINUX
TerminalInterface *OutInterface = new TerminalInterface();
#endif
#ifdef EMBEDDEDTERMINAL
EmbeddedInterface *OutInterface = new EmbeddedInterface();
#endif

List *fsm = new List(OutInterface);

AdvertisingDisplay<string> *Fila1 = new AdvertisingDisplay<string>(OutInterface);

AdvertisingList<string> *Fila2 = new AdvertisingList<string>();

int change;
int state;

AdvertisingNode<string> *address1;
AdvertisingNode<string> *address2;
AdvertisingNode<string> *ptrFunc;

main() {
  stringstream intStr;
  while (1) {
    char input = readInput();
    switch (input) {
    case 'a': // Moeda 25
      change = fsm->entradaM025();
      state = fsm->getEstadoAtual();
      if (change == 0) {
        intStr.str("");
        intStr << "Moeda Computada" << endl << "Saldo: " << state;
        OutInterface->displayMessage(intStr.str());
      } else {
        intStr.str("");
        intStr << "Troco: " << change << endl << "Saldo: " << state;
        OutInterface->displayMessage(intStr.str());
      }
      break;

    case 'b': // Moeda 50
      change = fsm->entradaM050();
      state = fsm->getEstadoAtual();
      if (change == 0) {
        intStr.str("");
        intStr << "Moeda Computada" << endl << "Saldo: " << state;
        OutInterface->displayMessage(intStr.str());
      } else {
        intStr.str("");
        intStr << "Troco: " << change << endl << "Saldo: " << state;
        OutInterface->displayMessage(intStr.str());
      }
      break;

    case 'c': // Moeda 100
      change = fsm->entradaM100();
      state = fsm->getEstadoAtual();
      if (change == 0) {
        intStr.str("");
        intStr << "Moeda Computada" << endl << "Saldo: " << state;
        OutInterface->displayMessage(intStr.str());
      } else {
        intStr.str("");
        intStr << "Troco: " << change << endl << "Saldo: " << state;
        OutInterface->displayMessage(intStr.str());
      }
      break;

    case 'D': // Devolucao
      change = fsm->entradaDEV();
      cout << fsm->getEstadoAtual();
      intStr.str("");
      intStr << "Valor devolvido: " << change << endl;
      OutInterface->displayMessage(intStr.str());
      usleep(2000000);
      break;

    case 'E': // Ertips
    if(fsm->getEtirpsCount() > 0){
      fsm->entradaETIRPS();
    }
    else     {  OutInterface->displayMessage("Não há Etirps em estoque");
    usleep(2000000);
  }
      break;

    case 'M': // Meet
    if(fsm->getMeetCount() > 0){
      fsm->entradaMEET();
    }
        else  {  OutInterface->displayMessage("Não há Meets em estoque");
        usleep(2000000);
      }
      break;

    case 'F': // AtualizarFila
      address1 = Fila1->getLastnodeaddress();
      address2 = Fila2->getFirstnodeaddress();
      Fila1->updateNodeAddress(address1, address2);
      Fila1->organizePosition();
      Fila2->updateHead();
      break;

    case 'R': // RemoverItemDaFila
      areYouSure();
      break;

    case 'O': // Manutencao
      maintenance();
      break;

    default:
      if (fsm->getEstadoAtual() == 0){
                Fila1->showAd();
              }
      break;
    }
  }
}

// MENU DE MANUTENCAO
void maintenance() {
  bool open = 1;
  int option = 0;
  while (open) {

    // Menu de Opções
    cout << endl
         << "Menu Principal (Manutencao)" << endl
         << "_____________________________________________" << endl;
    cout << "1 - Propagandas" << endl
         << "2 - Estoque" << endl
         << "3 - Concluir Manutencao" << endl;

    // Entrada do usuario
    cin >> option;

    // Selecao
    switch (option) {
    case 1:
      adOptions();
      break;

    case 2:
      stockOptions();
      break;

    default:
      open = 0;
      break;
    }
  }
}

// MENU DE ESTOQUE
void stockOptions() {
  bool stockOpen = 1;
  int option = 0;
  while (stockOpen) {
    // Sub Menu
    cout << endl << "MENU DE ESTOQUE" << endl << "==================" << endl;
    cout << "1 - Adicionar Refrigerante Etirps" << endl
         << "2 - Adicionar Refrigerante Meet" << endl
         << "3 - Consultar Estoque" << endl
         << "4 - Voltar" << endl;

    // Entrada do usuario
    cin >> option;

    // Selecao
    switch (option) {
    case 1:
      addEtirps();
      break;

    case 2:
      addMeet();
      break;

    case 3:
      showStock();
      break;

    default:
      stockOpen = 0;
      break;
    }
  }
}
void addEtirps() {
  cout << "Quantos Etirps foram adicionados?" << endl;
  int etirpsCount;
  cin >> etirpsCount;
  fsm->addEtirps(etirpsCount);
}
void addMeet() {
  cout << "Quantos Meets foram adicionados?" << endl;
  int meetsCount;
  cin >> meetsCount;
  fsm->addMeet(meetsCount);
}
void showStock() {
  cout << "No momento existem " << fsm->getEtirpsCount() << " Etirps e "
       << fsm->getMeetCount() << " Meets em estoque." << endl;
}

// MENU DE PROPAGANDAS
void adOptions() {
  bool adOpen = 1;
  int option = 0;
  while (adOpen) {
    // Sub Menu
    cout << endl
         << "MENU DE PROPAGANDAS" << endl
         << "______________________________________" << endl;
    cout << "1 - Adicionar Propaganda a fila 2" << endl
         << "2 - Remover Ultima Propaganda da fila 2" << endl
         << "3 - Exibir propagandas na fila 2" << endl
         << "4 - Voltar" << endl;

    // Entrada do usuario
    cin >> option;

    // Selecao
    switch (option) {
    case 1:
      addAd();
      break;

    case 2:
      removeAd();
      break;

    case 3:
      showAds();
      break;

    default:
      adOpen = 0;
      break;
    }
  }
}

void addAd() {
  cout << endl << "Entre com a nova propaganda" << endl;
  string advertising;
  cin.ignore();
  getline(std::cin, advertising);
  ptrFunc = new AdvertisingNode<string>();
  ptrFunc->setAdvertising(advertising);
  Fila2->insertionNode(ptrFunc);
}
void removeAd() {
  cout << "Ultima propaganda removida" << endl;
  Fila2->removeLastnode();
}
void showAds() {
  cout << endl << "Fila 2: " << endl;
  Fila2->listAll();
}

char readInput() {
  char input = 0;
#ifdef TERMINALLINUX
  fstream myfile;
  myfile.open("inputs.txt");
  if (myfile.is_open()) {
    usleep(1000);
    myfile.get(input);
    // myfile << 0 << endl;
    myfile.close();
    ofstream clearFile;
    clearFile.open("inputs.txt", std::ofstream::out | std::ofstream::trunc);
    clearFile.close();
    //remove("inputs.txt");
  }

  //else
  //  cout << "Erro no arquivo" << endl;

/*  int readStateFile = open("inputs.txt", O_RDONLY, 0x777);
  if(flock(readStateFile, LOCK_EX) == 0){
  read(readStateFile, &input, 1);
  flock(readStateFile, LOCK_UN);
  close(readStateFile);
  remove("inputs.txt");
  cout << "Input: " << input << endl;
}*/
#endif

#ifdef EMBEDDEDTERMINAL
  bool moeda25, moeda50, moeda100, devolver, etirps, meet, atualizarfila,
      removeranuncio, sim, nao, manutencao;

  if (moeda100 != (moeda100 = digitalRead(MOEDA100))) {
    if (moeda100)
      input = 'c';
  } else if (moeda50 != (moeda50 = digitalRead(MOEDA50))) {
    if (moeda50)
      input = 'b';
  } else if (moeda25 != (moeda25 = digitalRead(MOEDA25))) {
    if (moeda25)
      input = 'a';
  } else if (devolver != (devolver = digitalRead(DEVOLVER))) {
    if (devolver)
      input = 'D';
  } else if (etirps != (etirps = digitalRead(ETIRPS))) {
    if (etirps)
      input = 'E';
  } else if (meet != (meet = digitalRead(MEET))) {
    if (meet)
      input = 'M';
  } else if (atualizarfila != (atualizarfila = digitalRead(ATUALIZARFILA))) {
    if (atualizarfila)
      input = 'F';
  } else if (removeranuncio != (removeranuncio = digitalRead(REMOVERANUNCIO))) {
    if (removeranuncio)
      input = 'R';
  } else if (sim != (sim = digitalRead(SIM))) {
    if (sim)
      input = 'Y';
  } else if (nao != (nao = digitalRead(NAO))) {
    if (nao)
      input = 'N';
  } else if (manutencao != (manutencao = digitalRead(MANUTENCAO))) {
    if (manutencao)
      input = 'O';
  }
#endif
  return input;
}

void areYouSure() {
  cout << "Você tem certeza que deseja deletar a propaganda: "
       << Fila1->getLastNode() << "?" << endl;
  char answer = 0;
  while (!answer)
    answer = readInput();
  switch (answer) {
  case 'Y':
    Fila1->removeLastnode();
    break;
  default:
    break;
  }
}
