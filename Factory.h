#pragma once
#include <memory>
#include <string>
#include "Examen.h"
#include "Proiect.h"
#include "Quiz.h"

// Design Pattern: Simple Factory
class EvaluareFactory {
public:
    static std::unique_ptr<Evaluare> creeazaExamen(std::string d, int p, int m) {
        return std::make_unique<Examen>(std::move(d), p, m);
    }
    static std::unique_ptr<Evaluare> creeazaProiect(std::string d, int n, int z) {
        return std::make_unique<Proiect>(std::move(d), n, z);
    }
    static std::unique_ptr<Evaluare> creeazaQuiz(std::string d, int c, int t) {
        return std::make_unique<Quiz>(std::move(d), c, t);
    }
};
