#include "Examen.h"
#include "Erori.h"
#include <cmath>
#include <algorithm>

Examen::Examen(std::string disc, int p, int maxP)
    : Evaluare(std::move(disc)), punctaj(p), maxPunctaj(maxP) {
    if (maxPunctaj <= 0) throw ParametruInvalid("Examen: maxPunctaj trebuie > 0.");
    if (punctaj < 0 || punctaj > maxPunctaj) throw ParametruInvalid("Examen: punctaj in afara intervalului.");
}

int Examen::notaFinala() const {
    double x = 10.0 * punctaj / maxPunctaj;
    int n = (int)std::lround(x);
    return std::clamp(n, 1, 10);
}

void Examen::print(std::ostream& out) const {
    out << "[Examen] " << disciplina
        << " punctaj=" << punctaj << "/" << maxPunctaj
        << " notaFinala=" << notaFinala();
}
