// Arquivo: ValidadorEntrada.cpp
#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

namespace ValidadorEntrada {

    int validarInt(const string& mensagem) {
        int valor;
        string entrada;
        while (true) {
            cout << mensagem;
            getline(cin, entrada);
            stringstream ss(entrada);
            if (ss >> valor && ss.eof() && ss) {
                break; // Entrada válida
            } else {
                cout << "Entrada invalida! Digite um numero inteiro valido." << endl;
            }
        }
        return valor;
    }

    float validarFloat(const string& mensagem) {
        float valor;
        string entrada;
        while (true) {
            cout << mensagem;
            getline(cin, entrada);
            stringstream ss(entrada);
            if (ss >> valor && ss.eof()) {
                break; // Entrada válida
            } else {
                cout << "Entrada invalida! Digite um float valido." << endl;
            }
        }
        return valor;
    }

    string validarString(const string& mensagem) {
        string entrada;
        while (true) {
            cout << mensagem;
            getline(cin, entrada);
            if (!entrada.empty()) {
                break; // Entrada válida
            } else {
                cout << "Entrada invalida! Digite uma string valida." << endl;
            }
        }
        return entrada;
    }
}
