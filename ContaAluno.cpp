// Arquivo: ContaAluno.cpp
#pragma once

#include <iostream>
#include "ContaCartao.cpp"
#include "Aluno.cpp"

class ContaAluno : public ContaCartao, public Aluno {
private:
    float desconto_lev;
    float bonos_dep;

public:
    ContaAluno(const std::string& nome, const std::string& numBI, int anoNascimento,
               const std::string& escola, const std::string& idMatricula, const std::string& contacto,
               const std::string& numConta, bool estado, float saldo, float desconto_lev, float bonos_dep)
        : ContaCartao(nome, numBI, anoNascimento, numConta, estado, saldo),
          Aluno(nome, numBI, anoNascimento, escola, idMatricula, contacto),
          desconto_lev(desconto_lev), bonos_dep(bonos_dep) {}

    float getDescontoLev() const { return desconto_lev; }
    float getBonosDep() const { return bonos_dep; }

    void setDescontoLev(float desconto_lev) { this->desconto_lev = desconto_lev; }
    void setBonosDep(float bonos_dep) { this->bonos_dep = bonos_dep; }

    string info() const {
        return "Desconto: " + to_string(getDescontoLev()) + ", Bonos: " + to_string(getBonosDep());
    }

    void levantarDinheiro(float montante) {
        float montanteFinal = montante * (1.0 - desconto_lev); // Aplicando desconto
        ContaCartao::levantarDinheiro(montanteFinal);
    }

    void depositarDinheiro(float montante) {
        float montanteFinal = montante * (1.0 + bonos_dep); // Aplicando bônus
        ContaCartao::depositarDinheiro(montanteFinal);
    }

    void transferirDinheiro(float montante, ContaAluno& contaDest) {
        ContaCartao::transferirDinheiro(montante, contaDest);
    }

};