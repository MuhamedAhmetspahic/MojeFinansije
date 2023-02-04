#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "osoba.h"
#include "kasa.h"
#include "datum.h"
#include "kategorija.h"

void provjeriFajl(Osoba& o) {
	std::string imeFajla;
	imeFajla = o.getKorisnicko() + "-KASE";
	Kasa k;
	std::ifstream ucitaj;
	ucitaj.open(imeFajla);
	if (!ucitaj) {
		std::cout << "Potrebno je postavini pocetne podatke zbog prve prijave!" << std::endl;
		std::cout << "Vase prvo spremiste: " << std::endl;
		std::ofstream zapis;
		zapis.open(imeFajla);
		k.setNaziv();
		k.setStanje();
		zapis << "Naziv: " << k.getNaziv() << std::endl;
		zapis << "Stanje: " << k.getStanje() << std::endl;
		zapis << std::endl;
		zapis.close();
	}
	ucitaj.close();
	system("cls");

	imeFajla = o.getKorisnicko() + "-KATEGORIJE";
	Kategorija kat;
	ucitaj.open(imeFajla);
	if (!ucitaj) {
		std::cout << "Vasa prva kategorija: " << std::endl;
		std::ofstream zapis;
		zapis.open(imeFajla);
		std::cin >> kat;
		zapis << "Naziv: " << kat << std::endl;
		zapis.close();
	}
	ucitaj.close();

	system("cls");

}

std::string dajNazivFajlaKase(Osoba& o) {
	std::string imeFajla;
	imeFajla = o.getKorisnicko() + "-KASE";
	return imeFajla;
}

std::string dajNazivFajlaTransakcije(Osoba& o) {
	std::string imeFajla;
	imeFajla = o.getKorisnicko() + "-TRANSAKCIJE";
	return imeFajla;
}

std::string dajNazivFajlaKategorije(Osoba& o) {
	std::string imeFajla;
	imeFajla = o.getKorisnicko() + "-KATEGORIJE";
	return imeFajla;
}

std::vector<Kasa> ucitajIzFajla(std::string nazivFajla) {
	std::ifstream ucitaj;
	ucitaj.open(nazivFajla);
	if (!ucitaj) {
		std::cout << "Greska sa fajlom!" << std::endl;
	}

	Kasa k;
	std::vector<Kasa>kase;

	std::string provjera;
	float provjeraStanje;

	bool kraj = false;

	std::vector<std::string>nazivi;
	std::vector<float>stanja;

	do {
		while (!ucitaj.eof()) {
			ucitaj >> provjera;
			if (provjera == "Naziv:") {
				ucitaj >> provjera;
				nazivi.push_back(provjera);
			}
			if (provjera == "Stanje:") {
				ucitaj >> provjeraStanje;
				stanja.push_back(provjeraStanje);
			}

			if (provjera == "") {
				kraj = true;
				break;
			}

		}

	} while (kraj = false);

	int vektorNazivi, vektorStanja;
	vektorNazivi = nazivi.size();
	vektorStanja = stanja.size();

	for (int i = 0; i < vektorNazivi; i++) {
		k.postaviNaziv(nazivi[i]);
		k.postaviStanje(stanja[i]);
		kase.push_back(k);
	}


	int brojSpremista;
	brojSpremista = kase.size();

	for (int k = 0; k < brojSpremista; k++) {
		std::cout << k + 1 << ". " << kase[k].getNaziv() << " - " << kase[k].getStanje() << " KM" << std::endl;
	}
	ucitaj.close();

	return kase;
}


void spremiNovoStanjeKasa(std::vector<Kasa>& k, std::string nazivFajla) {
	std::ofstream spremi;
	spremi.open(nazivFajla);
	int brojSpremista;
	brojSpremista = k.size();
	for (int i = 0; i < brojSpremista; i++) {
		spremi << "Naziv: " << k[i].getNaziv() << std::endl;
		spremi << "Stanje: " << static_cast<float> (k[i].getStanje()) << std::endl;
	}
	spremi << std::endl;
	spremi.close();
	std::cout << "Novo stanje uspjesno spremljeno!" << std::endl;
}

void spremiTransakcije(Osoba& o, datum d, float prosloStanje, float iznos, std::string vrstaTransakcije, std::string spremiste, std::string kategorija) {
	std::string nazivFajla;
	nazivFajla=dajNazivFajlaTransakcije(o);
	std::ofstream zapis;
	zapis.open(nazivFajla, std::ios::app);
	zapis << "Dan: " << d.getDan() << std::endl;
	zapis << "Mjesec: " << d.getMjesec() << std::endl;
	zapis << "Godina: " << d.getGodina() << std::endl;
	zapis << "PS: " << prosloStanje << std::endl;
	if (vrstaTransakcije == "priliv") {
		zapis << "Priliv: " << iznos << std::endl;
		zapis << "Kategorija: /" << std::endl;
		zapis << "NS: " << prosloStanje + iznos << std::endl;
	}
	else {
		zapis << "Odliv: " << iznos << std::endl;
		zapis << "Kategorija: " << kategorija << std::endl;
		zapis << "NS: " << prosloStanje - iznos << std::endl;
	}
	zapis << "Spremiste: " << spremiste << std::endl;
	zapis << std::endl;
	zapis.close();



}

std::vector<Kategorija> ucitajKategorije(std::string nazivFajla) {
	std::ifstream ucitaj;
	std::string provjera;
	std::vector<Kategorija>kategorije;
	std::vector<std::string>nazivi;
	Kategorija k;

	ucitaj.open(nazivFajla);
	if (!ucitaj) {
		std::cout << "Nema kategorija! - Prvo dodajte kategorije!" << std::endl;
	}
	else {
		while (!ucitaj.eof()) {
			ucitaj >> provjera;
			if (provjera == "Naziv:") {
				ucitaj >> provjera;
				nazivi.push_back(provjera);
			}

			if (provjera == "") {
				break;
			}
		}

		int velicinaVektor;
		velicinaVektor = nazivi.size();

		for (int j = 0; j < velicinaVektor; j++) {
			k.postaviKategorija(nazivi[j]);
			kategorije.push_back(k);
		}
	}
	ucitaj.close();

	return kategorije;


}