#pragma once
#include <vector>
#include <iostream>

// Clasa Sablon
template <typename T>
class ManagerDate {
private:
    std::vector<T> colectie;
public:
    void adauga(T item) { colectie.push_back(std::move(item)); }
    const std::vector<T>& getToate() const { return colectie; }
};

// Functie Sablon - ASIGURA-TE CA NUMELE ESTE afiseazaFiltrat
template <typename T, typename Predicat>
void afiseazaFiltrat(const std::vector<T>& lista, Predicat conditie) {
    for (const auto& element : lista) {
        if (conditie(element)) {
            std::cout << element << "\n";
        }
    }
}