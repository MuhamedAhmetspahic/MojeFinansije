#pragma once
#include <iostream>
#include <fstream>
#include "datum.h"
#include "osoba.h"
#include "fajl.h"
#include "kasa.h"
#include <math.h>
#include "kategorija.h"

void novaTransakcija(Osoba& o) {
	int izbor;
	do {
		system("cls");
		std::cout << "---------- Nova transakcija ----------" << std::endl;
		std::cout << "1. Priliv" << std::endl;
		std::cout << "2. Odliv" << std::endl;
		std::cout << "0. Nazad" << std::endl;
		std::cout << "-> ";
		std::cin >> izbor;
	} while (izbor < 0 && izbor>2);

	if (izbor == 1) {
		system("cls");
		std::string nazivKase;
		std::cout << "Odaberite spremiste novca!" << std::endl;
		std::cout << "Vasa spremista novca: " << std::endl;
		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKase(o);

		std::vector<Kasa>kase;
		kase = ucitajIzFajla(nazivFajla);

		int odabirKase;
		float dodatnaKolicina;
		do {
			std::cout << "-> ";
			std::cin >> odabirKase;
		} while (odabirKase<=0 || odabirKase>kase.size());
		system("cls");

		do {
			std::cout << "Iznos koji zelite dodati [KM]: ";
			std::cin >> dodatnaKolicina;
		} while (dodatnaKolicina<=0);

	
		float prosloStanje = kase[odabirKase - 1].getStanje();
		std::string nazivSpremista;
		nazivSpremista = kase[odabirKase - 1].getNaziv();

		kase[odabirKase - 1].postaviStanje(kase[odabirKase - 1].getStanje() + dodatnaKolicina); //izmjena stanja u vektoru

		spremiNovoStanjeKasa(kase, nazivFajla); //spremanje novog stanja u fajl
		std::cin.ignore();

		datum d;
		d.postaviDatum();

		std::string vrstaTransakcije;
		vrstaTransakcije = "priliv";

		spremiTransakcije(o, d, prosloStanje, dodatnaKolicina, vrstaTransakcije, nazivSpremista, nazivSpremista);
		std::cout << "Uspjesno spremljeno!" << std::endl;
		system("pause");
		system("cls");


	}


	else if (izbor == 2) {
		system("cls");
		std::string nazivKase;
		std::cout << "Odaberite spremiste novca!" << std::endl;
		std::cout << "Vasa spremista novca: " << std::endl;
		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKase(o);

		std::vector<Kasa>kase;
		kase = ucitajIzFajla(nazivFajla);

		int odabirKase;
		float odliv;
		do {
			std::cout << "-> ";
			std::cin >> odabirKase;
		} while (odabirKase<=0 || odabirKase>kase.size());
		system("cls");

		
		do {
			std::cout << "Iznos koji zelite uzeti iz spremista - odliv [KM]: ";
			std::cin >> odliv;
		} while (odliv<=0);


		std::string nazivFajlaKat;
		nazivFajlaKat = dajNazivFajlaKategorije(o);

		std::cout << "Kategorija potrosnje: " << std::endl;
		std::vector<Kategorija>kategorije;
		kategorije = ucitajKategorije(nazivFajlaKat);

		int velicinaKat;
		velicinaKat = kategorije.size();

		for (int i = 0; i < velicinaKat; i++) {
			std::cout << i + 1 << ". " << kategorije[i].getKategorija() << std::endl;
		}
		std::cout << "-> ";
		int izborKat;
		std::cin >> izborKat;
		std::string nazivKat;
		nazivKat = kategorije[izborKat - 1].getKategorija();

		float prosloStanje = kase[odabirKase - 1].getStanje();
		std::string nazivSpremista;
		nazivSpremista = kase[odabirKase - 1].getNaziv();

		bool dovoljno = false;
		do {
			if (prosloStanje < odliv) {
				std::cout << "Nedovoljno sredstava!" << std::endl;
				dovoljno = true;
				break;
			}
			else {
				kase[odabirKase - 1].postaviStanje(kase[odabirKase - 1].getStanje() - odliv);
			}

			spremiNovoStanjeKasa(kase, nazivFajla); //spremanje novog stanja u fajl
			std::cin.ignore();

			datum d;
			d.postaviDatum();

			std::string vrstaTransakcije;
			vrstaTransakcije = "odliv";

			spremiTransakcije(o, d, prosloStanje, odliv, vrstaTransakcije, nazivSpremista, nazivKat);
			std::cout << "Uspjesno spremljeno!" << std::endl;
			dovoljno = true;
			break;
		} while (dovoljno = false);
		system("pause");
		system("cls");
		

	}




}


void urediSpremista(Osoba& o) {
	system("cls");
	int izbor;
	do {
		std::cout << "---------- Spremista ----------" << std::endl;
		std::cout << "1. Dodaj spremiste" << std::endl;
		std::cout << "2. Obrisi spremiste" << std::endl;
		std::cout << "3. Ispis spremista i stanja" << std::endl;
		std::cout << "0. Nazad" << std::endl;
		std::cout << "-> ";
		std::cin >> izbor;
	} while (izbor<0 || izbor>3);


	if (izbor == 1) {
		system("cls");
		std::string nazivKase;
		std::cout << "Vasa spremista novca: " << std::endl;
		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKase(o);

		std::vector<Kasa>kase;
		kase = ucitajIzFajla(nazivFajla);

		int brNovihSpremista;
		std::cout << "Koliko zelite unijeti novih spremista: ";
		std::cin >> brNovihSpremista;
		system("cls");
		Kasa k;
		std::string pomNaziv;
		float pomStanje;

		for (int i = 0; i < brNovihSpremista; i++) {
			std::cout << "Unos " << i + 1 << ". " << std::endl;
			std::cout << "Naziv: ";
			std::cin >> pomNaziv;
			std::cout << "Stanje: ";
			std::cin >> pomStanje;

			k.postaviNaziv(pomNaziv);
			k.postaviStanje(pomStanje);
			kase.push_back(k);

			system("cls");
		}

		int velicinaVektora;
		velicinaVektora = kase.size();

		std::ofstream zapis;
		zapis.open(nazivFajla);

		for (int j = 0; j < velicinaVektora; j++) {
			zapis << "Naziv: " << kase[j].getNaziv() << std::endl;
			zapis << "Stanje: " << kase[j].getStanje() << std::endl;
			zapis << std::endl;
		}
		zapis.close();
		std::cout << "Uspjesno spremljeno!" << std::endl;
		system("pause");

	}
	else if (izbor == 2) {
		system("cls");
		std::string nazivKase;
		std::cout << "Vasa spremista novca: " << std::endl;
		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKase(o);

		std::vector<Kasa>kase;
		kase = ucitajIzFajla(nazivFajla);

		int brBrisanje, velicinaVektor;
		velicinaVektor = kase.size();
		do {
			std::cout << "Unesite redni broj spremista koje zelite obrisati: ";
			std::cin >> brBrisanje;
		} while (brBrisanje <= 0 || brBrisanje > velicinaVektor);

		kase.erase(kase.begin()+brBrisanje-1);

		std::cout << "Uspjesno obrisano!" << std::endl;

		velicinaVektor = kase.size();
		std::ofstream zapis;
		zapis.open(nazivFajla);

		for (int j = 0; j < velicinaVektor; j++) {
			zapis << "Naziv: " << kase[j].getNaziv() << std::endl;
			zapis << "Stanje: " << kase[j].getStanje() << std::endl;
			zapis << std::endl;
		}
		zapis.close();
		system("pause");

	}
	else if (izbor == 3) {
		system("cls");
		std::string nazivKase;
		std::cout << "Vasa spremista novca: " << std::endl;
		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKase(o);

		std::vector<Kasa>kase;
		kase = ucitajIzFajla(nazivFajla);
		
		system("pause");


	}

}

void urediKategorije(Osoba& o) {
	system("cls");
	int izbor;
	do {
		std::cout << "---------- Kategorije ----------" << std::endl;
		std::cout << "1. Dodaj kategoriju" << std::endl;
		std::cout << "2. Obrisi kategoriju" << std::endl;
		std::cout << "3. Ispis kategorija" << std::endl;
		std::cout << "0. Nazad" << std::endl;
		std::cout << "-> ";
		std::cin >> izbor;
	} while (izbor < 0 || izbor>3);

	if (izbor == 1) {
		system("cls");
		std::cout << "Koliko zelite dodati novih kategorija: ";
		int brNovihKat;
		std::cin >> brNovihKat;

		std::vector<Kategorija>kategorije;
		Kategorija k;

		for (int i = 0; i < brNovihKat; i++) {
			k.setKategorija();
			kategorije.push_back(k);
		}

		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKategorije(o);
		std::ofstream zapis;
		zapis.open(nazivFajla, std::ios::app);

		for (int j = 0; j < brNovihKat; j++) {
			zapis <<"Naziv: " << kategorije[j].getKategorija() << std::endl;
		}
		zapis.close();
		system("pause");

	}
	else if (izbor == 2) {
		system("cls");
		int brBrisanje;

		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKategorije(o);

		std::vector<Kategorija>kategorije;
		kategorije = ucitajKategorije(nazivFajla);

		int velicinaVektor;
		velicinaVektor = kategorije.size();

		for (int i = 0; i < velicinaVektor; i++) {
			std::cout << i + 1 << ". " << kategorije[i].getKategorija() << std::endl;
		}

		do {
			std::cout << "Koju zelite obrisati kategoriju: ";
			std::cin >> brBrisanje;
		} while (brBrisanje<0 || brBrisanje>velicinaVektor);


		kategorije.erase(kategorije.begin() + brBrisanje - 1);

		std::ofstream zapis;
		zapis.open(nazivFajla);

		velicinaVektor = kategorije.size();

		for (int j = 0; j < velicinaVektor; j++) {
			zapis << "Naziv: " << kategorije[j].getKategorija() << std::endl;
		}
		zapis.close();


		std::cout << "Uspjesno obrisano!" << std::endl;
		system("pause");

	}
	else if (izbor == 3) {
		system("cls");
		std::cout << "---------- Kategorije ----------" << std::endl;
		std::string nazivFajla;
		nazivFajla = dajNazivFajlaKategorije(o);

		std::vector<Kategorija>kategorije;
		kategorije = ucitajKategorije(nazivFajla);

		int velicinaVektor;
		velicinaVektor = kategorije.size();

		for (int i = 0; i < velicinaVektor; i++) {
			std::cout << i + 1 << ". " << kategorije[i].getKategorija() << std::endl;
		}
		system("pause");
	}

	
	
}


void ispisTransakcija(Osoba& o) {
	system("cls");
	std::string nazivFajla;
	nazivFajla = dajNazivFajlaTransakcije(o);
	std::ifstream ucitaj;
	ucitaj.open(nazivFajla);

	datum d;
	std::vector<datum>datumi;

	std::string provjera;
	int provjeraDatum;
	
	std::vector<int>dani;
	std::vector<int>mjeseci;
	std::vector<int>godine;

	std::vector<float>proslaStanja;
	float provjeraPS;

	std::vector<float>novaStanja;
	float provjeraNS;

	std::vector<std::string>spremista;
	std::vector<std::string>tipovi;

	while (!ucitaj.eof()) {
		ucitaj >> provjera;
		if (provjera == "Dan:") {
			ucitaj >> provjeraDatum;
			dani.push_back(provjeraDatum);
		}
		if (provjera == "Mjesec:") {
			ucitaj >> provjeraDatum;
			mjeseci.push_back(provjeraDatum);
		}
		if (provjera == "Godina:") {
			ucitaj >> provjeraDatum;
			godine.push_back(provjeraDatum);
		}
		if (provjera == "PS:") {
			ucitaj >> provjeraPS;
			proslaStanja.push_back(provjeraPS);
		}
		if (provjera == "NS:") {
			ucitaj >> provjeraNS;
			novaStanja.push_back(provjeraNS);
		}
		if (provjera == "Spremiste:") {
			ucitaj >> provjera;
			spremista.push_back(provjera);
		}
		if (provjera == "Kategorija:") {
			ucitaj >> provjera;
			tipovi.push_back(provjera);
		}


		if (provjera == "") {
			break;
		}

	}

	int velicinaVektorDani;
	velicinaVektorDani = dani.size();

	if (velicinaVektorDani != 0) {

		for (int i = 0; i < velicinaVektorDani; i++) {
			d.postaviDan(dani[i]);
			d.postaviMjesec(mjeseci[i]);
			d.postaviGodina(godine[i]);
			datumi.push_back(d);
		}

		int velicinaVektoraDatumi;
		velicinaVektoraDatumi = datumi.size();

		Dan dan;

		for (int j = 0; j < velicinaVektoraDatumi; j++) {
			std::cout << datumi[j].getDan() << "." << datumi[j].getMjesec() << "." << datumi[j].getGodina() << ". | "; //datum ispis
			dan.dajDan(datumi[j].getDan(), datumi[j].getMjesec(), datumi[j].getGodina());
			std::cout << "Proslo stanje: " << proslaStanja[j] << " KM ";  //proslo stanje ispis
			float provjera;
			provjera = novaStanja[j] - proslaStanja[j];
			if (provjera > 0) {
				std::cout << "| +" << provjera << " KM";  //priliv odliv ispis kolicine
				std::cout << " | Novo stanje: " << novaStanja[j] << " KM "; //novo stanje ispis
				std::cout << "| Spremiste: " << spremista[j]<<std::endl;

			}
			if (provjera < 0) {
				std::cout << "| " << provjera << " KM";
				std::cout << " | Novo stanje: " << novaStanja[j] << " KM "; //novo stanje ispis
				std::cout << "| Spremiste: " << spremista[j];
				std::cout << " | Kategorija: " << tipovi[j]<<std::endl;
			}
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "Nema transakcija!" << std::endl;
	}


	ucitaj.close();
	system("pause");
}


void statistika(Osoba& o) {
	system("cls");
	std::string nazivFajlaKat;
	nazivFajlaKat = dajNazivFajlaKategorije(o);
	std::ifstream ucitaj;
	ucitaj.open(nazivFajlaKat);
	if (!ucitaj) {
		std::cout << "Napravite prvu transakciju da bi postojala statistika!" << std::endl;
	}
	else {
		std::string provjera;
		Kategorija k;
		std::vector<Kategorija>kategorije;

		while (!ucitaj.eof()) {
			ucitaj >> provjera;
			if (provjera == "Naziv:") {
				ucitaj >> provjera;
				k.postaviKategorija(provjera);
				kategorije.push_back(k);
			}
		}

		int velicinaVektora;
		velicinaVektora = kategorije.size();

		ucitaj.close();

		std::string nazivFajlaTr;
		nazivFajlaTr = dajNazivFajlaTransakcije(o);
		ucitaj.open(nazivFajlaTr);



		std::cout << "---------- Statistika ----------" << std::endl;

		datum d;
		std::vector<datum>datumi;

		//std::string provjera;
		int provjeraDatum;

		std::vector<int>dani;
		std::vector<int>mjeseci;
		std::vector<int>godine;

		std::vector<float>proslaStanja;
		float provjeraPS;

		std::vector<float>novaStanja;
		float provjeraNS;

		std::vector<std::string>spremista;
		std::vector<std::string>tipovi;

		while (!ucitaj.eof()) {
			ucitaj >> provjera;
			if (provjera == "Dan:") {
				ucitaj >> provjeraDatum;
				dani.push_back(provjeraDatum);
			}
			if (provjera == "Mjesec:") {
				ucitaj >> provjeraDatum;
				mjeseci.push_back(provjeraDatum);
			}
			if (provjera == "Godina:") {
				ucitaj >> provjeraDatum;
				godine.push_back(provjeraDatum);
			}
			if (provjera == "PS:") {
				ucitaj >> provjeraPS;
				proslaStanja.push_back(provjeraPS);
			}
			if (provjera == "NS:") {
				ucitaj >> provjeraNS;
				novaStanja.push_back(provjeraNS);
			}
			if (provjera == "Spremiste:") {
				ucitaj >> provjera;
				spremista.push_back(provjera);
			}
			if (provjera == "Kategorija:") {
				ucitaj >> provjera;
				tipovi.push_back(provjera);
			}


			if (provjera == "") {
				break;
			}

		}

		int velicinaVektorDani;
		velicinaVektorDani = dani.size();

		if (velicinaVektorDani != 0) {
			std::vector<float>ukupnoPoDatumu;
			float iznos;
			bool provjeraKat = false;
			int br(0);

			for (int i = 0; i < velicinaVektora; i++) {
				for (int j = 0; j < velicinaVektorDani; j++) {
					if (kategorije[i].getKategorija() == tipovi[j]) {
						iznos = novaStanja[j] - proslaStanja[j];
						if (provjeraKat == false) {
							ukupnoPoDatumu.push_back(iznos);
							provjeraKat = true;
							++br;
						}
						else if (provjeraKat == true) {
							ukupnoPoDatumu[ukupnoPoDatumu.size() - 1] = ukupnoPoDatumu[ukupnoPoDatumu.size() - 1] + iznos;
							++br;
						}
					}
				}
				if (br == 0) {
					ukupnoPoDatumu.push_back(0);
				}
				br = 0;
				provjeraKat = false;

			}

			int velicinaUkupnoPoDatumu;
			velicinaUkupnoPoDatumu = ukupnoPoDatumu.size();

			for (int k = 0; k < velicinaUkupnoPoDatumu; k++) {
				std::cout << k + 1 << ". " << kategorije[k].getKategorija() << " | " << ukupnoPoDatumu[k] << " KM" << std::endl;
			}
		}
		else {
			std::cout << "Nema transakcija za statistiku!" << std::endl;
		}
	}
	system("pause");
}

void mojProfil(Osoba& o) {
	system("cls");
	std::cout << "---------- Profil ----------" << std::endl;
	std::cout << "Ime: " << o.getIme() << std::endl;
	std::cout << "Prezime: " << o.getPrezime() << std::endl;
	std::cout << "Korisnicko ime: " << o.getKorisnicko() << std::endl;
	std::cout << "Sifra: "<<o.getSifra()<<std::endl;
	system("pause");
}

