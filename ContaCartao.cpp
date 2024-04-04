// Arquivo: ContaCartao.cpp
#pragma once

#include <iostream>
#include "DadosPessoa.cpp"

class ContaCartao : public DadosPessoa {
private:
    std::string numConta;
    bool estado;
    float saldo;

public:
    ContaCartao(const std::string& nome, const std::string& numBI, int anoNascimento,
                const std::string& numConta, bool estado, float saldo)
        : DadosPessoa(nome, numBI, anoNascimento), numConta(numConta), estado(estado), saldo(saldo) {}

    std::string getNumConta() const { return numConta; }
    bool getEstado() const { return estado; }
    float getSaldo() const { return saldo; }

    void setNumConta(const std::string& numConta) { this->numConta = numConta; }
    void setEstado(bool estado) { this->estado = estado; }
    void setSaldo(float saldo) { this->saldo = saldo; }

     string info() const {
        return "Numero de conta: " + getNumConta() + ", Estado: " + to_string(getEstado());
    }

    void levantarDinheiro(float montante) {
        if (montante > 0 && getSaldo() >= montante) {
            setSaldo(getSaldo() - montante);
            std::cout << "Levantamento bem-sucedido. Saldo restante: " << getSaldo() << std::endl;
        } else {
            std::cout << "Erro ao levantar dinheiro. Saldo insuficiente." << std::endl;
        }
    }

    void depositarDinheiro(float montante) {
        if (montante > 0) {
            setSaldo(getSaldo() + montante);
            std::cout << "Depósito bem-sucedido. Saldo atualizado: " << getSaldo() << std::endl;
        } else {
            std::cout << "Erro ao depositar dinheiro. Montante inválido." << std::endl;
        }
    }

void transferirDinheiro(float montante, ContaCartao& contaDest) {
    if (montante > 0 && getSaldo() >= montante) {
        setSaldo(getSaldo() - montante);
        contaDest.setSaldo(contaDest.getSaldo() + montante); // Correção aqui
        std::cout << "Transferência realizada com sucesso." << std::endl;
        
        // Mostrar saldos atualizados
        std::cout << "Saldo atual da conta origem: " << getSaldo() << std::endl;
        std::cout << "Saldo atual da conta destino: " << contaDest.getSaldo() << std::endl;
    } else {
        std::cout << "Erro ao transferir dinheiro. Saldo insuficiente." << std::endl;
    }
}


};