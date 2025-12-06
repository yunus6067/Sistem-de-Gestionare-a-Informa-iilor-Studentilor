#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// -------------------- CLASS NOTE --------------------
class Note {
private:
    vector<int> valori;

public:
    // Конструкторы
    Note() = default;
    Note(const vector<int>& valori) : valori(valori) {}
    Note(const Note& other) = default;
    Note& operator=(const Note& other) = default;
    ~Note() = default;

    // Добавление оценки
    void adaugaNota(int n) { valori.push_back(n); }

    // Средний балл
    double calculeazaMedie() const {
        if (valori.empty()) return 0;
        double suma = 0;
        for (int v : valori) suma += v;
        return suma / valori.size();
    }

    // Количество оценок
    int getNrNote() const { return valori.size(); }

    // Вывод
    friend ostream& operator<<(ostream& out, const Note& n) {
        out << "Note: ";
        for (int v : n.valori) out << v << " ";
        out << "(Medie: " << fixed << setprecision(2) << n.calculeazaMedie() << ")";
        return out;
    }
};

// -------------------- CLASS STUDENT --------------------
class Student {
private:
    string nume;
    int id;
    Note note;

public:
    // Конструкторы
    Student() : nume("Anonim"), id(0) {}
    Student(int id, const string& nume, const Note& note)
        : nume(nume), id(id), note(note) {}
    Student(const Student& other) = default;
    Student& operator=(const Student& other) = default;
    ~Student() = default;

    // Геттеры
    string getNume() const { return nume; }
    double getMedie() const { return note.calculeazaMedie(); }

    // Методы
    void adaugaNota(int n) { note.adaugaNota(n); }

    bool esteIntegralist() const { // студент без оценок < 5
        return note.calculeazaMedie() >= 5;
    }

    // Вывод
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "ID: " << s.id << ", Nume: " << s.nume << ", " << s.note;
        return out;
    }
};

// -------------------- CLASS GRUP --------------------
class Grup {
private:
    vector<Student> studenti;

public:
    // Методы
    void adaugaStudent(const Student& s) { studenti.push_back(s); }

    void afiseazaToti() const {
        cout << "\nLista studentilor:\n";
        for (const auto& s : studenti)
            cout << s << endl;
    }

    void sorteazaDupaMedie() {
        sort(studenti.begin(), studenti.end(),
             [](const Student& a, const Student& b) {
                 return a.getMedie() > b.getMedie();
             });
    }

    void afiseazaIntegraliști() const {
        cout << "\nStudenti integralisti:\n";
        for (const auto& s : studenti)
            if (s.esteIntegralist())
                cout << s << endl;
    }
};

// -------------------- MAIN --------------------
int main() {
    Note n1({9, 10, 8});
    Note n2({4, 6, 5});
    Note n3({10, 9, 9});

    Student s1(1, "Ion Popescu", n1);
    Student s2(2, "Maria Ionescu", n2);
    Student s3(3, "Andrei Vasile", n3);

    Grup g;
    g.adaugaStudent(s1);
    g.adaugaStudent(s2);
    g.adaugaStudent(s3);

    cout << "Inainte de sortare:\n";
    g.afiseazaToti();

    g.sorteazaDupaMedie();
    cout << "\nDupa sortare:\n";
    g.afiseazaToti();

    g.afiseazaIntegraliști();
    return 0;
}

