#pragma once
#include "Repository.h"

class ActiuneUndo{
public:
    virtual void doUndo() = 0; // nu exista implementare, functie pur virtuala

    virtual ~ActiuneUndo() = default;

};

class UndoAdauga: public ActiuneUndo {
private:
    Car addedCar;
    RepoAbstract& carRepo;
public:
    UndoAdauga(const Car& car, RepoAbstract& repo): addedCar{car}, carRepo{repo} {}

    void doUndo() override {
        this->carRepo.deleteCar(this->addedCar.getRegNumber());
    }
};

class UndoDelete: public ActiuneUndo {
private:
    Car deletedCar;
    RepoAbstract& carRepo;
public:
    UndoDelete(const Car& car, RepoAbstract& repo): deletedCar{car}, carRepo{repo} {}

    void doUndo() override {
        this->carRepo.addCar(this->deletedCar);
    }
};

class UndoModifica: public ActiuneUndo {
private:
    Car modifiedCar;
    RepoAbstract& carRepo;
public:
    UndoModifica(const Car& car, RepoAbstract& repo): modifiedCar{car}, carRepo{repo} {}

    void doUndo() override {
        this->carRepo.modifyCar(this->modifiedCar);
    }
};