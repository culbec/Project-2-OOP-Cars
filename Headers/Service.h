#pragma once

#include "Validator.h"
#include "Repository.h"
#include "Spalatorie.h"
#include <algorithm>

using std::sort;
using std::find_if;
using std::copy_if;

class ServiceException : std::exception {
private:
    string errorMessage;
public:
    explicit ServiceException(string message) : errorMessage(std::move(message)) {}

    string getMessage() { return this->errorMessage; }
};

class Service {
private:
    // fiecare instanta de tip Service va contine un repository propriu si un validator propriu
    Repository carRepository;
    WashingList washingList;

public:
    // definim un constructor implicit
    Service() noexcept = default;

    // functie care returneaza repo-ul service-ului
    //const Repository& getRepository() const;

    const carList &getCars() const;

    //// functie care returneaza validatorul service-ului
    //Validator getValidator() const;

    /*
        Se adauga o masina in lista de masini.
        @pre: se primesc 4 parametrii de tip string, ce reprezinta parametrii masinii de adaugat
        @post: masina se adauga
        @exception: masina invalida sau deja exista in lista.
    */

    bool addCarService(const string &, const string &, const string &, const string &);

    /*
        Se modifica o masina din lista de masini
        @pre: se primesc 4 parametrii, de tip string, ce reprezinta:
              - numarul de inmatriculare al masinii de modificat;
              - parametrii ce masinii ce vor fi modificati;
        @post: masina cu parametrii specificati se modifica;
        @exception: masina invalida sau nu exista masina in lista;
    */

    Car modifyCarService(const string &, const string &, const string &, const string &);

    /*
        Se sterge o masina din lista de masini
        @pre: se primeste un parametru, de tip string, ce reprezinta numarul de inmatriculare al masinii de sters
        @post: se sterge masina
        @exception: nu exista masina in lista
    */

    Car deleteCarService(const string &);

    /*
        Cautare masina dupa numar de inmatriculare.
        @pre: parametru de tip string, ce reprezinta numarul masinii de inmatriculare al masinii de gasit
        @post: masina cu numarul de inmatriculare
        @exception: nu exista masina in lista
    */

    Car findCarService(const string &);

    carList filter(const string &, bool(*compareMethod)(const Car &, const string &)) const;

    static bool compareByProducer(const Car &car, const string &producer) {
        return car.getProducer() == producer;
    }

    static bool compareByType(const Car &car, const string &type) {
        return car.getType() == type;
    }

    // functii de sortare
    // static carList generalSort(carList, bool(*compareMethod)(const Car &, const Car &));

    static carList sortRegNumber(const carList &);

    static carList sortType(const carList &);

    static carList sortProducerModel(const carList &);

    /**
     * @brief Returneaza lista masinilor pentru spalat
     * @pre true
     * @post true
     * @return lista masinilor pentru spalat
     */
     WashingList getWashingList() const;

    /**
     * @brief Adauga o masina in lista pentru masinile de spalat
     * @pre Masina cu numarul de inmatriculare exista in lista
     * @post Se adauga masina in lista de masini de spalat
     * @exception Nu exista masina in lista de masini
     */
    void addToWashingList(const string &);

    /**
     * @brief Goleste lista masinilor de spalat
     * @pre true
     * @post Lista masinilor de spalat se goleste
     */
    void clearWashingList();

    /**
     * @brief Genereaza o lista random de masini de spalat
     * @pre true
     * @post Se genereaza lista random de masini de spalat
     */
    void randomWashingList(unsigned int, const vector<Car> &);

};