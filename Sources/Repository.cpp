#include "../Headers/Repository.h"
#include <memory>
#include <random>

const carList &Repository::getCars() const{ return this->cars; }

size_t Repository::getSize() const noexcept { return this->cars.size(); }

size_t Repository::findCar(const string &regNumberToFind) const {
    auto found = std::find_if(this->cars.begin(), this->cars.end(), [regNumberToFind](const Car &car) {
        return car.getRegNumber() == regNumberToFind;
    });

    if (found != this->cars.end())
        return found - this->cars.begin();
    throw RepositoryException("Masina nu exista in lista!\n");
}

void Repository::addCar(const Car &carToAdd) {
    this->cars.push_back(carToAdd);
}

Car Repository::deleteCar(const string &regNumberOfCarToDelete) {
    try {
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
    carList copyList;
    copy(list.begin(), list.end(), back_inserter(copyList));

    return copyList;
}

void FileRepository::loadFromFile() {
    // initializam stream-ul de citire
    ifstream fin(this->fileName);

    // verificam daca s-a deschis
    if (!fin.is_open()) {
        throw RepositoryException("Error opening: " + this->fileName);
    }

    while (!fin.eof()) {
        // preluam parametrii din fisier dupa delimitatorul ','
        string regNumber, producer, model, type;
        std::getline(fin, regNumber, ',');
        if (regNumber.empty()) // check pentru linii goala
            break;
        std::getline(fin, producer, ',');
        std::getline(fin, model, ',');
        std::getline(fin, type, '\n');

        // adaugam masina in lista de masini apeland metoda din clasa de baza
        // daca am fi apelat metoda din clasa derivata, am fi intrat intr-un loop continuu
        // deoarece metoda ar fi incercat sa prelucreze fisierul in continuu
        Car car{regNumber, producer, model, type};
        Repository::addCar(car);
    }

    fin.close();
}

void FileRepository::writeToFile() {
    // initializam stream-ul de scriere
    ofstream fout(this->fileName);

    // verificam daca s-a deschis
    if (!fout.is_open()) {
        throw RepositoryException("Error open: " + this->fileName);
    }

    for (const auto &car: this->getCars()) {
        fout << car.getRegNumber() << "," << car.getProducer() << "," << car.getModel() << "," << car.getType();
        fout << std::endl;
        std::flush(fout);
    }

    fout.close();
}

void FileRepository::addCar(const Car &car) {
    Repository::addCar(car); // apelam metoda din clasa de baza
    this->writeToFile(); // scriem in fisier
}

Car FileRepository::deleteCar(const string &regNumber) {
    Car deleted = Repository::deleteCar(regNumber); // apelam metoda din clasa de baza
    this->writeToFile(); // scriem in fisier
    return deleted;
}

Car FileRepository::modifyCar(const Car &car) {
    Car modified = Repository::modifyCar(car); // apelam metoda din clasa de baza
    this->writeToFile(); // scriem in fisier
    return modified;
}


// FUNCTII IMPLEMENTATE PENTRU REPO CU MAP
const carList &RepoLab::getCars() const{

    return this->toUse;
}

size_t RepoLab::getSize() const noexcept {
    return this->cars.size();
}

size_t RepoLab::findCar(const std::string &regNumberToFind) const {
    int i = 0;
    for (const auto &car: this->toUse) {
        if (car.getRegNumber() == regNumberToFind)
            return i;
        i++;
    }
    throw RepositoryException("Masina nu exista in lista!\n");
}

void RepoLab::addCar(const Car &car) {
    /*std::mt19937 mt {std::random_device{}()};
    std::uniform_real_distribution<> dist(0, 1);
    this->randNr = dist(mt);
    if(randNr < 0.5)
        throw RepositoryException("mesaj");*/
    this->cars.insert({car.getRegNumber(), car});
    this->toUse.push_back(car);
}

Car RepoLab::deleteCar(const std::string &regToDelete) {
    for (auto iter = this->cars.begin(); iter != this->cars.end(); iter++)
        if (iter->second.getRegNumber() == regToDelete) {
            auto deleted = iter->second;
            this->cars.erase(iter);
            for(auto iterV = this->toUse.begin(); iterV != this->toUse.end(); iterV++)
                if(iterV->getRegNumber() == regToDelete) {
                    this->toUse.erase(iterV);
                    return deleted;
                }
        }
    throw RepositoryException("Nu se poate modifica deoarece nu exista masina in lista!\n");
}

Car RepoLab::modifyCar(const Car &car) {
    for (auto &_car: this->cars)
        if (_car.second == car) {
            auto modified = _car.second;
            this->cars.at(_car.first) = car;
            for(auto & i : this->toUse)
                if(i == car) {
                    i = car;
                    return modified;
                }
        }
    throw RepositoryException("Nu se poate modifica deoarece nu exista masina in lista!\n");
}

carList RepoLab::copyList(const carList &_cars) {
    carList carsVector;
    for (auto &car: this->cars)
        carsVector.push_back(car.second);
    return carsVector;
}