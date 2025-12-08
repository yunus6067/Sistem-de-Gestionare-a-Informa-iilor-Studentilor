#include <iostream>
#include <memory>

#include "Grup.h"
#include "Examen.h"
#include "Proiect.h"
#include "Quiz.h"
#include "Erori.h"

int main() {
    try {
        Grup g;

        Student s1("Ion Popescu");
        s1.adaugaEvaluare(std::make_unique<Examen>("POO", 85, 100));
        s1.adaugaEvaluare(std::make_unique<Proiect>("POO", 9, 1));
        s1.adaugaEvaluare(std::make_unique<Quiz>("POO", 8, 10));

        Student s2("Maria Ionescu");
        s2.adaugaEvaluare(std::make_unique<Examen>("POO", 40, 100));
        s2.adaugaEvaluare(std::make_unique<Proiect>("POO", 7, 3));
        s2.adaugaEvaluare(std::make_unique<Quiz>("POO", 6, 10));

        Student s3("Andrei Vasile");
        s3.adaugaEvaluare(std::make_unique<Examen>("POO", 95, 100));
        s3.adaugaEvaluare(std::make_unique<Proiect>("POO", 10, 0));
        s3.adaugaEvaluare(std::make_unique<Quiz>("POO", 10, 10));

        g.adaugaStudent(std::move(s1));
        g.adaugaStudent(std::move(s2));
        g.adaugaStudent(std::move(s3));

        std::cout << "=== Inainte de sortare ===\n";
        g.afiseazaToti();

        g.sorteazaDupaMedie();
        std::cout << "\n=== Dupa sortare ===\n";
        g.afiseazaToti();

        std::cout << "\n=== Integralisti ===\n";
        g.afiseazaIntegralisti();

        std::cout << "\n=== Dynamic cast: nr proiecte ===\n";
        g.afiseazaNrProiecte();
    }
    catch (const StudentError& e) {
        std::cerr << "StudentError: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "std::exception: " << e.what() << "\n";
    }
}
