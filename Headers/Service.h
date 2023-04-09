#pragma once

#include "Validator.h"

class ServiceException {
private:
    string errorMessage;
public:
    explicit ServiceException(string message) : errorMessage(std::move(message)) {}

    string getMessage() { return this->errorMessage; }
};

class Service {
    // declaram clasele Repository si Validator ca friend
    friend class Repository;

    friend class Validator;

private:
    // fiecare instanta de tip Service va contine un repository propriu si un validator propriu
    Validator carValidator;
    Repository carRepository;

public:
    // definim un constructor implicit
    Service() noexcept;

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


    ///*
    //	Functie de filtrare dupa producator
    //	@pre: se primeste un parametru de tip string, care reprezinta producatorul masinii dupa care se filtreaza
    //	@post: lista de masini cu producatorul dat
    //	@exception: nu exista masini cu producatorul dat
    //*/

    //carList filterByProducer (const string&) const;

    ///*
    //	Functie de filtrare dupa tip
    //	@pre: se primeste un paremetru de tip string, care reprezinta tipul masinii dupa care se filtreaza
    //	@post: lista de masini cu tipul dat
    //	@exception: nu exista masini cu tipul dat
    //*/

    //carList filterByType(const string&, bool(*) const;

    carList filter(const string &, bool(*compareMethod)(const Car &, const string &)) const;

    static bool compareByProducer(const Car &car, const string &producer) {
        return car.getProducer() == producer;
    }

    static bool compareByType(const Car &car, const string &type) {
        return car.getType() == type;
    }

};