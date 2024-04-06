// arquivo: main.cpp
#include "ContaAluno.cpp"
#include "ValidadorEntrada.cpp"
#include <iostream>
#include <vector>

using namespace std;

void mostrarMenu()
{
    cout << "\n--- Menu ---\n";
    cout << "1. Ver todos os alunos\n";
    cout << "2. Depositar dinheiro\n";
    cout << "3. Levantar dinheiro\n";
    cout << "4. Transferir dinheiro\n";
    cout << "5. Ver saldo\n";
    cout << "6. Minha Conta\n";
    cout << "0. Sair\n";
}

void mostrarOpcoesEdicao()
{
    cout << "O que quer Editar:\n";
    cout << "1. Dados Pessoais\n";
    cout << "2. Dados do Cartao\n";
    cout << "3. Dados do Aluno\n";
    cout << "0. Sair\n";
}

void mostrarOpcoesEdicaoDadosPessoais()
{
    cout << "Editar Dados Pessoais:\n";
    cout << "1. Nome\n";
    cout << "2. Numero BI\n";
    cout << "3. Ano Nascimento\n";
    cout << "0. Sair\n";
}

void subMenu(ContaAluno &aluno);

void editarDadosPessoais(ContaAluno &aluno)
{
    int opcao;

    do
    {
        mostrarOpcoesEdicaoDadosPessoais();
        opcao = ValidadorEntrada::validarInt("Escolha uma opcao: ");

        switch (opcao)
        {
        case 1:
        {
            system("cls");
            string nome = ValidadorEntrada::validarString("Novo nome: ");
            aluno.Aluno::setNome(nome);
            break;
        }
        case 2:
        {
            system("cls");
            string bi = ValidadorEntrada::validarString("Novo número do BI: ");
            aluno.Aluno::setNumBI(bi);
            break;
        }
        case 3:
        {
            system("cls");
            int anoNascimento = ValidadorEntrada::validarInt("Novo ano de nascimento: ");
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

void subMenu(ContaAluno &aluno)
{
    int opcao;
    do
    {
        system("cls");
        cout << "--- Minhas Informacoes ---\n";
        cout << "Info Pessoais: " << aluno.Aluno::info() << endl;
        cout << "Info Aluno: " << aluno.infoAluno() << endl;
        cout << "Info Cartao: " << aluno.ContaCartao::info() << endl;
        cout << "Info Cartao do Aluno: " << aluno.info() << endl;
        cout << "-------------------------\n";

        mostrarOpcoesEdicao();
        opcao = ValidadorEntrada::validarInt("Escolha uma opcao: ");
        switch (opcao)
        {
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
    vector<ContaAluno> alunos;

    alunos.push_back(ContaAluno("Joao", "123456789", 1990, "Escola XYZ", "M123", "999999999",
                                "987654321", true, 1000.0, 0.1, 0.05));
    alunos.push_back(ContaAluno("Maria", "987654321", 1992, "Escola ABC", "M456", "888888888",
                                "123456789", true, 1500.0, 0.1, 0.05));

    cout << alunos[0].Aluno::info() + ", " + alunos[0].ContaCartao::info() << endl;

    int opcao;
    float valor;
    string numContaDest;
    int indiceOrigem = -1, indiceDestino = -1;

    do
    {
        mostrarMenu();
        opcao = ValidadorEntrada::validarInt("Escolha uma opcao: ");

        switch (opcao)
        {
        case 1:
            system("cls");
            {
                cout << "\nInformacoes de todas as contas:" << endl;
                for (int i = 0; i < alunos.size(); ++i)
                {
                    cout << alunos[i].Aluno::info() + ", " + alunos[i].ContaCartao::info() << endl;
                    cout << endl;
                }
                break;
            }
        case 2:
            system("cls");
            valor = ValidadorEntrada::validarFloat("Digite o valor para depositar: ");
            if (alunos[0].depositarDinheiro(valor)) {
                cout << "Deposito realizado com sucesso!" << endl;
                cout << "Saldo atual: " << alunos[0].getSaldo() << endl;
            }else {
                cout << "Valor invalido para deposito!" << endl;
            }
            break;
        case 3:
            system("cls");
            valor = ValidadorEntrada::validarFloat("Digite o valor para levantar: ");
            if (alunos[0].levantarDinheiro(valor)) {
                cout << "Levantamento realizado com sucesso!" << endl;
                cout << "Saldo atual: " << alunos[0].getSaldo() << endl;
            }
            else {
                cout << "Saldo insuficiente para o levantamento!" << endl;
            }
            break;
        
            break;
        case 4:
            system("cls");
                numContaDest = ValidadorEntrada::validarString("Digite o numero da conta de destino para transferencia: ");
                for (int i = 0; i < alunos.size(); ++i) {
                    if (alunos[i].getNumConta() == alunos[0].getNumConta()) {
                        indiceOrigem = i;
                    }
                    if (alunos[i].getNumConta() == numContaDest) {
                        indiceDestino = i;
                    }
                    if (indiceOrigem != -1 && indiceDestino != -1) {
                        break;
                    }
                }
                
                if (indiceOrigem != -1 && indiceDestino != -1 && numContaDest != alunos[0].getNumConta()) {
                    valor = ValidadorEntrada::validarFloat("Digite o valor a ser transferido: ");
                    if (alunos[indiceOrigem].transferirDinheiro(valor, alunos[indiceDestino])) {
                        system("cls");
                        cout << "Transferencia realizada com sucesso!" << endl;
                        cout << "Saldo na conta origem: " << alunos[indiceOrigem].getSaldo() << endl;
                        cout << "Saldo na conta destino: " << alunos[indiceDestino].getSaldo() << endl;
                    }
                    else {
                        cout << "Saldo insuficiente para a transferencia!" << endl;
                    }
                }
                else {
                    cout << "Conta de destino invalida para a transferencia!" << endl;
                }
            break;
        case 5:
            system("cls");
            cout << "Saldo atual: " << alunos[0].getSaldo();
            cout << endl;
            break;

        case 6:
            system("cls");
            subMenu(alunos[0]);
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
