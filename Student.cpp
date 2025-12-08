#include "Student.h"
#include "Proiect.h"
#include <iomanip>

int Student::nextId = 1;

Student::Student(std::string nume_)
    : id(nextId++), nume(std::move(nume_)) {}

Student::Student(const Student& other)
    : id(other.id), nume(other.nume) {
    evaluari.reserve(other.evaluari.size());
    for (const auto& ev : other.evaluari) evaluari.push_back(ev->clone());
}

void swap(Student& a, Student& b) noexcept {
    using std::swap;
    swap(a.id, b.id);
    swap(a.nume, b.nume);
    swap(a.evaluari, b.evaluari);
}

Student& Student::operator=(const Student& other) {
    if (this != &other) {
        Student tmp(other);
        swap(*this, tmp);
    }
    return *this;
}

void Student::adaugaEvaluare(std::unique_ptr<Evaluare> ev) {
    evaluari.push_back(std::move(ev));
}

double Student::medie() const {
    if (evaluari.empty()) return 0.0;
    double s = 0;
    for (const auto& ev : evaluari) s += ev->notaFinala();
    return s / evaluari.size();
}

bool Student::esteIntegralist() const {
    return std::all_of(evaluari.begin(), evaluari.end(),
        [](const auto& ev){ return ev->notaFinala() >= 5; });
}

int Student::nrProiecte() const {
    int cnt = 0;
    for (const auto& ev : evaluari)
        if (dynamic_cast<const Proiect*>(ev.get())) ++cnt;
    return cnt;
}

std::ostream& operator<<(std::ostream& out, const Student& s) {
    out << "Student{id=" << s.id << ", nume=\"" << s.nume << "\""
        << ", medie=" << std::fixed << std::setprecision(2) << s.medie()
        << ", evaluari=" << s.evaluari.size() << "}\n";
    for (const auto& ev : s.evaluari) out << "   - " << *ev << "\n";
    return out;
}
