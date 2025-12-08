#include "Quiz.h"
#include "Erori.h"
#include <cmath>
#include <algorithm>

Quiz::Quiz(std::string disc, int c, int t)
    : Evaluare(std::move(disc)), corecte(c), total(t) {
    if (total <= 0) throw ParametruInvalid("Quiz: total trebuie > 0.");
    if (corecte < 0 || corecte > total) throw ParametruInvalid("Quiz: corecte in afara intervalului.");
}

int Quiz::notaFinala() const {
    double x = 10.0 * corecte / total;
    int n = (int)std::lround(x);
    return std::clamp(n, 1, 10);
}

void Quiz::print(std::ostream& out) const {
    out << "[Quiz] " << disciplina
        << " corecte=" << corecte << "/" << total
        << " notaFinala=" << notaFinala();
}
