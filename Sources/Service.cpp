#include "../Headers/Service.h"

Service::Service() noexcept : carRepository(Repository()), carValidator(Validator()) {}

Repository Service::getRepository() const { return this->carRepository; }

bool Service::addCarService(const string& regNumber, const string& producer, const string& model, const string& type) {
	Car carToAdd(regNumber, producer, model, type); // initializing the car to add
	
	this->carValidator.validateCar(carToAdd, this->carRepository); // may have an exception, but it is handled by the repository
	
	// daca e cu succes, adaugam masina
	this->carRepository.addCar(carToAdd);
	return true;
}

Car Service::modifyCarService(const string& regNumber, const string& newProducer, const string& newModel, const string& newType) {
	Car carModified(regNumber, newProducer, newModel, newType); // initializing the modified car

	// salvam erorile de la validari
	string validationErrors = "";
	
	try {
		this->carValidator.validateProducer(carModified); // exception handled by the validator
	}
	catch (ValidatorException& vE) { validationErrors += vE.getMessage(); }
	
	try {
		this->carValidator.validateModel(carModified); // exception handled by the validator
	}
	catch (ValidatorException& vE) { validationErrors += vE.getMessage(); }

	try {
		this->carValidator.validateType(carModified); // exception handled by the validator
	}
	catch (ValidatorException& vE) { validationErrors += vE.getMessage(); }

	if (validationErrors.size() != 0)
		throw ServiceException(validationErrors);

	// daca e cu succes, modificam masina
	Car oldCar = this->carRepository.modifyCar(carModified); // exception handled by the repository
	return oldCar;
}

Car Service::deleteCarService(const string& regNumberToDelete) {
	// returnam direct rezultatul stergerii
	// daca exista exceptie, va fi gestionata de repo
	return this->carRepository.deleteCar(regNumberToDelete);
}

Car Service::findCarService(const string& regNumberToFind) {
	// cautam masina prin intermediul repo
	// si returnam masina de pe pozitia gasita

	const unsigned int foundPosition = this->carRepository.findCar(regNumberToFind);

	return this->carRepository.getCars().at(foundPosition);
}

//carList Service::filterByProducer(const string& producer, bool(*compareMethod)(const Car&, const string&)) const{
//	carList filteredCars; // initializam o lista vida
//
//	// iteram prin lista
//	for (auto iter = this->carRepository.getCars().begin(); iter != this->carRepository.getCars().end(); iter++)
//		if (compareMethod(*iter, producer))
//			filteredCars.push_back(*iter); // adaugam masina in lista filtrata daca e ok
//	
//	// daca lista filtrata e goala, aruncam exceptie
//	if (filteredCars.size() == 0)
//		throw ServiceException("Nu exista masini cu producatorul dat!");
//	
//	// altfel, returnam lista de masini filtrata
//	return filteredCars;
//}
//
//carList Service::filterByType(const string& type) const {
//	carList filtered Cars; // initializam o lista vida
//}

carList Service::filter(const string& whatFilter, bool(*compareMethod)(const Car&, const string&)) const{
	carList filteredCars; // initializam o lista vida

	// iteram prin lista
	carList currentCarList = this->carRepository.getCars();

	for (auto iter = currentCarList.begin(); iter != currentCarList.end(); iter++)
		if (compareMethod(*iter, whatFilter))
			filteredCars.push_back(*iter); // adaugam masina in lista
	
	// aruncam exceptie daca lista e goala
	if (filteredCars.size() == 0)
		throw ServiceException("Nu s-au gasit masini cu parametrul specificat!\n");

	// altfel, returnam lista
	return filteredCars;
}