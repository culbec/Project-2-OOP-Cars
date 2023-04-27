#pragma once

#include "Car.h"
#include "LDI.h"
#include <utility>
#include <vector>
#include <exception>
#include <algorithm>

using std::vector;
using std::exception;
using std::remove;

typedef LDI<Car> carList;

// declaram o exceptie custom pentru repository:
class RepositoryException : std::exception {
private:
    string errorMessage;
public:
    explicit RepositoryException(string message) : errorMessage(std::move(message)) {}

    string getMessage() { return this->errorMessage; }
};

class Repository {
    friend class Car;

private:
    carList cars; // lista de masini
public:
    Repository() noexcept;

    /*
        Returneaza lista de masini a repository-ului
        @pre: true
        @post: lista de masini a repo-ului
    */
    const carList &getCars() const;

    /*
        Size-ul listei de masini
        @pre: true
        @post: size-ul listei de masini
    */
    size_t getSize() const noexcept;

    /*
        Cauta o masina dupa un anumit id si ii returneaza pozitia.
        @pre: string -> numar de inmatriculare
        @post: pozitia masinii
        @exception: masina nu exista in lista
    */

    unsigned int findCar(const string &) const;

    /*
        Adauga o masina la lista de masini
        @pre: Car -> obiect de tip Car valid
        @post: obiectul de tip Car adaugat la lista de masini
    */
    void addCar(const Car &);

    /*
        Sterge o masina din lista de masini
        @pre: string -> numar de inmatriculare
        @post: masina stearsa
        @exception: nu exista masina in lista
    */
    Car deleteCar(const string &);

    /*
        Modifica o masina din lista de masini
        @pre: string -> numar de inmatriculare
              string -> producator
              string -> model
              string -> tip
        @post: masina modificata
        @exception: nu exista masina in lista
    */
    Car modifyCar(const Car &);

    /*
        Functie de copiere (deep copy)
        @pre: true
        @post: lista de masini este copiata
    */
    static carList copyList(const carList &);
};

