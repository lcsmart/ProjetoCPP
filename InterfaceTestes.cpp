// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// InterfaceTestes.cpp

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace std;

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

void inputOptions();

void writeToFile(char);

int main() {
  bool open = 1;
  int option = 0;
  while (open) {

    // Menu de Opções
    cout << endl
         << "Escolha o que deve ser testado" << endl
         << "==================" << endl;
    cout << "1 - Propagandas" << endl
         << "2 - Estoque" << endl
         << "3 - Botoes e sensores" << endl
         << "4 - Fechar o programa" << endl;

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

    case 3:
      inputOptions();
      break;

    default:
      open = 0;
      break;
    }
  }
}

// MENU DE PROPAGANDAS
void adOptions() {
  bool adOpen = 1;
  int option = 0;
  while (adOpen) {
    // Sub Menu
    cout << endl
         << "MENU DE PROPAGANDAS" << endl
         << "==================" << endl;
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
void addAd() { cout << "Adicionar propagandas*" << endl; };
void removeAd() { cout << "Remover propagandas*" << endl; };
void showAds() { cout << "Exibir propagandas*" << endl; };

// MENU DE ESTOQUE
void stockOptions() {
  bool stockOpen = 1;
  int option = 0;
  while (stockOpen) {
    // Sub Menu
    cout << endl << "MENU DE ESTOQUE" << endl << "==================" << endl;
    cout << "1 - Adicionar Refrigerante Etirps" << endl
         << "2 - Adicionar Refrigerante Meet" << endl
         << "3 - Remover Refrigerante Etirps" << endl
         << "4 - Remover Refrigerante Meet" << endl
         << "5 - Consultar Estoque" << endl
         << "6 - Voltar" << endl;

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
      removeEtirps();
      break;

    case 4:
      removeMeet();
      break;

    case 5:
      showStock();
      break;

    default:
      stockOpen = 0;
      break;
    }
  }
}
void addEtirps() { cout << "Etirps adicionado*" << endl; }
void addMeet() { cout << "Meet adicionado*" << endl; }
void removeEtirps() { cout << "Etirps removido*" << endl; }
void removeMeet() { cout << "Meet removido*" << endl; }
void showStock() { cout << "Exibir Estoque*" << endl; }

// MENU DE ENTRADAS
void inputOptions() {
  bool inputOpen = 1;
  int option = 0;
  while (inputOpen) {
    // Sub Menu
    cout << endl
         << "MENU DE ENTRADAS" << endl
         << "==================" << endl
         << "1 - MOEDA 25" << endl
         << "2 - MOEDA 50" << endl
         << "3 - MOEDA 100" << endl
         << "4 - DEVOLUCAO" << endl
         << "5 - ETIRPS" << endl
         << "6 - MEET" << endl
         << "7 - ATUALIZAR FILA" << endl
         << "8 - REMOCAO" << endl
         << "9 - SIM" << endl
         << "10 - NAO" << endl
         << "11 - Voltar" << endl;

    // Entrada do usuario
    cin >> option;

    // Selecao
    switch (option) {
    case 1:
      writeToFile('a');
      break;

    case 2:
      writeToFile('b');
      break;

    case 3:
      writeToFile('c');
      break;

    case 4:
      writeToFile('D');
      break;

    case 5:
      writeToFile('E');
      break;
    case 6:
      writeToFile('M');
      break;
    case 7:
      writeToFile('F');
      break;
    case 8:
      writeToFile('R');
      break;
    case 9:
      writeToFile('Y');
      break;
    case 10:
      writeToFile('N');
      break;

    default:
      inputOpen = 0;
      break;
    }
  }
}

void writeToFile(char input) {
  ofstream outfile;
  outfile.open("inputs.txt", ios::trunc);
  outfile << input << endl;
  outfile.close();
}
