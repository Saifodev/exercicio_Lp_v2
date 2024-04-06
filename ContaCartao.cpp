// Arquivo: ContaCartao.cpp
#pragma once

#include <iostream>
#include "DadosPessoa.cpp"

using namespace std;

class ContaCartao : public DadosPessoa {
private:
    string numConta;
    bool estado;
    float saldo;

public:
    ContaCartao(const string& nome, const string& numBI, int anoNascimento,
                const string& numConta, bool estado, float saldo)
        : DadosPessoa(nome, numBI, anoNascimento), numConta(numConta), estado(estado), saldo(saldo) {}

    string getNumConta() const { return numConta; }
    bool getEstado() const { return estado; }
    float getSaldo() const { return saldo; }

    void setNumConta(const string& numConta) { this->numConta = numConta; }
    void setEstado(bool estado) { this->estado = estado; }
    void setSaldo(float saldo) { this->saldo = saldo; }

    string info() const {
        return "Numero de conta: " + getNumConta() + ", Estado: " + (getEstado() ? "Ativo" : "Inativo") + ", Saldo: " + to_string(getSaldo());
    }
    bool levantarDinheiro(float montante) {
        if (montante > 0 && saldo >= montante) {
            setSaldo(getSaldo() - montante);
            return true;
        }
        return false;
    }

    bool depositarDinheiro(float montante) {
        if (montante > 0) {
            setSaldo(getSaldo() + montante);
            return true;
        }
        return false;
    }

    bool transferirDinheiro(float montante, ContaCartao& contaDest) {
        if (montante > 0 && saldo >= montante) {
            setSaldo(getSaldo() - montante);
            contaDest.depositarDinheiro(montante);
            return true;
        }
        return false;
    }
};
