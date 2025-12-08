#pragma once
#include <stdexcept>
#include <string>

class StudentError : public std::runtime_error {
public:
    explicit StudentError(const std::string& msg) : std::runtime_error(msg) {}
};

class DisciplinaInvalida : public StudentError {
public:
    DisciplinaInvalida() : StudentError("Disciplina invalida (string gol).") {}
};

class ParametruInvalid : public StudentError {
public:
    explicit ParametruInvalid(const std::string& msg) : StudentError(msg) {}
};

class FaraEvaluari : public StudentError {
public:
    FaraEvaluari() : StudentError("Studentul nu are evaluari.") {}
};
