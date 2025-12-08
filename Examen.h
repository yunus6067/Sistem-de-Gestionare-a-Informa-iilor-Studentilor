#pragma once
#include "Evaluare.h"

class Examen final : public Evaluare {
    int punctaj, maxPunctaj;

protected:
    void print(std::ostream& out) const override;

public:
    Examen(std::string disc, int p, int maxP);

    int notaFinala() const override;
    std::unique_ptr<Evaluare> clone() const override {
        return std::make_unique<Examen>(*this);
    }
};
