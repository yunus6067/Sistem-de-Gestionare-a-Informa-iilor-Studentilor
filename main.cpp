#include <iostream>
#include <memory>
#include <vector>
#include <string>

#include "Grup.h"
#include "Examen.h"
#include "Proiect.h"
#include "Quiz.h"
#include "Erori.h"
#include "Factory.h"      
#include "TemplateUtils.h" 

int main() {
    try {
        // --- 1. Template Class (Instantierea 1: Student) ---
        ManagerDate<Student> catalog;
        
        // --- 2. Template Class (Instantierea 2: std::string) ---
        ManagerDate<std::string> istoricActiuni;

        // Student 1
        Student s1("Ion Popescu");
        s1.adaugaEvaluare(EvaluareFactory::creeazaExamen("POO", 85, 100));
        s1.adaugaEvaluare(EvaluareFactory::creeazaProiect("POO", 9, 1));
        s1.adaugaEvaluare(EvaluareFactory::creeazaQuiz("POO", 8, 10));

        // Student 2
        Student s2("Maria Ionescu");
        s2.adaugaEvaluare(EvaluareFactory::creeazaExamen("POO", 40, 100));
        s2.adaugaEvaluare(EvaluareFactory::creeazaProiect("POO", 7, 3));
        s2.adaugaEvaluare(EvaluareFactory::creeazaQuiz("POO", 6, 10));

        // Student 3
        Student s3("Andrei Vasile");
        s3.adaugaEvaluare(EvaluareFactory::creeazaExamen("POO", 95, 100));
        s3.adaugaEvaluare(EvaluareFactory::creeazaProiect("POO", 10, 0));
        s3.adaugaEvaluare(EvaluareFactory::creeazaQuiz("POO", 10, 10));

        // Adaugam in template si logam
        catalog.adauga(std::move(s1));
        istoricActiuni.adauga("Adaugat student: Ion Popescu");
        
        catalog.adauga(std::move(s2));
        istoricActiuni.adauga("Adaugat student: Maria Ionescu");
        
        catalog.adauga(std::move(s3));
        istoricActiuni.adauga("Adaugat student: Andrei Vasile");

        Grup g;
        for (const auto& s : catalog.getToate()) {
            g.adaugaStudent(s); 
        }

        std::cout << "=== Lista completa (din Grup) ===\n";
        g.afiseazaToti();

        // --- 3. Template Function (Instantierea 1: Student) ---
        std::cout << "\n=== [Template] Studenti cu media > 8.5 ===\n";
        afiseazaFiltrat(catalog.getToate(), [](const Student& s) {
            return s.medie() > 8.5;
        });

        // --- 4. Template Function (Instantierea 2: int) ---
        std::vector<int> praguriContestatie = {4, 5, 8, 10};
        std::cout << "\n=== [Template] Praguri de nota peste 5 ===\n";
        afiseazaFiltrat(praguriContestatie, [](int n) {
            return n > 5;
        });

        std::cout << "\n=== Statistici finale ===\n";
        g.sorteazaDupaMedie();
        g.afiseazaIntegralisti();
        g.afiseazaNrProiecte();

    }
    catch (const StudentError& e) {
        std::cerr << "StudentError: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cerr << "std::exception: " << e.what() << "\n";
    }

    return 0;
}