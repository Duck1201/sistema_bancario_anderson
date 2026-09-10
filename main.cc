#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int numeroConta, tipoConta;
    string nomeCliente, cpf;
    double saldo;
    bool contaAtiva;
    int operacao = 0;
    
    struct Client {
        int numeroConta;
        int tipoConta;
        string nomeCliente;
        string cpf;
        double saldo;
        bool contaAtiva;
    };
    
    vector<Client> clientes;

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

    while(true) {
        if(cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "ERRO! Digite um numero" << endl;
            continue;
        }

        if(operacao > 6 || operacao < 1) {
            cout << "ERRO! Operação invalida escolha um numero entre 1 e 6: ";
            cin >> operacao;
            continue;;
        }

        break;
    }

    if(operacao == 6) {
        break;
    }

    switch (operacao) {
    case 1:
        cin.ignore();

        cout << "Qual o nome do titular da conta? ";
        getline(cin, nomeCliente);

        cout << "Qual o número da conta? ";
        cin >> numeroConta;    
        
        while (true) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
            
                cout << "ERRO! Digite um numero" << endl;
                continue;
            }

            if (numeroConta < 0) {
                cout << "ERRO! Número invalido, adicione um numero maior que 0: ";
                cin >> numeroConta;
                break;
            }
            
            break;
        }

        cout << "Qual o CPF do titular? ";
        getline(cin, cpf);


        cout << "Qual o tipo da conta? ";
        cin >> tipoConta;
        

                
        while (true) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
            
                cout << "ERRO! Digite um numero" << endl;
                continue;
            }

            if (tipoConta < 0) {
                cout << "ERRO! Tipo de conta invalido, escolha entre os tipos 1 e 2: ";
                cin >> tipoConta;
                break;
            }

            break;
        }

        cout << "Qual o saldo inicial? ";
        cin >> saldo;
        
        while (true) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
            
                cout << "ERRO! Digite um numero" << endl;
                continue;
            }

            if (saldo < 0) {
                cout << "ERRO! Saldo invalido, adicione um saldo maior que 0: ";
                cin >> saldo;
                break;
            }

            break;
        }

        clientes.push_back({numeroConta, tipoConta, nomeCliente, cpf, saldo, contaAtiva});
        break;
        
    case 2:
        if(!clientes.data()) {
            cout << endl;
            cout << "Sem clientes cadastrados!" << endl;
            cout << endl;
            break;    
        }

        cout << "********************************" << endl;
        cout << "** BANCO INF101 **" << endl;
        cout << "**   CLIENTES   **" << endl;
        cout << "********************************" << endl;

        int controle;

        for (int i = 0; i < clientes.size(); i++) {
            cout << "Cliente " << i + 1 << ": " << clientes[i].nomeCliente << endl;
            cout << endl;
        }
            
        cout << "1 - Sair" << endl;
        cout << "Operação: "; cin >> controle;

        while (true) {
            if(cin.fail()) {
                cin.clear();
                cin.ignore();
            
                cout << "ERRO! Digite um numero" << endl;
                continue;
            }

            if (tipoConta != 1) {
                cout << "ERRO!  Operação invalida, tente 1";
                cin >> operacao;
                break;
            }

            break;
        }

        if(controle == 1) {
            break;
        }

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