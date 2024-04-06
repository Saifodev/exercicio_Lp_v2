// Arquivo: Aluno.cpp
#pragma once

#include <iostream>
#include "DadosPessoa.cpp"

using namespace std;

class Aluno : public DadosPessoa {
private:
    string escola;
    string idMatricula;
    string contacto;

public:
    Aluno(const string& nome, const string& numBI, int anoNascimento,
          const string& escola, const string& idMatricula, const string& contacto)
        : DadosPessoa(nome, numBI, anoNascimento), escola(escola), idMatricula(idMatricula), contacto(contacto) {}

    string getEscola() const { return escola; }
    string getIdMatricula() const { return idMatricula; }
    string getContacto() const { return contacto; }

    void setEscola(const string& escola) { this->escola = escola; }
    void setIdMatricula(const string& idMatricula) { this->idMatricula = idMatricula; }
    void setContacto(const string& contacto) { this->contacto = contacto; }

    string infoAluno() const {
        return "Escola: " + getEscola() + ", Matricula: " + getIdMatricula() + ", Contacto: " + getContacto();
    }
};
