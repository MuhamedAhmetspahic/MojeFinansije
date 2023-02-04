#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "osoba.h"


bool registracija(Osoba& o) {
	system("cls");
	std::cout << "---------- Registracija profila ----------" << std::endl;
	bool postoji = false;
	std::ifstream registracija;
	registracija.open("korisnici.txt");
	std::cin >> o;
	std::string pomKorisnicko;
	pomKorisnicko=o.getKorisnicko();
	do {
		std::string provjera;
		while (!registracija.eof()) {
			registracija >> provjera;
			if (provjera == pomKorisnicko) {
				std::cout << "Vec postoji profil sa istim korisnickim imenom!" << std::endl;
				system("pause");
				return false;
			}
		}
		if (provjera == "") {
			break;
		}
	} while (postoji==false);
	registracija.close();

	if (postoji == false) {
		std::ofstream spremi;
		spremi.open("korisnici.txt", std::ios::app);
		spremi << o.getKorisnicko() << " " << o.getIme() << " " << o.getPrezime() << " " << o.getSifra() << std::endl;
		spremi.close();
		std::cout << "Uspjesno ste se registrovali!" << std::endl;
		system("pause");
		return true;
	}
	

}


bool login(Osoba& o) {
	system("cls");
	std::cout << "-------------- Prijava --------------" << std::endl;
	std::string pomKorisnicko;
	std::cout << "Unesite vase korisnicko ime: ";
	std::cin >> pomKorisnicko;
	bool pronadjen = false;
	std::ifstream ucitaj;
	ucitaj.open("korisnici.txt");
	do {
		std::string provjera;
		while (!ucitaj.eof()) {
			ucitaj >> provjera;
			if (provjera == pomKorisnicko) {
				std::cout << "Profil je pronadjen!" << std::endl;
				o.postaviKorisnicko(provjera);
				ucitaj >> provjera;
				o.postaviIme(provjera);
				ucitaj >> provjera;
				o.postaviPrezime(provjera);
				ucitaj >> provjera;
				o.postaviSifra(provjera);
				std::cout << "Unesite sifru: ";
				std::string pomSifra;
				std::cin >> pomSifra;
				if (pomSifra == o.getSifra()) {
					pronadjen = true;
				}
				else {
					std::cout << "Neispravna sifra!" << std::endl;
					system("pause");
					return false;
				}
				
			}

		}
		if (provjera == "") {
			std::cout << "Profil nije pronadjen!" << std::endl;
			system("pause");
			return false;
		}
	} while (pronadjen == false);
	ucitaj.close();
	return true;
}