#pragma once
#include "Evaluare.h"

class Quiz final : public Evaluare {
    int corecte, total;

protected:
    void print(std::ostream& out) const override;

public:
    Quiz(std::string disc, int c, int t);
    int notaFinala() const override;

    std::unique_ptr<Evaluare> clone() const override {
        return std::make_unique<Quiz>(*this);
    }
};
