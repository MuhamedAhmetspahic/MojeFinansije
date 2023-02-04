#pragma once
#include <iostream>
#include <cstring>

class datum {
private:
	int dan, mjesec, godina;
public:
	void setDan();
	void setMjesec();
	void setGodina();

	void postaviDan(int dan);
	void postaviMjesec(int mjesec);
	void postaviGodina(int godina);

	int getDan();
	int getMjesec();
	int getGodina();

	void postaviDatum();
	void ispisiDatum();

	datum() {
		this->dan = 1;
		this->mjesec = 1;
		this->godina = 1900;
	}
	~datum() {

	}
};


class Dan : public datum {
	enum dani { ned=0, pon, uto, sri, cet, pet, sub };
public:
	void dajDan(int dan, int mjesec, int godina);
};