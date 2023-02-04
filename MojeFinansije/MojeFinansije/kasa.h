#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "osoba.h"

class Kasa {
private:
	std::string naziv;
	float stanje;
public:
	void setNaziv();
	void setStanje();

	std::string getNaziv();
	float getStanje();

	void postaviNaziv(std::string nazivKase);
	void postaviStanje(double stanjeKase);

	Kasa() {
		this->stanje = 0;
		this->naziv = "nepoznato";
	}

	~Kasa() = default;

};