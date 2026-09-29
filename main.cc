#include <iostream>
#include <string>
#include <vector>

using namespace std;

int validarInput(string input) {
    int number;

    while (true) {
        cout << input;
        cin >> number;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();

            cout << "ERRO! Digite um numero" << endl;
        } else {
            return number;
        }
    }
}

int main() {
    int numeroConta, tipoConta, controle;
    string nomeCliente, cpf, cpfControle;
    double saldo;
    bool contaAtiva;

    struct Client {
        int numeroConta;
        int tipoConta;
        string nomeCliente;
        string cpf;
        double saldo;
        bool contaAtiva;
        void mostrar() {
            cout << endl;
            cout << "Numero da conta: " << numeroConta << endl;
            cout << "Tipo da conta: " << tipoConta << endl;
            cout << "Nome do cliente: " << nomeCliente << endl;
            cout << "CPF: " << cpf << endl;
            cout << "Saldo: " << saldo << endl;
            cout << "Status da Conta (0 - Desativado; 1 - Ativado): " << contaAtiva << endl;
            cout << endl;
        }
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
        controle = validarInput("Operação: ");

        while (controle > 6 || controle < 1) {
            controle = validarInput("ERRO! Operação invalida escolha um numero entre 1 e 6: ");
        }

        if (controle == 6) {
            break;
        }

        switch (controle) {
        case 1:
            contaAtiva = 0;
            cin.ignore();

            cout << "Qual o nome do titular da conta? ";
            getline(cin, nomeCliente);

            while (true) {
                numeroConta = validarInput("Qual o número da conta? ");

                while (numeroConta < 0) {
                    numeroConta = validarInput("ERRO! Número invalido, adicione um numero maior que 0: ");
                }

                break;
            }

            cin.ignore();

            cout << "Qual o CPF do titular? ";
            getline(cin, cpf);

            while (true) {
                tipoConta = validarInput("Qual o tipo da conta? ");

                while (tipoConta != 1 && tipoConta != 2) {
                    tipoConta = validarInput("ERRO! Tipo de conta invalido, escolha entre os tipos 1 e 2: ");
                }

                break;
            }

            while (true) {
                saldo = validarInput("Qual o saldo inicial? ");

                while (saldo < 0) {
                    saldo = validarInput("ERRO! Saldo invalido, adicione um saldo maior que 0: ");
                }

                break;
            }

            contaAtiva = 1;
            clientes.push_back({ numeroConta, tipoConta, nomeCliente, cpf, saldo, contaAtiva });
            break;

        case 2:
            if (!clientes.data()) {
                cout << endl;
                cout << "Sem clientes cadastrados!" << endl;
                cout << endl;
                break;
            }
            while (true) {

                cout << "********************************" << endl;
                cout << "** BANCO INF101 **" << endl;
                cout << "**   CLIENTES   **" << endl;
                cout << "********************************" << endl;

                cout << "1 - Exibir todos os clientes" << endl;
                cout << "2 - Procurar por um cliente" << endl;
                cout << "3 - Sair" << endl;
                controle = validarInput("Operação: ");

                while (controle < 1 && controle > 2) {
                    controle = validarInput("ERRO!  Operação invalida, tente 1: ");
                }

                if (controle == 1) {
                    for (int i = 0; i < clientes.size(); i++) {
                        cout << "Cliente " << i + 1 << ": " << endl;
                        clientes[i].mostrar();
                        cout << endl;
                    }
                } else if (controle == 2) {
                    cin.ignore();

                    cout << "Qual o CPF do titular da conta? ";
                    getline(cin, cpfControle);

                    for (int i = 0; i < clientes.size(); i++) {
                        if (clientes[i].cpf == cpfControle) {
                            clientes[i].mostrar();
                        }
                    }
                } else {
                    break;
                }
            }

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