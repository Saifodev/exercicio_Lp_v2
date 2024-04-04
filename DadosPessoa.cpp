// Arquivo: DadosPessoa.cpp
#pragma once

#include <iostream>
#include <string>

using namespace std;

class DadosPessoa {
private:
    string nome;
    string numBI;
    int anoNascimento;

public:
    DadosPessoa(const string& nome, const string& numBI, int anoNascimento)
        : nome(nome), numBI(numBI), anoNascimento(anoNascimento) {}

    string getNome() const { return nome; }
    string getNumBI() const { return numBI; }
    int getAnoNascimento() const { return anoNascimento; }

    void setNome(const string& nome) { this->nome = nome; }
    void setNumBI(const string& numBI) { this->numBI = numBI; }
    void setAnoNascimento(int anoNascimento) { this->anoNascimento = anoNascimento; }

    string info() const {
        return "Nome: " + getNome() + ", Numero BI: " + getNumBI() + ", Ano Nascimento: " + to_string(getAnoNascimento());
    }
};