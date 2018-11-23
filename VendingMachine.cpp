// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// VendingMachine.cpp

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

#include "OutputInterface.cpp"

#include "TerminalInterface.cpp"

#include "Stock.cpp"

#include "AdvertisingDisplay.cpp"

#include "FSMList.cpp"

void adOptions();
void addAd();
void removeAd();
void showAds();

void stockOptions();
void addEtirps();
void addMeet();
void removeEtirps();
void removeMeet();
void showStock();
void maintenance();

//#ifdef PC
TerminalInterface *OutInterface = new TerminalInterface();
//#endif

List *fsm = new List(OutInterface);
Stock currentStock;

AdvertisingDisplay *Fila1 = new AdvertisingDisplay(OutInterface);
AdvertisingList *Fila2 = new AdvertisingList();

int change;
int state;

AdvertisingNode *address1;
AdvertisingNode *address2;
AdvertisingNode *ptrFunc;

main() {

  while (1) {
    char input = 0;
    ifstream readStateFile;
    readStateFile.open("inputs.txt", ios::in);

    if (readStateFile.is_open()) {
      input = readStateFile.get();
      readStateFile.close();
      cout << "Input: " << input << endl;
      remove("inputs.txt");
    }



    switch (input) {

    case 'a': // Moeda 25
      change = fsm->entradaM025();
      state = fsm->getEstadoAtual();
      if (change == 0) {
        cout << "Moeda computada" << endl;
      } else {
        cout << "Troco:" << change << endl;
      }
      cout << "Estado Atual: " << state << endl;
      break;

    case 'b': // Moeda 50
      change = fsm->entradaM050();
      state = fsm->getEstadoAtual();
      if (change == 0) {
        cout << "Moeda computada" << endl;
      } else {
        cout << "Troco:" << change << endl;
      }
      cout << "Estado Atual: " << state << endl;
      break;

    case 'c': // Moeda 100
      change = fsm->entradaM100();
      state = fsm->getEstadoAtual();
      if (change == 0) {
        cout << "Moeda computada" << endl;
      } else {
        cout << "Troco:" << change << endl;
      }
      cout << "Estado Atual: " << state << endl;
      break;

    case 'D': // Devolucao
      change = fsm->entradaDEV();
      state = fsm->getEstadoAtual();
      cout << "Valor devolvido: " << change << endl;
      cout << "Estado Atual: " << state << endl;
      break;

    case 'E': // Ertips
      fsm->entradaETIRPS();
      state = fsm->getEstadoAtual();
      cout << "Estado Atual: " << state << endl;
      break;

    case 'M': // Meet
      fsm->entradaMEET();
      state = fsm->getEstadoAtual();
      cout << "Estado Atual: " << state << endl;
      break;

    case 'F': // AtualizarFila
      address1 = Fila1->getLastnodeaddress();
      address2 = Fila2->getFirstnodeaddress();
      Fila1->updateNodeAddress(address1, address2);
      Fila1->organizePosition();
      Fila2->updateHead();
      break;

    case 'R': // RemoverItemDaFila
      break;

    case 'Y': // Sim
      break;

    case 'N': // Nao
      break;

    case 'O': // Manutencao
      maintenance();
      break;

    default:
      Fila1->showAd();
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
         << "4 - Consultar Estoque" << endl
         << "5 - Voltar" << endl;

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

    case 4:
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
  currentStock.addEtirps(etirpsCount);
}
void addMeet() {
  cout << "Quantos Meets foram adicionados?" << endl;
  int meetsCount;
  cin >> meetsCount;
  currentStock.addMeet(meetsCount);
}
void showStock() {
  cout << "No momento existem " << currentStock.getEtirpsCount() << " Etirps e "
       << currentStock.getMeetCount() << " Meets em estoque." << endl;
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
         << "2 - Remover Propagandas da fila 2" << endl
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
  ptrFunc = new AdvertisingNode();
  ptrFunc->setAdvertising(advertising);
  Fila2->insertionNode(ptrFunc);
}
void removeAd() { cout << "Remover propagandas*" << endl; }
void showAds() {
  cout << endl << "Fila 2: " << endl;
  Fila2->listAll();
}
