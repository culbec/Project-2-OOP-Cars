#include "../Headers/Service.h"

Service::Service() noexcept: carRepository(Repository()) {}

//const Repository& Service::getRepository() const { return this->carRepository; }

const carList &Service::getCars() const { return this->carRepository.getCars(); }

bool Service::addCarService(const string &regNumber, const string &producer, const string &model, const string &type) {
    Car carToAdd(regNumber, producer, model, type); // initializing the car to add

    Validator::validateCar(carToAdd, this->carRepository); // may have an exception, but it is handled by the repository

    // daca e cu succes, adaugam masina
    this->carRepository.addCar(carToAdd);
    return true;
}

Car Service::modifyCarService(const string &regNumber, const string &newProducer, const string &newModel,
                              const string &newType) {
    Car carModified(regNumber, newProducer, newModel, newType); // initializing the modified car

    // salvam erorile de la validari
    string validationErrors;

    try {
        Validator::validateProducer(carModified); // exception handled by the validator
    }
    catch (ValidatorException &vE) { validationErrors += vE.getMessage(); }

    try {
        Validator::validateModel(carModified); // exception handled by the validator
    }
    catch (ValidatorException &vE) { validationErrors += vE.getMessage(); }

    try {
        Validator::validateType(carModified); // exception handled by the validator
    }
    catch (ValidatorException &vE) { validationErrors += vE.getMessage(); }

    if (!validationErrors.empty())
        throw ServiceException(validationErrors);

    // daca e cu succes, modificam masina
    Car oldCar = this->carRepository.modifyCar(carModified); // exception handled by the repository
    return oldCar;
}

Car Service::deleteCarService(const string &regNumberToDelete) {
    // returnam direct rezultatul stergerii
    // daca exista exceptie, va fi gestionata de repo
    return this->carRepository.deleteCar(regNumberToDelete);
}

Car Service::findCarService(const string &regNumberToFind) {
    // cautam masina prin intermediul repo
    // si returnam masina de pe pozitia gasita

    const unsigned int foundPosition = this->carRepository.findCar(regNumberToFind);

    return this->carRepository.getCars().at(foundPosition);
}

carList Service::filter(const string &whatFilter, bool(*compareMethod)(const Car &, const string &)) const {
    carList filteredCars; // initializam o lista vida

    // iteram prin lista
    const carList &currentCarList = this->carRepository.getCars();

    for (const auto &car: currentCarList)
        if (compareMethod(car, whatFilter))
            filteredCars.push_back(car);

    // aruncam exceptie daca lista e goala
    if (filteredCars.empty())
        throw ServiceException("Nu s-au gasit masini cu parametrul specificat!\n");

    // altfel, returnam lista
    return filteredCars;
}