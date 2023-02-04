#pragma once
#include <string>

class Kategorija {
private:
	std::string naziv;
public:
	void setKategorija();
	std::string getKategorija();

	void postaviKategorija(std::string naziv);

	friend std::istream& operator>>(std::istream& stream, Kategorija& k);
	friend std::ostream& operator<<(std::ostream& stream, Kategorija& k);

	Kategorija() {
		this->naziv = "nepoznato";
	}

	~Kategorija() = default;




};