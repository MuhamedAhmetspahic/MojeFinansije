#include <iostream>
#include "kategorija.h"
#include <string>

void Kategorija::setKategorija() {
	std::cout << "Naziv kategorije: ";
	std::cin >> this->naziv;
}

std::string Kategorija::getKategorija() {
	return this->naziv;
}

void Kategorija::postaviKategorija(std::string naziv) {
	this->naziv = naziv;
}

std::istream& operator>>(std::istream& stream, Kategorija& k) {
	k.setKategorija();
	return stream;
}

std::ostream& operator<<(std::ostream& stream, Kategorija& k) {
	stream << k.getKategorija() << std::endl;
	return stream;
}