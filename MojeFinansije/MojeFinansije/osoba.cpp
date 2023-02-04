#include <iostream>
#include <cstring>
#include "osoba.h"


void Osoba::setIme() {
	std::cout << "Vase ime: ";
	std::cin>>this->ime;
}

void Osoba::setPrezime() {
	std::cout << "Vase prezime: ";
	std::cin>>this->prezime;
}

void Osoba::setKorisnicko() {
	std::cout << "Vase Korisnicko ime: ";
	std::cin>>this->korisnickoIme;
}

void Osoba::setSifra() {
	std::cout << "Vasa sifra: ";
	std::cin>>this->sifra;
}

std::string Osoba::getIme() {
	return this->ime;
}

std::string Osoba::getPrezime() {
	return this->prezime;
}

std::string Osoba::getKorisnicko() {
	return this->korisnickoIme;
}

std::string Osoba::getSifra() {
	return this->sifra;
}

std::istream& operator>>(std::istream& stream, Osoba& o) {
	o.setIme();
	o.setPrezime();
	o.setKorisnicko();
	o.setSifra();
	return stream;
}

void Osoba::postaviIme(std::string ime) {
	this->ime = ime;
}

void Osoba::postaviPrezime(std::string prezime) {
	this->prezime = prezime;
}

void Osoba::postaviKorisnicko(std::string korisnicko) {
	this->korisnickoIme = korisnicko;
}

void Osoba::postaviSifra(std::string sifra) {
	this->sifra = sifra;
}