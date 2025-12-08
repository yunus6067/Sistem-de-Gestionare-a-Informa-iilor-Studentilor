#pragma once
#include <vector>
#include "Student.h"

class Grup {
    std::vector<Student> studenti;

public:
    void adaugaStudent(Student s) { studenti.push_back(std::move(s)); }

    void afiseazaToti() const;
    void sorteazaDupaMedie();
    void afiseazaIntegralisti() const;
    void afiseazaNrProiecte() const;
};
