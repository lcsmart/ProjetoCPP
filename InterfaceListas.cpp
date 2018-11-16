/*
   Arquivo Interface.cpp
   Advertising
 */

#include "List.cpp"

int main() {

  List *Fila1 = new List();
  List *Fila2 = new List();
  Node *ptrFunc;
  Node *address1;
  Node *address2;
  bool sai = false;
  int opcao;
  string advertising;
  int count = 0;
  while (!sai) {
    // menu de opcoes
    cout << endl << "Propagandas" << endl << "==================" << endl;
    cout << "1 - Incluir Propaganda na Fila 2" << endl
         << "2 - Remover Propaganda da Fila 2" << endl
         << "3 - Remover Propaganda da Fila 1" << endl
         << "4 - Transferir Fila 2 para Fila 1" << endl
         << "5 - Trocar posição do Ultimo com a do Primeiro da Fila 1" << endl
         << "6 - Exibir a lista" << endl
         << "7 - Fim do programa" << endl
         << "Opcao? ";

    cin >> opcao;

    switch (opcao) {
    // Inclui Propaganda na fila
    case 1:
      cout << endl << "Propaganda: ";
      cin.ignore();
      getline(std::cin, advertising);
      ptrFunc = new Node();
      ptrFunc->setAdvertising(advertising);
      Fila2->insertionNode(ptrFunc);
      break;
    // Remove Propaganda na fila
    case 2:
      if (!Fila2->removeLastnode(count)) {
        count = 0;
        cout << endl
             << "Erro!!! Remocao nao realizada" << endl
             << "Lista vazia" << endl;
      } else {
        count = 0;
        cout << endl
             << "Propaganda " << Fila2->getNumElem() + 1 << " removida" << endl;
      }
      break;

    case 3:
      if (!Fila1->removeLastnode(count)) {
        count = 0;
        cout << endl
             << "Erro!!! Remocao nao realizada" << endl
             << "Lista vazia" << endl;
      } else {
        cout << endl
             << "Propaganda " << Fila1->getNumElem() + 1 << " removida" << endl;
        count = 0;
      }
      break;

    case 4:
      address1 = Fila1->getLastnodeaddress();
      address2 = Fila2->getFirstnodeaddress();
      count = Fila2->getNumElem();
      Fila1->updateNodeaddress(address1, address2);
      Fila1->organizePosition();
      Fila2->updateHead();
      break;
    case 5:
      Fila1->switchLasttofirst();
      break;
    // Exibe a Lista de Propagandas
    case 6:
      cout << "Fila 1: " << endl;
      Fila1->listAll();
      cout << endl << "Fila 2: " << endl;
      Fila2->listAll();
      break;

    // Fim do programa
    case 7:
      sai = true;
      break;

    default:
      cout << endl << "Erro: opcao invalida!" << endl;
    }
  }

  return 0;
}
