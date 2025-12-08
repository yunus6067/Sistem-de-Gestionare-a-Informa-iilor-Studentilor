#pragma once
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <ostream>
#include <utility>
#include "Evaluare.h"

class Student {
    int id;
    std::string nume;
    std::vector<std::unique_ptr<Evaluare>> evaluari;

public:
    static int nextId;

    explicit Student(std::string nume_);
    Student(const Student& other);

    friend void swap(Student& a, Student& b) noexcept;
    Student& operator=(const Student& other);

    Student(Student&&) noexcept = default;
    Student& operator=(Student&&) noexcept = default;
    ~Student() = default;

    void adaugaEvaluare(std::unique_ptr<Evaluare> ev);

    double medie() const;
    bool esteIntegralist() const;

    int nrProiecte() const;

    friend std::ostream& operator<<(std::ostream& out, const Student& s);
};
