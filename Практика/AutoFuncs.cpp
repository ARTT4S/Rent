#include <iomanip>
#include <iostream>
#include <Windows.h>
#include "AutoFuncs.h"
#include "Funcs.h"
using namespace std;
void automenu(Autos cars[], int* quont) {
	int command(1);
	while (command != 0) {
		cout << "0 - ������� � �������� ����.\n" << "1 - �������� ������.\n" << "2 - �������� ������.\n" << "3 - ������� ������.\n" << "4 - �������� ������ �����������.\n" << "5 - �������� ������ ����������� � ����.\n" << "6 - �������� ������ ����������� �� �����.\n";
		cout << "������� ����� �������: ";
		command = typeCheck(command);
		system("cls");
		switch (command) {
		case 0:
			cout << "�� ����� ������� ������� � �������� ����.\n";
			Sleep(500);
			break;
		case 1:
			cout << "�� ����� ������� �������� ������.\n";
			Sleep(500);
			system("cls");
			addCar(cars, quont);
			system("pause");
			break;
		case 2:
			cout << "�� ����� ������� �������� ������.\n";
			Sleep(500);
			system("cls");
			changeCar(cars, *quont);
			system("pause");
			break;
		case 3:
			cout << "�� ����� ������� ������� ������.\n";
			Sleep(500);
			system("cls");
			deleteCar(cars, quont);
			system("pause");
			break;
		case 4:
			cout << "�� ����� ������� �������� ������ �����������.\n";
			Sleep(500);
			system("cls");
			writeCar(cars, *quont);
			system("pause");
			break;
		case 5:
			cout << "�� ����� ������� �������� ������ ����������� � �����.\n";
			Sleep(500);
			system("cls");
			fileoutCar(cars, *quont);
			system("pause");
			break;
		case 6:
			cout << "�� ����� ������� �������� ������ ����������� �� �����.\n";
			Sleep(500);
			system("cls");
			fileinCar(cars, quont);
			system("pause");
			break;
		default:
			cout << "������� �������� �������.\n";
		}
		system("cls");
	}
}

void addCar(Autos cars[], int* quont) {
	int tempPrice = 0, tempNumber = 0;
	char* tempBrand = new char[MAXSIZEBRAND] {};
	char* tempType = new char[MAXSIZETYPE] {};
	++(*quont);
	if (*quont != MAXQUONTCARS) {
		cout << "�������� ������.\n";
		cout << "������� ����� ����������: ";
		SimilaryCheckNum(cars, *quont, &tempNumber, 100, 999);
		cars[*quont - 1].setNumber(tempNumber);
		cout << "������� ����� ����������: ";
		strCheck(tempBrand);
		cars[*quont - 1].setBrand(tempBrand);
		cout << "������� ��������� ������� ����������: ";
		tempPrice = typeCheck(tempPrice, 0, 100000);
		cars[*quont - 1].setPrice(tempPrice);
		cout << "������� ��� ����������: ";
		strCheck(tempType);
		cars[*quont - 1].setType(tempType);
	}
	else {
		cout << "���������� ������������ ���������� �����������.\n";
	}
	delete[] tempBrand;
	delete[] tempType;
}

void deleteCar(Autos cars[], int* quont) {
	int delstr = 0, copyi = 0;
	writeCar(cars, *quont);
	cout << "����� �� ����� ������ �� ������ �������: ";
	delstr = typeCheck(delstr, 1, *quont);
	system("cls");
	delstr -= 1;
	for (int j = 0; j < *quont; ++j) {
		if (j != delstr) {
			cars[copyi] = cars[j];
			++copyi;
		}
	}
	cout << "������ �������.\n";
	*quont -= 1;
}
void changeCar(Autos cars[], int quont) {
	int changeCommand = 0, numCar = 0, tempNumber = 0, tempPrice = 0;
	char* tempBrand = new char[MAXSIZEBRAND];
	char* tempType = new char[MAXSIZETYPE];
	writeCar(cars, quont);
	cout << "������ � ����� ���������� �� ������ �� ������ ��������: ";
	numCar = typeCheck(numCar, 1, quont);
	numCar -= 1;
	cout << "�������� �����:\n";
	cout << "0 - ������� � ����." << endl << "1 - �������� ����� ����������." << endl << "2 - �������� ����� ����������." << endl << "3 - �������� ��������� ������� ����������." << endl << "4 - �������� ��� ����������." << endl;
	changeCommand = typeCheck(changeCommand);
	switch (changeCommand) {
	case 0:
		cout << "���������� ��� � ���� ����������.\n";
		break;
	case 1:
		cout << "������� ��������� � ���� �����: ";
		SimilaryCheckNum(cars, quont, &tempNumber, 100, 999);
		cars[numCar].setNumber(tempNumber);
		break;
	case 2:
		cout << "������� ��������� � ���� �����: ";
		strCheck(tempBrand);
		cars[numCar].setBrand(tempBrand);
		break;
	case 3:
		cout << "������� ��������� � ���� ��������� �������: ";
		tempPrice = typeCheck(tempPrice, 0, 100000);
		cars[numCar].setPrice(tempPrice);
		break;
	case 4:
		cout << "������� ��������� � ���� ���: ";
		cin >> tempType;
		cars[numCar].setType(tempType);
		break;
	default:
		cout << "������� �������� �������.\n";
	}
	delete[] tempBrand;
	delete[] tempType;
}
void writeCar(Autos cars[], int quont) {
	char beg_end[LINESIZE]{ "----------------------------------------------------" };
	char dividingLine[LINESIZE]{ "|--|-----|---------------|--------------|----------|" };
	cout << "������:\n";
	cout << beg_end << endl;
	cout << '|' << " �" << '|' << "�����" << '|' << setw(MAXSIZEBRAND) << "�����" << '|' << setw(14) << "���������" << '|' << setw(MAXSIZETYPE) << "���" << '|' << endl;
	for (int i = 0; i < quont; ++i) {
		cout << dividingLine << endl;
		cout << '|' << setw(2) << i + 1;
		cars[i].print();
	}
	cout << beg_end << endl;
}
void fileoutCar(Autos cars[], int quont) {
	char* filename = new char[FILENAME] {};
	cout << "������� ��� �����: ";
	strCheck(filename);
	ofstream file(filename, ios::trunc | ios::out | ios::binary);
	char symbol = '|';
	char* tempNumber = new char[5]{};
	char* tempBrand = new char[MAXSIZEBRAND] {};
	char* tempPrice = new char[6]{};
	char* tempType = new char[MAXSIZETYPE] {};
	for (int i = 0; i < quont; ++i) {
		_itoa_s(cars[i].getNumber(), tempNumber, 5, 10);
		tempBrand = cars[i].getBrand();
		_itoa_s(cars[i].getPrice(), tempPrice, 6, 10);
		tempType = cars[i].getType();
		file.write((char*)tempNumber, strlen(tempNumber));
		file.write((char*)&symbol, sizeof(symbol));
		file.write((char*)tempBrand, MAXSIZEBRAND);
		file.write((char*)&symbol, sizeof(symbol));
		file.write((char*)tempPrice, strlen(tempPrice));
		file.write((char*)&symbol, sizeof(symbol));
		file.write((char*)tempType, MAXSIZETYPE);
		file.write((char*)&symbol, sizeof(symbol));
	}
	/*delete[] filename;
	delete[] tempNumber;
	delete[] tempBrand;
	delete[] tempPrice;
	delete[] tempType;*/
}
void fileinCar(Autos cars[], int* quont) {
	char* filename = new char[FILENAME] {};
	char* string = new char[LINESIZE] {};
	cout << "������� ��� �����: ";
	strCheck(filename);
	fstream File(filename, ios::in | ios::binary);
	if (File.is_open()) {
		File.seekg(0, ios_base::end);
		if (File.tellg() == 0) {
			cout << "���� ����!\n";
			Sleep(500);
			system("cls");
		}
		else {
			File.seekg(0, ios_base::beg);
			char read = NULL;
			int count = 0;
			while (!File.eof()) {
				File.read((char*)&read, sizeof(read));
				if (read == '|') {
					++count;
				}
			}
			*quont = count / 4;
			File.clear();
			File.seekg(0, ios_base::beg);
			for (int i = 0; i < *quont; ++i) {
				int tempNumber = 0, tempPrice = 0;
				char* tempBrand = new char[MAXSIZEBRAND] {};
				char* tempType = new char[MAXSIZETYPE] {};
				Read(File, &tempNumber, '|');
				cars[i].setNumber(tempNumber);
				Read(File, tempBrand, '|');
				cars[i].setBrand(tempBrand);
				Read(File, &tempPrice, '|');
				cars[i].setPrice(tempPrice);
				Read(File, tempType, '|');
				cars[i].setType(tempType);
				delete[] tempBrand;
				delete[] tempType;
			}
			cout << "���������� �� ���� ���������!\n";
			Sleep(500);
		}
		File.close();
	}
	else {
		cout << "�� ������� ������� ����\n";
	}
	delete[] filename;
	delete[] string;
}