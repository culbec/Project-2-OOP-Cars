#include "../Headers/UI.h"

using std::cout;
using std::cin;

UI::UI() noexcept: carService(Service()) {}

void UI::uiCommands() {
    cout << "\nComenzile sunt: ";
    cout << "help, show_cars, add_car, delete_car, modify_car, find_car, filter_producer, filter_type, sort_reg_number, sort_type, "
            "sort _producer_model, exit.\n";
}

void UI::uiShowCars() const {
    if (this->carService.getCars().empty()) {
        cout << "\nNu exista masini in lista!\n";
        return;
    }

    cout << "\nLista de masini este: \n\n";

    for (const auto &car: this->carService.getCars())
        cout << car.getRegNumber() << " | " << car.getProducer() << " | " << car.getModel() << " | " << car.getType()
             << std::endl;
}

void UI::uiAddCar() {
    string regNumber, producer, model, type;

    cout << "Nr. de inmatriculare: ";
    cin >> regNumber;
    cout << "Producator: ";
    cin >> producer;
    cout << "Model: ";
    cin >> model;
    cout << "Tip: ";
    cin >> type;

    try {
        this->carService.addCarService(regNumber, producer, model, type);
        cout << "\nMasina adaugata cu succes!\n";
    }
    catch (RepositoryException &rE) { cout << rE.getMessage(); }
    catch (ValidatorException &vE) { cout << vE.getMessage(); }
}

void UI::uiDeleteCar() {
    string regNumber;

    cout << "\nMasinile disponibile pentru stergere sunt urmatoarele: \n";

    this->uiShowCars();

    cout << "\nIntroduceti numarul de inmatriculare al masinii pe care vreti sa o stergeti: ";
    cin >> regNumber;

    try {
        const Car &deletedCar = this->carService.deleteCarService(regNumber);

        cout << "\nS-a sters cu succes masina: ";
        cout << deletedCar.getRegNumber() << " | " << deletedCar.getProducer() << " | " << deletedCar.getModel()
             << " | " << deletedCar.getType() << std::endl;
    }
    catch (RepositoryException &rE) { cout << rE.getMessage(); }
}

void UI::uiModifyCar() {
    string regNumber;
    string newProducer, newModel, newType;

    cout << "Masinile disponibile pentru modificare sunt: \n";

    this->uiShowCars();

    cout << "\nIntroduceti numarul de inmatriculare al masinii pe care doriti sa o modificati: ";
    cin >> regNumber;

    cout << "Producator nou: ";
    cin >> newProducer;
    cout << "Model nou: ";
    cin >> newModel;
    cout << "Tip nou: ";
    cin >> newType;

    try {
        Car modifiedCar = this->carService.modifyCarService(regNumber, newProducer, newModel, newType);

        cout << "\nS-a modificat cu succes masina: ";
        cout << modifiedCar.getRegNumber() << " | " << modifiedCar.getProducer() << " | " << modifiedCar.getModel()
             << " | " << modifiedCar.getType() << std::endl;
    }
    catch (RepositoryException &rE) { cout << rE.getMessage(); }
    catch (ServiceException &sE) { cout << sE.getMessage(); }
}

void UI::uiFindCar() {
    string regNumber;

    cout << "Introduceti numarul de inmatriculare al masinii pe care o cautati: ";
    cin >> regNumber;

    try {
        Car foundCar = this->carService.findCarService(regNumber);

        cout << "\nMasina este: ";
        cout << foundCar.getRegNumber() << " | " << foundCar.getProducer() << " | " << foundCar.getModel() << " | "
             << foundCar.getType() << std::endl;
    }
    catch (RepositoryException &rE) { cout << rE.getMessage(); }
}

void UI::uiFilterByProducer() const {
    string producer;

    cout << "Introduceti producatorul dupa care vreti sa filtrati: ";
    cin >> producer;

    try {
        const carList &filteredCars = this->carService.filter(producer, Service::compareByProducer);

        cout << "\nLista de masini filtrata dupa producatorul " << producer << " este:\n";
        for (const auto &car: filteredCars)
            cout << car.getRegNumber() << " | " << car.getProducer() << " | " << car.getModel() << " | "
                 << car.getType() << std::endl;
    }
    catch (ServiceException &sE) { cout << sE.getMessage(); }
}

void UI::uiFilterByType() const {
    string type;

    cout << "Introduceti tipul dupa care vreti sa filtrati: ";
    cin >> type;

    try {
        const carList &filteredCars = this->carService.filter(type, Service::compareByType);

        cout << "\nLista de masini filtrata dupa tipul " << type << " este:\n";
        for (const auto &car: filteredCars)
            cout << car.getRegNumber() << " | " << car.getProducer() << " | " << car.getModel() << " | "
                 << car.getType() << std::endl;
    }
    catch (ServiceException &sE) { cout << sE.getMessage(); }
}

void UI::uiSortRegNumber() const {
    cout << "\nLista de masini sortata dupa numarul de inmatriculare este:\n";
    for (const auto &car: Service::sortRegNumber(this->carService.getCars()))
        cout << car.getRegNumber() << " | " << car.getProducer() << " | " << car.getModel() << " | "
             << car.getType() << std::endl;
}

void UI::uiSortType() const {
    cout << "\nLista de masini sortata dupa tip este:\n";
    for (const auto &car: Service::sortType(this->carService.getCars()))
        cout << car.getRegNumber() << " | " << car.getProducer() << " | " << car.getModel() << " | "
             << car.getType() << std::endl;
}

void UI::uiSortProducerModel() const {
    cout << "\nLista de masini sortata dupa producator si model este:\n";
    for (const auto &car: Service::sortProducerModel(this->carService.getCars()))
        cout << car.getRegNumber() << " | " << car.getProducer() << " | " << car.getModel() << " | "
             << car.getType() << std::endl;
}

void UI::uiRun() {
    string option;
    while (true) {
        this->uiCommands();
        cout << "Introduceti optiunea: ";
        cin >> option;
        if (option == "help")
            continue;
        else if (option == "show_cars")
            this->uiShowCars();
        else if (option == "add_car")
            this->uiAddCar();
        else if (option == "delete_car")
            this->uiDeleteCar();
        else if (option == "modify_car")
            this->uiModifyCar();
        else if (option == "find_car")
            this->uiFindCar();
        else if (option == "filter_producer")
            this->uiFilterByProducer();
        else if (option == "filter_type")
            this->uiFilterByType();
        else if (option == "sort_reg_number")
            this->uiSortRegNumber();
        else if (option == "sort_type")
            this->uiSortType();
        else if (option == "sort_producer_model")
            this->uiSortProducerModel();
        else if (option == "exit") {
            cout << "Leaving...";
            return;
        } else
            cout << "Optiune invalida.\n";
    }
}
