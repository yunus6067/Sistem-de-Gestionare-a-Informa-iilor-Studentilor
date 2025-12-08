#include "Grup.h"
#include <iostream>
#include <algorithm>

void Grup::afiseazaToti() const {
    for (const auto& s : studenti) std::cout << s;
}

void Grup::sorteazaDupaMedie() {
    std::sort(studenti.begin(), studenti.end(),
        [](const Student& a, const Student& b){ return a.medie() > b.medie(); });
}

void Grup::afiseazaIntegralisti() const {
    for (const auto& s : studenti)
        if (s.esteIntegralist()) std::cout << s;
}

void Grup::afiseazaNrProiecte() const {
    for (const auto& s : studenti)
        std::cout << "Nr proiecte: " << s.nrProiecte() << "\n";
}
