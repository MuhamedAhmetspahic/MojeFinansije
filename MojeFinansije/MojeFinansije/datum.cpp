#include <cstring>
#include <iostream>
#include "datum.h"

void datum::setDan() {
	int dan;
	do {
		std::cout << "Unesite dan: ";
		std::cin >> dan;
	} while (dan <= 0 || dan > 31);
	this->dan = dan;
}

void datum::setMjesec() {
	int mjesec;
	do {
		std::cout << "Unesite mjesec: ";
		std::cin >> mjesec;
		if (mjesec < 1 || mjesec>12) {
			std::cout << "Pogresan unos!" << std::endl;
		}
	} while (mjesec < 1 || mjesec>12);
	this->mjesec = mjesec;
}

void datum::setGodina() {
	int godina;
	do {
		std::cout << "Unesite godinu (min.1990): ";
		std::cin >> godina;
		if (godina < 1900) {
			std::cout << "Pogresan unos!" << std::endl;
		}
	} while (godina < 1990);
	this->godina = godina;
}

int datum::getDan() {
	return this->dan;
}

int datum::getMjesec() {
	return this->mjesec;
}

int datum::getGodina() {
	return this->godina;
}

void datum::postaviDatum() {
	bool neispravan(true);
	int maxDana;
	do {
		setDan();
		setMjesec();
		switch (this->mjesec) {
		case 1:
			maxDana = 31;
			break;
		case 2:
			maxDana = 28;
			break;
		case 3:
			maxDana = 31;
			break;
		case 4:
			maxDana = 30;
			break;
		case 5:
			maxDana = 31;
			break;
		case 6:
			maxDana = 30;
			break;
		case 7:
			maxDana = 31;
			break;
		case 8:
			maxDana = 31;
			break;
		case 9:
			maxDana = 30;
			break;
		case 10:
			maxDana = 31;
			break;
		case 11:
			maxDana = 30;
			break;
		case 12:
			maxDana = 31;
			break;
		}
		setGodina();
		if (this->godina % 4 == 0 && this->mjesec == 2) {
			maxDana = 29;
		}
		if (this->dan > maxDana) {
			std::cout << "Pogresan unos (navedeni mjesec moze imati 1-" << maxDana << " dan/a)!" << std::endl;
		}
		else {
			break;
		}
	} while (neispravan == true);

}

void datum::ispisiDatum() {
	std::cout << this->dan << "." << this->mjesec << "." << this->godina << "." << std::endl;
}

void datum::postaviDan(int dan) {
	this->dan = dan;

}

void datum::postaviMjesec(int mjesec) {
	this->mjesec = mjesec;
}

void datum::postaviGodina(int godina) {
	this->godina = godina;
}


void Dan::dajDan(int dan, int mjesec, int godina) {
	dani d;
	
	int kodMjesec;
	if (mjesec == 1 || mjesec == 10) {
		kodMjesec = 0;
	}
	else if (mjesec == 2 || mjesec == 3 || mjesec == 11) {
		kodMjesec = 3;
	}
	else if (mjesec == 4 || mjesec == 7) {
		kodMjesec = 6;
	}
	else if (mjesec == 5) {
		kodMjesec = 1;
	}
	else if (mjesec == 6) {
		kodMjesec = 4;
	}
	else if (mjesec == 8) {
		kodMjesec = 2;
	}
	else if (mjesec == 9 || mjesec==12) {
		kodMjesec = 5;
	}

	int kodGodina;
	if (godina >= 1900 && godina <= 1999) {
		kodGodina = 0;
	}
	else if (godina >= 2000 && godina <= 2099) {
		kodGodina = 6;
	}
	
	int godinaZadnjeDvijeCifre;
	godinaZadnjeDvijeCifre = godina % 100;

	int petaCifra;
	petaCifra = godinaZadnjeDvijeCifre / 4;

	int korak1;
	korak1 = dan+kodMjesec+kodGodina+godinaZadnjeDvijeCifre+petaCifra;

	int korak2;
	korak2 = korak1 % 7;

	if (korak2 == 0) {
		d = ned;
		std::cout << "NED" << std::endl;
	}
	else if (korak2 == 1) {
		d = pon;
		std::cout << "PON" << std::endl;
	}
	else if (korak2 == 2) {
		d = uto;
		std::cout << "UTO" << std::endl;
	}
	else if (korak2 == 3) {
		d = sri;
		std::cout << "SRI" << std::endl;
	}
	else if (korak2 == 4) {
		d = cet;
		std::cout << "CET" << std::endl;
	}
	else if (korak2 == 5) {
		d = pet;
		std::cout << "PET" << std::endl;
	}
	else {
		d = sub;
		std::cout << "SUB" << std::endl;
	}


}