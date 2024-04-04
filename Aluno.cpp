// Arquivo: Aluno.cpp
#pragma once

#include <iostream>
#include "DadosPessoa.cpp"

class Aluno : public DadosPessoa {
private:
    std::string escola;
    std::string idMatricula;
    std::string contacto;

public:
    Aluno(const std::string& nome, const std::string& numBI, int anoNascimento,
          const std::string& escola, const std::string& idMatricula, const std::string& contacto)
        : DadosPessoa(nome, numBI, anoNascimento), escola(escola), idMatricula(idMatricula), contacto(contacto) {}

    std::string getEscola() const { return escola; }
    std::string getIdMatricula() const { return idMatricula; }
    std::string getContacto() const { return contacto; }

    void setEscola(const std::string& escola) { this->escola = escola; }
    void setIdMatricula(const std::string& idMatricula) { this->idMatricula = idMatricula; }
    void setContacto(const std::string& contacto) { this->contacto = contacto; }

    std::string infoAluno() const {
        return "Escola: " + getEscola() + ", Matricula: " + getIdMatricula() + ", Contacto: " + getContacto();
    }
};