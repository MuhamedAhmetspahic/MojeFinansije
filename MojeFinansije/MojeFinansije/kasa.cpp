#include <iostream>
#include <fstream>
#include "kasa.h"

void Kasa::setNaziv() {
	std::cout << "Naziv: ";
	std::cin >> this->naziv;
}

void Kasa::setStanje() {
	std::cout << "Stanje: ";
	std::cin >> this->stanje;
}

std::string Kasa::getNaziv() {
	return this->naziv;
}

float Kasa::getStanje() {
	return this->stanje;
}

void Kasa::postaviNaziv(std::string nazivKase) {
	this->naziv = nazivKase;
}

void Kasa::postaviStanje(double stanjeKase) {
	this->stanje = stanjeKase;
}

