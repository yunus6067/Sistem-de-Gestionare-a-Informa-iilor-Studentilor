#pragma once
#include "Evaluare.h"

class Proiect final : public Evaluare {
    int notaBruta;      // 1..10
    int zileIntarziere; // >=0

public:
    static int penalizarePeZi; // static bifa

protected:
    void print(std::ostream& out) const override;

public:
    Proiect(std::string disc, int nota, int intarziereZile);
    int notaFinala() const override;

    std::unique_ptr<Evaluare> clone() const override {
        return std::make_unique<Proiect>(*this);
    }
};
