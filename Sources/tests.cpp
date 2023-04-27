#include "../Headers/Car.h"
#include "../Headers/Service.h"
#include "../Headers/tests.h"

void domainTests() {
    // initializam o noua masina
    Car someCar("CJ81VSL", "Audi", "Q8", "SUV");

    // testing getters
    assert(someCar.getRegNumber() == "CJ81VSL");
    assert(someCar.getProducer() == "Audi");
    assert(someCar.getModel() == "Q8");
    assert(someCar.getType() == "SUV");

    // testing the copy constructor
    Car copyCar(someCar);
    assert(copyCar == someCar);

    // testing setters
    string oldProducer = someCar.getProducer();
    someCar.setProducer("BMW");
    assert(someCar.getProducer() == "BMW");

    string oldModel = someCar.getModel();
    someCar.setModel("Q7");
    assert(someCar.getModel() == "Q7");

    string oldType = someCar.getType();
    someCar.setType("Sedan");
    assert(someCar.getType() == "Sedan");

    // setting back the old values;
    someCar.setProducer(oldProducer);
    assert(someCar.getProducer() == oldProducer);

    someCar.setModel(oldModel);
    assert(someCar.getModel() == oldModel);

    someCar.setType(oldType);
    assert(someCar.getType() == oldType);

    // suprascriem obiectul curent
    someCar = Car("VS12CAR", "Mercedes", "Vito", "Truck");
    assert(someCar.getRegNumber() == "VS12CAR");
    assert(someCar.getProducer() == "Mercedes");
    assert(someCar.getModel() == "Vito");
    assert(someCar.getType() == "Truck");
}

void repositoryTests() {
    // creating some cars
    Car car1("VS48TUD", "VW", "Tiguan", "SUV");
    Car car2("VS06GOD", "VW", "Passat", "Combi");
    Car car3("CJ14SAL", "Skoda", "Fabia", "Hatch");
    Car car4("BH04SUD", "Renault", "Kadjar", "SUV");
    Car car5("B777BOS", "Dacia", "Logan", "Sedan");

    // initializing a repo
    Repository carRepository;

    // adding some cars
    carRepository.addCar(car1);
    assert(carRepository.getSize() == 1);

    // for deleting a first item coverage
    carRepository.deleteCar("VS48TUD");
    carRepository.addCar(car1);

    carRepository.addCar(car2);
    assert(carRepository.getSize() == 2);

    // for deleting any other car, except for the last one coverage
    carRepository.addCar(car3);
    carRepository.deleteCar("VS06GOD");
    carRepository.deleteCar("CJ14SAL");
    carRepository.addCar(car2);


    // finding the cars
    assert(carRepository.findCar("VS48TUD") == 0);
    assert(carRepository.findCar("VS06GOD") == 1);

    // testing the exception
    try {
        carRepository.findCar("VS06GOT");
        assert(false);
    }
    catch (const RepositoryException &) {
        assert(true);
    }

    // modifying a car and deleting one
    Car newCar("VS48TUD", "Volkswagen", "Touareg", "2016");
    Car modifiedCar = carRepository.modifyCar(newCar);
    assert(modifiedCar == car1);

    assert(carRepository.getCars().at(0) == newCar);

    Car deletedCar = carRepository.deleteCar("VS06GOD");
    assert(deletedCar == car2);
    assert(carRepository.getSize() == 1);

    // trying to modify and delete cars that are not in the list
    try {
        Car badCar("VS48TUT", "Audi", "Q8", "SUV");
        carRepository.modifyCar(badCar);
        assert(false);
    }
    catch (RepositoryException &rE) {
        assert(!rE.getMessage().empty());
    }

    try {
        carRepository.deleteCar("VS48TUT");
        assert(false);
    }
    catch (const RepositoryException &) {
        assert(true);
    }

    // testing the copy list function
    carList carCopyList = Repository::copyList(carRepository.getCars());

    assert(carCopyList.size() == carRepository.getSize());

    // adding the other cars
    carRepository.addCar(car3);
    assert(carRepository.getSize() == 2);

    carRepository.addCar(car4);
    carRepository.addCar(car5);
    assert(carRepository.getSize() == 4);
}

void validatorTests() {
    // initializam un repo si un validator
    Repository carRepo;
    Validator carValid;

    // initializam cateva masini
    Car car1("CJ81VSL", "Volkswagen", "Touareg", "SUV");
    Car car2("B23ZZZ", "Skoda", "Fabia", "Combi");
    Car car3("BH71CLZ", "Peugeot", "508", "Sedan");

    // initializam si cateva masini cu parametrii gresiti
    Car badCarRegNumber1("CJ8VSL", "Citroen", "C4", "Combi");
    Car badCarRegNumber2("B100CZ", "Seat", "Ibiza", "Hatch");
    Car badCarRegNumber3("B01CE", "Aston Marti", "Spider", "Sport");
    Car badCarRegNumber4("", "What", "The", "Sport+");
    Car badCarRegNumber5("B1031ZX", "Volvo", "XC90", "SUV");
    Car badCarRegNumber6("B103ZY2", "Volvo", "C90", "SUV");
    Car badCarRegNumber7("B103ZX1", "Volvo", "XC60", "SUV");
    Car badCarRegNumber8("B101BZ", "Skoda", "Superb", "Sedan");
    Car badCarRegNumber9("B10B1Y", "Seat", "Toledo", "Hatch");
    Car badCarRegNumber10("B10BA_", "Skoda", "Octavia", "Combi");
    Car badCarRegNumber11("B1AXZC", "Skoda", "Fabia", "201");
    Car badCarRegNumber12("B_13JJZ", "Hyundai", "i30", "Hatch");
    Car badCarRegNumber13("CJ#3KZS", "Kia", "xCeed", "Hatch");

    Car badCarProducer1("CJ81VSE", "", "Golf", "Plus");
    Car badCarProducer2("VS08LXX", "volvo", "xda", "plus");
    Car badCarProducer3("VS11LZX", "Volv0)", "xkz", "hatch");

    Car badCarModel("CL88SEL", "Volk", "", "Hatch");

    Car badCarType("CJ11VLS", "Skoda", "Fabia", "");

    Car badCar1("CJ", "volk", "Type R", "Combi");
    Car badCar2("B001KSS", "", "wow", "sport+");
    Car badCar3("", "", "", "");

    // validam masini

    assert(Validator::validateRegNumber(car1) == true);
    carRepo.addCar(car1);

    assert(Validator::validateModel(car2) == true);
    carRepo.addCar(car2);

    assert(carValid.validateCar(car3, carRepo) == true);
    carRepo.addCar(car3);

    assert(Validator::validateType(car3) == true);

    // verificam exceptia daca vrem sa adaugam un element deja adaugat

    try {
        carValid.validateCar(car1, carRepo);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    // verificam exceptia pentru toate cazurile de numar invalid

    try {
        Validator::validateRegNumber(badCarRegNumber1);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber2);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber3);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber4);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber5);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber6);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber7);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber8);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber9);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber10);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber11);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber12);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateRegNumber(badCarRegNumber13);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    // testam exceptia pentru producator invalid
    try {
        Validator::validateProducer(badCarProducer1);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateProducer(badCarProducer2);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        Validator::validateProducer(badCarProducer3);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    // testam exceptia pentru model
    try {
        Validator::validateModel(badCarModel);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    // testam exceptia pentru tip
    try {
        Validator::validateType(badCarType);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    // testam si exceptii multiple
    try {
        carValid.validateCar(badCar1, carRepo);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        carValid.validateCar(badCar2, carRepo);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }

    try {
        carValid.validateCar(badCar3, carRepo);
        assert(false);
    }
    catch (const ValidatorException &) { assert(true); }
}

void serviceTests() {
    // initializam un service
    Service carService;

    //assert(carService.carRepository.getSize() == 0);

    // adaugam cateva masini in service si verificam ca functioneaza adaugarea
    // vom adauga si cateva masini pentru a testa exceptiile

    assert(carService.addCarService("CJ81VSL", "Audi", "Q7", "SUV") == true);

    assert(carService.addCarService("VS15PES", "Mercedes", "Vito", "Utilitara") == true);

    // verificam si exceptii pentru adaugare
    try {
        assert(carService.addCarService("", "Mitsubishi", "LX", "Truck") == true);
    }
    catch (const ValidatorException &) { assert(true); }

    // modificam o masina care exista
    Car unmodifiedCar = carService.modifyCarService("CJ81VSL", "Audi", "RS6", "Sport+");
    Car wasModified = Car(carService.getCars().at(0));

    assert(unmodifiedCar == wasModified);

    assert(unmodifiedCar.getProducer() == wasModified.getProducer());

    assert(unmodifiedCar.getModel() == "Q7");
    assert(wasModified.getModel() == "RS6");

    assert(unmodifiedCar.getType() == "SUV");
    assert(wasModified.getType() == "Sport+");

    // verificam exceptia daca vrem sa modificam o masina cu niste parametrii invalizi
    try {
        carService.modifyCarService("VS15PES", "", "", "");
        assert(false);
    }
    catch (ServiceException &sE) { assert(!sE.getMessage().empty()); }

    // verificam exceptia daca vrem sa modificam o masina care nu exista
    try {
        carService.modifyCarService("B100CZL", "Audi", "Q9", "Driver");
        assert(false);
    }
    catch (const RepositoryException &) { assert(true); }

    // stergem o masina
    Car deletedCar = carService.deleteCarService("CJ81VSL");
    assert(deletedCar.getProducer() == "Audi");
    assert(deletedCar.getModel() == "RS6");
    assert(deletedCar.getType() == "Sport+");

    // incercam sa stergem si o masina care nu exista
    try {
        carService.deleteCarService("B100CZL");
        assert(false);
    }
    catch (const RepositoryException &) { assert(true); }

    // mai adaugam masini pentru a folosi cautarea si filtrarea
    assert(carService.addCarService("BV67LZZ", "Mercedes", "CLA", "Sport+"));
    assert(carService.addCarService("CV16LYZ", "Mercedes", "CLS", "Truck"));
    assert(carService.addCarService("CT01ZIL", "Skoda", "Fabia", "Combi"));

    // cautam dupa numarul de inmatriculare
    assert(carService.findCarService("BV67LZZ").getModel() == "CLA");
    assert(carService.findCarService("CV16LYZ").getProducer() == "Mercedes");

    try {
        carService.findCarService("VS45WED");
        assert(false);
    }
    catch (const RepositoryException &) { assert(true); }

    // filtram dupa producator / tip
    carList filterProducer = carService.filter("Mercedes", Service::compareByProducer);
    assert(filterProducer.size() == 3);

    filterProducer = carService.filter("Skoda", Service::compareByProducer);
    assert(filterProducer.size() == 1);

    // filtram si dupa un producator care nu exista

    try {
        carService.filter("Peugeot", Service::compareByProducer);
        assert(false);
    }
    catch (const ServiceException &) { assert(true); }

    carList filterType = carService.filter("Sport+", Service::compareByType);
    assert(filterType.size() == 1);

    filterType = carService.filter("Combi", Service::compareByType);
    assert(filterType.size() == 1);

    // filtram si dupa un tip care nu exista
    try {
        carService.filter("Sport", Service::compareByType);
        assert(false);
    }
    catch (const ServiceException &) { assert(true); }

}

void runTests() {
    domainTests();
    repositoryTests();
    validatorTests();
    serviceTests();
}