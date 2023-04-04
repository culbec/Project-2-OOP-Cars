#pragma once
#include "Repository.h"

class ValidatorException {
private:
	string errorMessage;
public:
	ValidatorException(string message) : errorMessage{message } {}
	string getMessage() { return this->errorMessage; }
};

class Validator
{	
	// nu vom avea o reprezentare privata, deoarece validatorul nu va contine
	// propriu-zis ceva ce il defineste

	// asa ca specificam doar prototipurile functiilor ce se vor ocupa de validare
public:
	// aceste functii se vor ocupa de validarea obiectului & a parametrilor obiectului
	// ne intereseaza valoarea de adevar a validarii, deci tipul va fi bool
	
	/*
		@pre: const Car& refera un obiect de tip Car
		@post: true or false, daca nr. de inmatriculare este valid

		@exception: numarul de inmatriculare nu reprezinta un numar valid din Romania

		Exemplu: CJ18CEV sau B777CCC -> 7 caractere: 2 litere - 2 cifre - 3 litere
				  exceptie Bucuresti -> 6/7 caractere: 1 litera -> 2/3 cifre - 3 litere
	*/

	bool validateRegNumber(const Car&) const;


	/*
		@pre: const Car& refera un obiect de tip Car
		@post: true or false, daca producator este valid

		@exception: producatorul reprezinta un string care nu incepe cu majuscula
					si care contine alte caractere pe langa litere
	*/

	bool validateProducer(const Car&) const;

	/*
		@pre: const Car& refera un obiect de tip Car
		@post: true or false, daca modelul este valid
		@exception: daca modelul este vid
	*/

	bool validateModel(const Car&) const;

	/*
		@pre: const Car& refera un obiect de tip Car
		@post: true or false, daca tipul este valid
		@exception: daca tipul este vid
	*/

	bool validateType(const Car&) const;

	/*
		@pre: const Car& refera un obiect de tip Car
			  const Repository& refera repository-ul de masini
		@post: true or false, daca masina este valida

		@exception: nu are parametrii valizi sau exista deja in lista
	*/

	bool validateCar(const Car&, const Repository&) const;
};

