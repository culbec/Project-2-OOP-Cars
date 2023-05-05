#pragma once

#include "Car.h"
#include <utility>
#include <vector>
#include <exception>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <unordered_map>

using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;
using std::exception;
using std::remove;
using std::find_if;
using std::copy;
using std::back_inserter;
using std::copy_if;
using std::unordered_map;

typedef vector<Car> carList;

// declaram o exceptie custom pentru repository:
class RepositoryException : std::exception {
private:
    string errorMessage;
public:
    explicit RepositoryException(string message) : errorMessage(std::move(message)) {}

    string getMessage() { return this->errorMessage; }
};

class RepoAbstract {
public:
    virtual const carList &getCars() const = 0;

    virtual size_t getSize() const noexcept = 0;

    virtual size_t findCar(const string &) const = 0;

    virtual void addCar(const Car &) = 0;

    virtual Car deleteCar(const string &) = 0;

    virtual Car modifyCar(const Car &) = 0;

    virtual carList copyList(const carList &) = 0;

    virtual ~RepoAbstract() = default;
};

class Repository: public RepoAbstract{
private:
    carList cars; // lista de masini
public:

    Repository() noexcept = default; // constructor implicit

    /*
        Returneaza lista de masini a repository-ului
        @pre: true
        @post: lista de masini a repo-ului
    */
    const carList &getCars() const override;

    /*
        Size-ul listei de masini
        @pre: true
        @post: size-ul listei de masini
    */
    size_t getSize() const noexcept override;

    /*
        Cauta o masina dupa un anumit id si ii returneaza pozitia.
        @pre: string -> numar de inmatriculare
        @post: pozitia masinii
        @exception: masina nu exista in lista
    */

    size_t findCar(const string &) const override;

    /*
        Adauga o masina la lista de masini
        @pre: Car -> obiect de tip Car valid
        @post: obiectul de tip Car adaugat la lista de masini
    */
    void addCar(const Car &) override;

    /*
        Sterge o masina din lista de masini
        @pre: string -> numar de inmatriculare
        @post: masina stearsa
        @exception: nu exista masina in lista
    */
    Car deleteCar(const string &) override;

    /*
        Modifica o masina din lista de masini
        @pre: string -> numar de inmatriculare
              string -> producator
              string -> model
              string -> tip
        @post: masina modificata
        @exception: nu exista masina in lista
    */
    Car modifyCar(const Car &) override;

    /*
        Functie de copiere (deep copy)
        @pre: true
        @post: lista de masini este copiata
    */
    carList copyList(const carList &) override;

    // destructor virtual -> pentru ca clasele derivate sa isi apeleze constructorul in functie de obiectul lor
//    ~Repository() override = default;
};

// using inheritance to create a file repository

class FileRepository : public Repository {
private:
    string fileName; // numele fisierului in care facem scriere/citire
    void loadFromFile(); // functie de incarcare din fisier
    void writeToFile(); // functie de stocare in fisier
public:
    // constructorul pentru clasa derivata
    explicit FileRepository(const string &file) {
        this->fileName = file;
        this->loadFromFile();
    }

    // metode suprascrise din clasa de baza
    void addCar(const Car &) override;

    Car deleteCar(const string &) override;

    Car modifyCar(const Car &) override;
};

class RepoLab: public RepoAbstract {
private:
    unordered_map<string, Car> cars; // map-ul unde tinem masinile
    carList toUse; // pentru operatii
    double randNr = 0.75; // probabilitate random intre 0 si 1
public:
    //RepoLab() = default; // constructor trivial

    const carList &getCars() const override; // functia de 'get all' -> pentru map

    size_t getSize() const noexcept override; // functia de 'get size' -> pentru map

    size_t findCar(const string &) const override; // functia de find -> pentru map

    void addCar(const Car&) override; // functia de adaugare -> pentru map

    Car deleteCar(const string&) override; // functia de stergere -> pentru map

    Car modifyCar(const Car &) override; // functia de modificare -> pentru map

    carList copyList(const carList &) override; // functia de copiere -> pentru map
};



