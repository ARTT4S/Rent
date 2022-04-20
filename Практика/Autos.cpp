#include <string>
#include <iostream>
#include <iomanip>
#include "Autos.h"
Autos::Autos() {
	m_number = 0;
	m_brand = new char[MAXSIZEBRAND] {};
	m_price = 0;
	m_type = new char[MAXSIZETYPE] {};
};

void Autos::setNumber(int number) {
	m_number = number;
};

int Autos::getNumber() {
	return m_number;
};

void Autos::setBrand(char* brand) {
	strcpy_s(m_brand, MAXSIZEBRAND, brand);
};

char* Autos::getBrand() {
	return m_brand;
};

void Autos::setPrice(int price) {
	m_price = price;
};

int Autos::getPrice() {
	return m_price;
};

void Autos::setType(char* type) {
	strcpy_s(m_type, MAXSIZETYPE, type);
};

char* Autos::getType() {
	return m_type;
};

void Autos::print() {
	std::cout << '|' << std::setw(5) << m_number << '|' << std::setw(MAXSIZEBRAND) << m_brand << '|' << std::setw(14) << m_price << '|' << std::setw(MAXSIZETYPE) << m_type << '|' << std::endl;
};