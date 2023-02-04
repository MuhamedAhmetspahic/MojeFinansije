#pragma once
#include <cstring>
#include <string>

class Osoba {
private:
	std::string ime, prezime, korisnickoIme, sifra;
public:
	void setIme();
	void setPrezime();
	void setKorisnicko();
	void setSifra();

	std::string getIme();
	std::string getPrezime();
	std::string getKorisnicko();
	std::string getSifra();

	friend std::istream& operator>>(std::istream& stream, Osoba& o);

	void postaviIme(std::string ime);
	void postaviPrezime(std::string prezime);
	void postaviKorisnicko(std::string korisnicko);
	void postaviSifra(std::string sifra);

	Osoba() {
		this->ime = "nepoznato";
		this->prezime = "nepoznato";
		this->korisnickoIme = "nepoznato";
		this->sifra = "nepoznato";
	}

	~Osoba() = default;

};