#include "Proiect.h"
#include "Erori.h"
#include <algorithm>

int Proiect::penalizarePeZi = 1;

Proiect::Proiect(std::string disc, int nota, int intarziereZile)
    : Evaluare(std::move(disc)), notaBruta(nota), zileIntarziere(intarziereZile) {
    if (!Evaluare::notaValida(notaBruta)) throw ParametruInvalid("Proiect: notaBruta trebuie 1..10.");
    if (zileIntarziere < 0) throw ParametruInvalid("Proiect: zileIntarziere trebuie >= 0.");
}

int Proiect::notaFinala() const {
    int n = notaBruta - penalizarePeZi * zileIntarziere;
    return std::clamp(n, 1, 10);
}

void Proiect::print(std::ostream& out) const {
    out << "[Proiect] " << disciplina
        << " notaBruta=" << notaBruta
        << " intarziere=" << zileIntarziere
        << " penalizarePeZi=" << penalizarePeZi
        << " notaFinala=" << notaFinala();
}
