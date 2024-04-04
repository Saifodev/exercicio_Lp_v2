// Arquivo: ValidadorEntrada.cpp
#include <iostream>
#include <limits>
#include <sstream>

class ValidadorEntrada {
public:
    static int validarInteiro(const std::string& mensagem) {
        int valor;
        std::string entrada;
        while (true) {
            std::cout << mensagem;
            std::getline(std::cin, entrada);
            std::stringstream ss(entrada);
            if (ss >> valor && ss.eof()) {
                break; // Entrada válida
            } else {
                std::cout << "Entrada inválida! Digite um número inteiro válido." << std::endl;
            }
        }
        return valor;
    }

    static float validarFlutuante(const std::string& mensagem) {
        float valor;
        std::string entrada;
        while (true) {
            std::cout << mensagem;
            std::getline(std::cin, entrada);
            std::stringstream ss(entrada);
            if (ss >> valor && ss.eof()) {
                break; // Entrada válida
            } else {
                std::cout << "Entrada inválida! Digite um número de ponto flutuante válido." << std::endl;
            }
        }
        return valor;
    }

    static std::string validarString(const std::string& mensagem) {
        std::string entrada;
        while (true) {
            std::cout << mensagem;
            std::getline(std::cin, entrada);
            if (!entrada.empty()) {
                break; // Entrada válida
            } else {
                std::cout << "Entrada inválida! Digite uma string válida." << std::endl;
            }
        }
        return entrada;
    }
};
