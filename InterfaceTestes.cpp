// UFSC 2018.2
// C++ para Sistemas Embarcados
// Lucas Martins e Rafael Valente
// Projeto Final - Vending Machine
// InterfaceTestes.cpp

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sys/file.h>
#include <time.h>
#include <unistd.h>

using namespace std;

void writeToFile(char);

int main() {
  bool inputOpen = 1;
  int option = 0;
  while (inputOpen) {
    // MENU DE ENTRADAS
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
         << "11 - MANUTENCAO" << endl
         << "12 - Fechar Programa" << endl;

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

    case 11:
      writeToFile('O');
      break;

    default:
      inputOpen = 0;
      break;
    }
  }
  return 0;
}

//Escreve a Entrada selecionada no arquivo a ser lido pelo programa principal
void writeToFile(char input) {
  ofstream myfile ("inputs.txt", ios::trunc);
  if(myfile.is_open()){
    myfile << input << endl;
    myfile.close();
  }
  else cout << "Erro no arquivo" << endl;
}
