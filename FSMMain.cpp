

#include "FSMList.cpp"

int main() {
  List fsm;
  bool sai = false;
  int change;
  int opcao;
  int state;
  while (!sai) {
    // menu de opcoes
    cout << endl << endl << "Opções: " << endl << "==================" << endl;
    cout << "1 - Colocar moeda de 25 centavos" << endl
         << "2 - Colocar moeda de 50 centavos" << endl
         << "3 - Colocar moeda de 1 real" << endl
         << "4 - Reembolso" << endl
         << "5 - Comprar refrigerante MEET" << endl
         << "6 - Comprar refrigerante ETIRPS" << endl
         << "7 - Fechar Programa" << endl
         << endl
         << endl;

    cin >> opcao;
    cout << endl << endl << endl << endl << endl;

    switch (opcao) {
    // Moeda 25
    case 1:
      change = fsm.entradaM025();
      state = fsm.getEstadoAtual();
      if (change == 0) {
        cout << "Moeda computada" << endl;
      } else {
        cout << "Troco:" << change << endl;
      }
      cout << "Estado Atual: " << state << endl;
      break;

    // Moeda 50
    case 2:
      change = fsm.entradaM050();
      state = fsm.getEstadoAtual();
      if (change == 0) {
        cout << "Moeda computada" << endl;
      } else {
        cout << "Troco:" << change << endl;
      }
      cout << "Estado Atual: " << state << endl;
      break;

    // Moeda 100
    case 3:
      change = fsm.entradaM100();
      state = fsm.getEstadoAtual();
      if (change == 0) {
        cout << "Moeda computada" << endl;
      } else {
        cout << "Troco:" << change << endl;
      }
      cout << "Estado Atual: " << state << endl;
      break;

    // Reembolso
    case 4:
      change = fsm.entradaDEV();
      state = fsm.getEstadoAtual();
      cout << "Valor devolvido: " << change << endl;
      cout << "Estado Atual: " << state << endl;
      break;

    // MEET
    case 5:
      fsm.entradaMEET();
      state = fsm.getEstadoAtual();
      cout << "Estado Atual: " << state << endl;
      break;

    case 6:
      fsm.entradaETIRPS();
      state = fsm.getEstadoAtual();
      cout << "Estado Atual: " << state << endl;
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
