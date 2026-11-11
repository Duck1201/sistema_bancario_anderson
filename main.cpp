#include <iostream>
#include <set>
#include <stdexcept>
#include <thread>
using namespace std;

// Conta
// Controle
const int MAX_CONTAS = 100;
int quantidadeContas = 0;

//
int numeroConta[MAX_CONTAS];
string nomeCliente[MAX_CONTAS];
string cpf[MAX_CONTAS];
int tipoConta[MAX_CONTAS];
double saldo[MAX_CONTAS];
bool contaAtiva[MAX_CONTAS];

// Movimentações
// Controle
const int MAX_MOVIMENTACOES = 500;
int quantidadeMovimentacoes = 0;

//
int contaMovimentacao[MAX_MOVIMENTACOES];
char tipoMovimentacao[MAX_MOVIMENTACOES];
double valorMovimentacao[MAX_MOVIMENTACOES];

struct User {
    int numeroConta;
    string nomeCliente;
    string cpf;
    int tipoConta;
    double *saldo;
    bool *contaAtiva;
};

bool containNumbers(const string &str) {
    if (str.empty()) {
        return false;
    }

    for (char c : str) {
        if (isdigit(c)) {
            return true;
        }
    }

    return false;
}

int randomId(set<int> &num) {
    int random;
    int numSize = num.size();

    while (true) {
        random = (rand() % 101) + 1;
        num.insert(random);

        if (num.size() > numSize) {
            return random;
        }
    }
}

string cpfFmt(const string &cpf) {
    string validCpf;

    for (char c : cpf) {
        if (c != '.' && c != '-') {
            validCpf += c;
        }
    }

    return validCpf;
}

int numberInput(const string &input) {
    string value;
    while (true) {
        cout << input;
        getline(cin, value);

        try {
            return stoi(value);
        } catch (const exception) {
            cout << "[!] Erro: Número inválido!" << endl;
            return 0;
        }
    }
}

string textInput(const string &input) {
    string value;
    while (true) {
        cout << input;
        getline(cin, value);

        if (value.empty()) {
            cout << "[!] Erro: Texto inválido!" << endl;
        } else {
            return value;
        }
    }
}

char charInput(const string &input) {
    char value;
    while (true) {
        cout << input;
        cin >> value;

        if (!value) {
            cout << "[!] Erro: Texto inválido!" << endl;
        } else {
            return value;
        }
    }
}

void timeout(int time) {
    this_thread::sleep_for(chrono::milliseconds(time));
}

User findUser(const int &numero) {
    for (int i = 0; i < quantidadeContas; i++) {
        if (numeroConta[i] == numero) {
            return {
                numeroConta : numeroConta[i],
                nomeCliente : nomeCliente[i],
                cpf : cpf[i],
                tipoConta : tipoConta[i],
                saldo : &saldo[i],
                contaAtiva : &contaAtiva[i],
            };
        }
    }

    throw runtime_error("Número da conta inválido.");
}

int main() {
    // Controle interno
    int controle;
    int controleInterno;

    string cpfLimpo;
    string status;

    User cliente;
    User cliente2;
    set<int> numSet;

    while (true) {
        cout << "---- | --- Banco --- | ----" << endl;
        cout << "- | Contas adicionadas | -" << endl;
        cout << "---- | ----- " << quantidadeContas << " ----- | ----" << endl;
        cout << "" << endl;

        cout << "1. Cadastrar um usuário" << endl;
        cout << "2. Gerenciar contas" << endl;
        cout << "3. Movimentações" << endl;
        cout << "0. Sair" << endl;
        cout << "------- | ------- | -------" << endl;
        controle = numberInput("Escolha uma opção: ");

        switch (controle) {
        case 1:
            // Cadastrar conta
            if (quantidadeContas >= MAX_CONTAS) {
                cout << "Você não pode adicionar mais contas." << endl;
                break;
            }

            // Inputs
            nomeCliente[quantidadeContas] = textInput("Qual seu nome? ");

            cpf[quantidadeContas] = textInput("Qual seu CPF? ");
            cpfLimpo = cpfFmt(cpf[quantidadeContas]);

            while (cpfLimpo.length() < 11 || !containNumbers(cpfLimpo)) {
                cout << "CPF inválido. Por favor digite um valor númerico de 11 digitos." << endl;
                cout << "Digite um valor válido: " << endl;
                cin >> cpf[quantidadeContas];

                cpfLimpo = cpfFmt(cpf[quantidadeContas]);

                cin.ignore();
            }

            tipoConta[quantidadeContas] = numberInput("Qual o tipo da conta (1 | 2)? ");

            while (tipoConta[quantidadeContas] != 1 && tipoConta[quantidadeContas] != 2) {
                cout << "Tipo de conta inválido!" << endl;
                cout << "Digite um valor válido: ";
                cin >> tipoConta[quantidadeContas];

                cin.ignore();
            }

            // Padrões
            numeroConta[quantidadeContas] = randomId(numSet);
            saldo[quantidadeContas] = 0;

            cout << "Usuário cadastrado com sucesso!" << endl;
            cout << "Nome: " << nomeCliente[quantidadeContas] << endl;
            cout << "Número da conta: " << numeroConta[quantidadeContas] << endl;
            cout << "" << endl;

            // Controle
            contaAtiva[quantidadeContas] = true;
            quantidadeContas++;

            break;

        case 2:
            cout << "---- | --- Contas --- | ----" << endl;
            cout << "1. Listar as contas cadastradas." << endl;
            cout << "2. Consultar uma conta pelo número." << endl;
            cout << "3. Desativar conta." << endl;
            cout << "4. Ativar conta." << endl;
            cout << "" << endl;
            cout << "0. Voltar" << endl;
            cout << "------- | ------- | -------" << endl;
            controleInterno = numberInput("Escolha uma opção: ");

            int conta;

            switch (controleInterno) {
            case 1:
                // Buscar todas as contas
                if (!quantidadeContas) {
                    cout << "Antes de continuar adicione uma ou mais contas." << endl;
                    timeout(2000);
                    break;
                }

                for (int i = 0; i < quantidadeContas; i++) {
                    cout << "Número da conta: " << numeroConta[i] << endl;
                    cout << "Nome: " << nomeCliente[i] << endl;
                    cout << "CPF: " << cpf[i] << endl;
                    cout << "Saldo: " << saldo[i] << endl;
                    cout << "Tipo da conta: " << tipoConta[i] << endl;

                    status = contaAtiva[i] ? "Sim" : "Não";
                    cout << "Conta ativa: " << status << endl;
                    cout << "" << endl;
                }

                controleInterno = charInput("Sair (S): ");

                if (tolower(controleInterno) == 's') {
                    cin.ignore();
                    break;
                }

                cin.ignore();

                break;

            case 2:
                // Buscar uma conta
                conta = numberInput("Qual o número da conta? ");

                try {
                    cliente = findUser(conta);
                } catch (const exception &e) {
                    cout << "[!] Erro: Nenhum cliente foi encontrado\nMensagem: " << e.what() << endl;
                    timeout(1000);
                    break;
                }

                cout << "Número da conta: " << cliente.numeroConta << endl;
                cout << "Nome: " << cliente.nomeCliente << endl;
                cout << "CPF: " << cliente.cpf << endl;
                cout << "Saldo: " << *cliente.saldo << endl;
                cout << "Tipo da conta: " << cliente.tipoConta << endl;

                status = *cliente.contaAtiva ? "Sim" : "Não";
                cout << "Conta ativa: " << status << endl;
                cout << "" << endl;

                controleInterno = charInput("Sair (S): ");
                tolower(controleInterno);

                if (controleInterno == 's') {
                    cin.ignore();
                    break;
                }

                cin.ignore();

                break;

            case 3:
                // Desativar conta
                conta = numberInput("Qual o número da conta? ");

                try {
                    cliente = findUser(conta);
                } catch (const exception &e) {
                    cout << "[!] Erro: Nenhum cliente foi encontrado\nMensagem: " << e.what() << endl;
                    timeout(1000);
                    break;
                }

                *cliente.contaAtiva = false;

                cout << "Conta número: " << cliente.numeroConta << " foi desativa!" << endl;

                break;

            case 4:
                // Ativar conta
                conta = numberInput("Qual o número da conta? ");

                try {
                    cliente = findUser(conta);
                } catch (const exception &e) {
                    cout << "[!] Erro: Nenhum cliente foi encontrado\nMensagem: " << e.what() << endl;
                    timeout(1000);
                    break;
                }

                *cliente.contaAtiva = true;

                cout << "Conta número: " << cliente.numeroConta << " foi ativada!" << endl;

                break;
            default:
                break;
            }

            break;
        case 3:
            cout << "---- | --- Contas --- | ----" << endl;
            cout << "1. Realizar depósito." << endl;
            cout << "2. Realizar saques." << endl;
            cout << "3. Realizar transferência." << endl;
            cout << "4. Exibir o extrato." << endl;
            cout << "0. Voltar" << endl;
            cout << "------- | ------- | -------" << endl;
            controleInterno = numberInput("Escolha uma opção: ");

            int numero, numero2;
            double total, valor;

            switch (controleInterno) {
            case 1:
                // Depositar na conta
                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Você não pode fazer mais movimentações." << endl;
                    break;
                }

                numero = numberInput("Qual o número da conta? ");

                try {
                    cliente = findUser(numero);
                } catch (const exception &e) {
                    cout << "[!] Erro: " << e.what() << endl;
                    timeout(1000);
                    break;
                }

                if (*cliente.contaAtiva == false) {
                    cout << "[!] Erro: Essa conta está desativada!" << endl;
                    timeout(1000);
                    break;
                }

                valor = numberInput("Valor do depósito? ");

                if (valor <= 0) {
                    cout << "Valor inválido!" << endl;
                    timeout(1000);
                    break;
                }

                total = *cliente.saldo + valor;

                *cliente.saldo = total;

                // Controle
                contaMovimentacao[quantidadeMovimentacoes] = cliente.numeroConta;
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++;

                cout << "Depósito realizado com sucesso!" << endl;

                break;

            case 2:
                // Sacar da conta
                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Você não pode fazer mais movimentações." << endl;
                    break;
                }

                numero = numberInput("Qual o número da conta? ");

                try {
                    cliente = findUser(numero);
                } catch (const exception &e) {
                    cout << "[!] Erro: " << e.what() << endl;
                    timeout(1000);
                    break;
                }

                if (*cliente.contaAtiva == false) {
                    cout << "[!] Erro: Essa conta está desativada!" << endl;
                    timeout(1000);
                    break;
                }

                valor = numberInput("Quanto você quer sacar? ");

                if (valor <= 0) {
                    cout << "Valor inválido!" << endl;
                    break;
                }

                if (valor > *cliente.saldo) {
                    cout << "Saldo insuficiente!" << endl;
                    cout << "Saldo disponível: " << *cliente.saldo << endl;
                    timeout(2000);
                    break;
                }

                total = *cliente.saldo - valor;

                *cliente.saldo = total;

                // Controle
                contaMovimentacao[quantidadeMovimentacoes] = cliente.numeroConta;
                tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                valorMovimentacao[quantidadeMovimentacoes] = valor;

                quantidadeMovimentacoes++;

                cout << "Saque realizado com sucesso!" << endl;

                break;

            case 3:
                // Tranferencia entre contas
                if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Você não pode fazer mais movimentações." << endl;
                    break;
                }

                numero = numberInput("Qual o número da sua conta? ");

                // Buscar cliente 1
                try {
                    cliente = findUser(numero);
                } catch (const exception &e) {
                    cout << "[!] Erro: " << e.what() << endl;
                    timeout(1000);
                    break;
                }

                if (*cliente.contaAtiva == false) {
                    cout << "[!] Erro: Essa conta está desativada!" << endl;
                    timeout(1000);
                    break;
                }

                numero2 = numberInput("Qual o número da conta alvo? ");

                // Buscar cliente 2
                try {
                    cliente2 = findUser(numero2);
                } catch (const exception &e) {
                    cout << "[!] Erro: " << e.what() << endl;
                    timeout(1000);
                    break;
                }

                if (*cliente.contaAtiva == false) {
                    cout << "[!] Erro: Essa conta está desativada!" << endl;
                    timeout(1000);
                    break;
                }

                // Valor
                valor = numberInput("Valor da transferência? ");

                if (valor <= 0) {
                    cout << "Valor inválido!" << endl;
                    break;
                }

                if (valor > *cliente.saldo) {
                    cout << "Saldo insuficiente!" << endl;
                    cout << "Saldo disponível: " << *cliente.saldo << endl;
                    timeout(2000);
                    break;
                }

                // Cliente 1
                total = *cliente.saldo - valor;

                *cliente.saldo = total;

                // Controle cliente 1
                contaMovimentacao[quantidadeMovimentacoes] = cliente.numeroConta;
                tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++;

                // Cliente 2
                total = *cliente2.saldo + valor;

                *cliente2.saldo = total;

                // Controle cliente 2
                contaMovimentacao[quantidadeMovimentacoes] = cliente2.numeroConta;
                tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                valorMovimentacao[quantidadeMovimentacoes] = valor;
                quantidadeMovimentacoes++;

                cout << "Movimentação realizada com sucesso!" << endl;

                break;

            case 4:
                // Ver extrato da conta
                numero = numberInput("Qual o número da conta? ");

                cout << "---- | --- Extrato --- | ----" << endl;

                for (int i = 0; i < quantidadeMovimentacoes; i++) {
                    if (numero == contaMovimentacao[i]) {
                        if (tipoMovimentacao[i] == 'D') {
                            cout << "Deposito: R$ " << valorMovimentacao[i] << endl;
                        }

                        if (tipoMovimentacao[i] == 'S') {
                            cout << "Saque: R$ " << valorMovimentacao[i] << endl;
                        }
                    }
                }

                controleInterno = charInput("Sair (S): ");
                tolower(controleInterno);

                if (controleInterno == 's') {
                    cin.ignore();
                    break;
                }

                cin.ignore();

                break;

            default:
                break;
            }
            break;

        case 0:
            cout << "Saindo..." << endl;
            return false;
        default:
            break;
        }
    }
}
