#include "ContaAluno.cpp"
#include "ValidadorEntrada.cpp"
#include <iostream>
#include <vector>

using namespace std;

class BancoAlunos {
private:
    vector<ContaAluno> alunos;

public:
    void adicionarAluno(const ContaAluno& aluno) {
        alunos.push_back(aluno);
    }

    void verTodosAlunos() {
        cout << "Visualizando todos os alunos:\n";
        for (const auto& aluno : alunos) {
            cout << aluno.Aluno::info() +", "+ aluno.ContaCartao::info() << endl; //aluno.getSaldo() << endl;
        }
    }
};

void mostrarMenu()
{
    cout << "\n--- Menu ---\n";
    cout << "1. Ver saldo\n";
    cout << "2. Depositar dinheiro\n";
    cout << "3. Levantar dinheiro\n";
    cout << "4. Transferir dinheiro\n";
    cout << "5. Minha Conta\n";
    cout << "6. Ver todos os alunos\n";
    cout << "0. Sair\n";
}

void mostrarOpcoesEdicao() {
    cout << "O que quer Editar:\n";
    cout << "1. Dados Pessoais\n";
    cout << "2. Dados do Cartao\n";
    cout << "3. Dados do Aluno\n";
    cout << "0. Sair\n";
}

void mostrarOpcoesEdicaoDadosPessoais() {
    cout << "Editar Dados Pessoais:\n";
    cout << "1. Nome\n";
    cout << "2. Numero BI\n";
    cout << "3. Ano Nascimento\n";
    cout << "0. Sair\n";
}

void subMenu(ContaAluno& aluno);

void editarDadosPessoais(ContaAluno& aluno) {
    int opcao;
  
    do {
        mostrarOpcoesEdicaoDadosPessoais();
        opcao = ValidadorEntrada::validarInteiro("Escolha uma opcao: ");
      
        switch (opcao) {
            case 1: {
                system("cls");
                string nome = ValidadorEntrada::validarString("Novo nome: ");
                aluno.Aluno::setNome(nome);
                break;
            }
            case 2: {
                system("cls");
                string bi = ValidadorEntrada::validarString("Novo número do BI: ");
                aluno.Aluno::setNumBI(bi);
                break;
            }
            case 3: {
                system("cls");
                int anoNascimento = ValidadorEntrada::validarInteiro("Novo ano de nascimento: ");
                aluno.Aluno::setAnoNascimento(anoNascimento);
                break;
            }
            case 0:
                cout << "Saindo da edicao de dados pessoais...\n";
                break;
            default:
                cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 0);
    
    // Após editar os dados, retorna ao subMenu
    subMenu(aluno);
}

void verTodosAlunos(BancoAlunos& banco) {
    banco.verTodosAlunos();
}

void subMenu(ContaAluno& aluno) {
    int opcao;
    do {
        system("cls");
        cout << "--- Minhas Informacoes ---\n";
        cout << "Info Pessoais: " << aluno.Aluno::info() << endl;
        cout << "Info Aluno: " << aluno.infoAluno() << endl;
        cout << "Info Cartao: " << aluno.ContaCartao::info() << endl;
        cout << "Info Cartao do Aluno: " << aluno.info() << endl;
        cout << "-------------------------\n";

        mostrarOpcoesEdicao();
        opcao = ValidadorEntrada::validarInteiro("Escolha uma opcao: ");
        switch (opcao) {
            case 1:
                system("cls");
                editarDadosPessoais(aluno);
                break;
            case 0:
                system("cls");
                cout << "Voltando ao menu principal...\n";
                break;
            default:
                system("cls");
                cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 0);
}

int main()
{
    system("cls");
    ContaAluno aluno1("Joao", "123456789", 1990, "Escola XYZ", "M123", "999999999",
                      "987654321", true, 1000.0, 0.1, 0.05);
    ContaAluno aluno2("Maria", "987654321", 1992, "Escola ABC", "M456", "888888888",
                      "123456789", true, 1500.0, 0.1, 0.05);

    BancoAlunos banco;
    banco.adicionarAluno(aluno1);
    banco.adicionarAluno(aluno2);

    int opcao;
    float valor;
    string numContaDest;

    do
    {
        mostrarMenu();
        opcao = ValidadorEntrada::validarInteiro("Escolha uma opcao: ");

        switch (opcao)
        {
        case 1:
            system("cls");
            cout << "Saldo atual: " << aluno1.getSaldo() << endl;
            break;
        case 2:
            system("cls");
            valor = ValidadorEntrada::validarFlutuante("Digite o valor para depositar: ");
            aluno1.depositarDinheiro(valor);
            break;
        case 3:
            system("cls");
            valor = ValidadorEntrada::validarFlutuante("Digite o valor para levantar: ");
            aluno1.levantarDinheiro(valor);
            break;
        case 4:
            system("cls");
            valor = ValidadorEntrada::validarFlutuante("Digite o valor para transferir: ");
            numContaDest = ValidadorEntrada::validarString("Digite o número da conta de destino: ");

            aluno1.transferirDinheiro(valor, aluno2);
            break;
        case 5:
            system("cls");
            subMenu(aluno1);
            break;
        case 6:
            system("cls");
            verTodosAlunos(banco);
            break;
        case 0:
            system("cls");
            cout << "Saindo do programa...\n";
            break;
        default:
            system("cls");
            cout << "Opcao invalida! Tente novamente.\n";
        }
    } while (opcao != 0);

    return 0;
}
