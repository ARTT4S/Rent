#ifndef HEADER_H
#define HEADER_H

enum AutoConsts {
	AUTO_SIZE = 10,
	MAXSIZEBRAND = 15,
	MAXSIZETYPE = 10,
	MAXQUONTCARS = 30,
	FILENAME = 30,
	err = 48,
	LINESIZE = 63
};

class Autos {

private:
	int m_number = 0;
	char* m_brand;
	int m_price = 0;
	char* m_type;

public:
	Autos();
	void setNumber(int number);
	int getNumber();
	void setBrand(char* brand);
	char* getBrand();
	void setPrice(int price);
	int getPrice();
	void setType(char* type);
	char* getType();
	void print();

};

#endif

