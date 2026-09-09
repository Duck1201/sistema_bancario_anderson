#include <iostream>
#include <array>

using namespace std;

int main() {
    int numeroConta, tipoConta;
    string nomeCliente, cpf;
    double saldo;
    bool contaAtiva;
    int operacao = 0;

    while (true) {
        cout << "********************************" << endl;
        cout << "** BANCO INF101 **" << endl;
        cout << "********************************" << endl;

        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Consultar conta" << endl;
        cout << "3 - Verificar saldo" << endl;
        cout << "4 - Alterar tipo da conta" << endl;
        cout << "5 - Ativar/Desativar conta" << endl;
        cout << "6 - Sair" << endl;
        cout << "Operação: ";
        cin >> operacao;    
    
    while(operacao > 6 || operacao < 1) {
        cout << "Operação invalida escolha entre 1 e 6: ";
        cin >> operacao;
    }

    if(operacao == 6) {
        break;
    }
    
    cin.ignore();

    switch (operacao) {
    case 1:
        cout << "Qual o nome do titular da conta? ";
        getline(cin, nomeCliente);

        cout << "Qual o número da conta? ";
        cin >> numeroConta;    
        
        while (numeroConta < 0) {
            cout << "ERROR! Número invalido, adicione um numero maior que 0: ";
            cin >> numeroConta;
        }

        cin.ignore();
        cout << "Qual o CPF do titular? ";
        getline(cin, cpf);

        cout << "Qual o tipo da conta? ";
        cin >> tipoConta;
        
        while (tipoConta < 0) {
            cout << "ERROR! Tipo de conta invalido, escolha entre os tipos 1 e 2: ";
            cin >> tipoConta;
        }

        cout << "Qual o saldo inicial? ";
        cin >> saldo;

        while (saldo < 0) {
            cout << "ERROR! Saldo invalido, adicione um saldo maior que 0: ";
            cin >> saldo;
        }
        
        break;
        
    case 2:
        /* code */
        break;

    case 3:
        /* code */
        break;
    
    case 4:
        /* code */
        break;

    case 5:
        /* code */
        break;

    case 6:
        /* code */
        break;
    
    default:
        break;
    }
}

    return 0;
}