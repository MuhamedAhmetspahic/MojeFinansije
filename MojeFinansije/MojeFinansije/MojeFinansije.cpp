#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "prijava.h"
#include "fajl.h"
#include "meniFunkcije.h"

int main() {
	Osoba o;
	int izbor1;
	bool prolaz=false;
	do {
		system("cls");
		do {
			try {
				system("cls");
				std::cout << "1. Prijava" << std::endl;
				std::cout << "2. Registracija" << std::endl;
				std::cout << "0. Izlaz" << std::endl;
				std::cout << "-> ";
				std::cin >> izbor1;
				if (izbor1 < 0 || izbor1>2) {
					throw 0;
				}
			}
			catch(...) {
				system("cls");
				std::cout << "Pogresan unos!" << std::endl;
				system("pause");
				system("cls");
			}
		} while (izbor1 < 0 || izbor1>2);

		if (izbor1 == 1) {
			prolaz = login(o);
		}
		else if (izbor1 == 2) {
			prolaz = registracija(o);
		}
		else if (izbor1 == 0) {
			system("cls");
			std::cout << "Ugodan ostatak dana/veceri!" << std::endl;
			return 0;
		}


	} while (prolaz==false);
	
	system("cls");
	std::cout << "Uspjesno ste se prijavili/registrovali - Dobrodosli!" << std::endl;
	system("pause");
	system("cls");

	provjeriFajl(o);
	

	int izbor2;
	do {
		try {
			system("cls");
			std::cout << "---------- Glavni meni ----------" << std::endl;
			std::cout << "1. Nova transakcija" << std::endl;
			std::cout << "2. Ispis transakcija" << std::endl;
			std::cout << "3. Moji racuni/kase/spremista" << std::endl;
			std::cout << "4. Moje kategorije" << std::endl;
			std::cout << "5. Statistika" << std::endl;
			std::cout << "6. Moj profil" << std::endl;
			std::cout << "0. Izlaz" << std::endl;
			std::cout << "-> ";
			std::cin >> izbor2;
			if (izbor2 < 0 || izbor2>6) {
				throw 0;
			}
		}
		catch(...) {
			system("cls");
			std::cout << "Pogresan unos!" << std::endl;
			system("pause");
			system("cls");
		}
		if (izbor2 == 1) {
			novaTransakcija(o);
		}
		else if (izbor2 == 2) {
			ispisTransakcija(o);
		}
		else if (izbor2 == 3) {
			urediSpremista(o);
		}
		else if (izbor2 == 4) {
			urediKategorije(o);
		}
		else if (izbor2 == 5) {
			statistika(o);
		}
		else if (izbor2 == 6) {
			mojProfil(o);
		}

	} while (izbor2!=0);
	
	system("cls");
	std::cout << "Ugodan ostatak dana/veceri!" << std::endl;
	return 0;
}