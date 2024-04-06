// Arquivo: ContaAluno.cpp
#pragma once

#include <iostream>
#include "ContaCartao.cpp"
#include "Aluno.cpp"

using namespace std;

class ContaAluno : public ContaCartao, public Aluno {
private:
    float desconto_lev;
    float bonos_dep;

public:
    ContaAluno(const string& nome, const string& numBI, int anoNascimento,
               const string& escola, const string& idMatricula, const string& contacto,
               const string& numConta, bool estado, float saldo, float desconto_lev, float bonos_dep)
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

    bool levantarDinheiro(float montante) {
        float montanteFinal = montante * (1.0 - getDescontoLev()); // Aplicando desconto
        return ContaCartao::levantarDinheiro(montanteFinal);
    }

    bool depositarDinheiro(float montante) {
       float montanteFinal = montante * (1.0 + getBonosDep()); // Aplicando bônus
        return ContaCartao::depositarDinheiro(montanteFinal);
    }

    bool transferirDinheiro(float montante, ContaCartao& contaDest) {
        return ContaCartao::transferirDinheiro(montante, contaDest);
    }
};
