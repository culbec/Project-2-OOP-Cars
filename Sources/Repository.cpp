#include "../Headers/Repository.h"

const carList &Repository::getCars() const { return this->cars; }

size_t Repository::getSize() const noexcept { return this->cars.size(); }

unsigned int Repository::findCar(const string &regNumberToFind) const {
    /*for (auto i = 0; i < this->cars.size(); i++)
        if (this->cars.at(i).getRegNumber() == regNumberToFind)
            return i;*/
    auto found = std::find_if(this->cars.begin(), this->cars.end(), [regNumberToFind](const Car &car) {
        return car.getRegNumber() == regNumberToFind;
    });

    if(found != this->cars.end())
        return found - this->cars.begin();
    throw RepositoryException("Masina nu exista in lista!\n");
}

void Repository::addCar(const Car &carToAdd) {
    this->cars.push_back(carToAdd);
}

Car Repository::deleteCar(const string &regNumberOfCarToDelete) {
    try {
        /*const size_t positionToDelete = findCar(regNumberOfCarToDelete);

        auto iter = this->cars.begin();
        for (auto i = 0; i < positionToDelete; i++)
            iter++;

        Car deletedCar(*iter);
        this->cars.erase(iter);*/

        auto position = this->cars.begin() + findCar(regNumberOfCarToDelete);

        Car deletedCar(*position);
        this->cars.erase(position);

        return deletedCar;
    }
    catch (const RepositoryException &) {
        throw RepositoryException("Nu se poate sterge deoarece nu exista masina in lista!\n");
    }
}

Car Repository::modifyCar(const Car &newCar) {
    try {
        /*const size_t positionToModify = findCar(newCar.getRegNumber());

        auto iter = this->cars.begin();
        for (auto i = 0; i < positionToModify; i++) iter++;

        Car modifiedCar(*iter);
        *iter = Car(newCar.getRegNumber(), newCar.getProducer(), newCar.getModel(), newCar.getType());*/

        auto position = this->cars.begin() + findCar(newCar.getRegNumber());

        Car modifiedCar(*position);
        *position = Car(newCar.getRegNumber(), newCar.getProducer(), newCar.getModel(), newCar.getType());

        return modifiedCar;
    }
    catch (const RepositoryException &) {
        throw RepositoryException("Nu se poate modifica deoarece nu exista masina in lista!\n");
    }
}

carList Repository::copyList(const carList &list) {
    /*carList copyList;

    for (auto &car: list) {
        const Car &copyCar(car);
        copyList.push_back(copyCar);
    }*/

    carList copyList;
    copy(list.begin(), list.end(), back_inserter(copyList));

    return copyList; }