#pragma once
#include <iostream>
#include "../Headers/Service.h"

class UI
{
private:
	// UI-ul contine un service pentru masini
	Service carService;
public:
	// constructorul implicit al UI-ului
	UI() noexcept;

	// afiseaza comenzile disponibile
	void uiCommands() const;

	/*
		Functie de afisare a masinilor
		@pre: true
		@post: lista de masini
		@eroare: nu exista masini in lista
	*/
	void uiShowCars() const;

	/*
		Functie de adaugare a unei masini
		@pre: true
		@post: masina adaugata
		@eroare: nu se poate adauga masina din cazurile de validitate
	*/
	void uiAddCar();

	/*
		Functie de stergere a unei masini
		@pre: true
		@post: masina stearsa
		@eroare: nu se poate sterge masina, daca nu exista
	*/
	void uiDeleteCar();

	/*
		Functie de cautare a unei masini dupa nr. de inmatriculare
		@pre: true
		@post: masina cautata
		@eroare: masina nu exista
	*/

	void uiFindCar();

	/*
		Functie de modificare a unei masini
		@pre: true
		@post: masina modificata
		@eroare: nu se poate modifica masina, daca nu exista sau parametrii sunt invalizi
	*/
	void uiModifyCar();

	/*
		Functie de filtrare a masinilor dupa producator
		@pre: true
		@post: lista de masini filtrate
		@eroare: lista filtrata este goala
	*/
	void uiFilterByProducer() const;

	/*
		Functie de filtrare a masinilor dupa tip
		@pre: true
		@post: lista de masini filtrate
		@eroare: lista filtrata este goala
	*/
	void uiFilterByType() const;


	// rulare pentru UI
	void uiRun();
};


