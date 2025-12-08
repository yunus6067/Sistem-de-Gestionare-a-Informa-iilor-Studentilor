#pragma once
#include <iostream>
#include <memory>
#include <string>

class Evaluare {
protected:
    std::string disciplina;
    virtual void print(std::ostream& out) const = 0;

public:
    explicit Evaluare(std::string disc);   // <-- doar declaratie
    virtual ~Evaluare() = default;

    virtual int notaFinala() const = 0;
    virtual std::unique_ptr<Evaluare> clone() const = 0;

    void afiseaza(std::ostream& out) const { print(out); }

    friend std::ostream& operator<<(std::ostream& out, const Evaluare& e) {
        e.afiseaza(out);
        return out;
    }

    static bool notaValida(int n) { return 1 <= n && n <= 10; }
};
