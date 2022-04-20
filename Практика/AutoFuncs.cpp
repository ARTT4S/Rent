#include <iomanip>
#include <iostream>
#include <Windows.h>
#include "AutoFuncs.h"
#include "Funcs.h"
using namespace std;
void automenu(Autos cars[], int* quont) {
	int command(1);
	while (command != 0) {
		cout << "0 - Возврат к прошлому меню.\n" << "1 - Добавить запись.\n" << "2 - Изменить запись.\n" << "3 - Удалить запись.\n" << "4 - Показать список автомобилей.\n" << "5 - Записать список автомобилей в файл.\n" << "6 - Записать список автомобилей из файла.\n";
		cout << "Введите номер команды: ";
		command = typeCheck(command);
		system("cls");
		switch (command) {
		case 0:
			cout << "Вы ввели команду Возврат к прошлому меню.\n";
			Sleep(500);
			break;
		case 1:
			cout << "Вы ввели команду Добавить запись.\n";
			Sleep(500);
			system("cls");
			addCar(cars, quont);
			system("pause");
			break;
		case 2:
			cout << "Вы ввели команду Изменить запись.\n";
			Sleep(500);
			system("cls");
			changeCar(cars, *quont);
			system("pause");
			break;
		case 3:
			cout << "Вы ввели команду Удалить запись.\n";
			Sleep(500);
			system("cls");
			deleteCar(cars, quont);
			system("pause");
			break;
		case 4:
			cout << "Вы ввели команду Показать список автомобилей.\n";
			Sleep(500);
			system("cls");
			writeCar(cars, *quont);
			system("pause");
			break;
		case 5:
			cout << "Вы ввели команду Записать список автомобилей в файла.\n";
			Sleep(500);
			system("cls");
			fileoutCar(cars, *quont);
			system("pause");
			break;
		case 6:
			cout << "Вы ввели команду Записать список автомобилей из файла.\n";
			Sleep(500);
			system("cls");
			fileinCar(cars, quont);
			system("pause");
			break;
		default:
			cout << "Введена неверная команда.\n";
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
		cout << "Добавьте запись.\n";
		cout << "Введите номер автомобиля: ";
		SimilaryCheckNum(cars, *quont, &tempNumber, 100, 999);
		cars[*quont - 1].setNumber(tempNumber);
		cout << "Введите марку автомобиля: ";
		strCheck(tempBrand);
		cars[*quont - 1].setBrand(tempBrand);
		cout << "Введите стоимость проката автомобиля: ";
		tempPrice = typeCheck(tempPrice, 0, 100000);
		cars[*quont - 1].setPrice(tempPrice);
		cout << "Введите тип автомобиля: ";
		strCheck(tempType);
		cars[*quont - 1].setType(tempType);
	}
	else {
		cout << "Достигнуто максимальное количество автомобилей.\n";
	}
	delete[] tempBrand;
	delete[] tempType;
}

void deleteCar(Autos cars[], int* quont) {
	int delstr = 0, copyi = 0;
	writeCar(cars, *quont);
	cout << "Какую по счёту запись вы хотите удалить: ";
	delstr = typeCheck(delstr, 1, *quont);
	system("cls");
	delstr -= 1;
	for (int j = 0; j < *quont; ++j) {
		if (j != delstr) {
			cars[copyi] = cars[j];
			++copyi;
		}
	}
	cout << "Запись удалена.\n";
	*quont -= 1;
}
void changeCar(Autos cars[], int quont) {
	int changeCommand = 0, numCar = 0, tempNumber = 0, tempPrice = 0;
	char* tempBrand = new char[MAXSIZEBRAND];
	char* tempType = new char[MAXSIZETYPE];
	writeCar(cars, quont);
	cout << "Запись о каком автомобиле по номеру вы хотите поменять: ";
	numCar = typeCheck(numCar, 1, quont);
	numCar -= 1;
	cout << "Выберите пункт:\n";
	cout << "0 - Возврат к меню." << endl << "1 - Изменить номер автомобиля." << endl << "2 - Изменить марку автомобиля." << endl << "3 - Изменить стоимость проката автомобиля." << endl << "4 - Изменить тип автомобиля." << endl;
	changeCommand = typeCheck(changeCommand);
	switch (changeCommand) {
	case 0:
		cout << "Возвращаем вас к меню сортировки.\n";
		break;
	case 1:
		cout << "Внесите изменения в поле Номер: ";
		SimilaryCheckNum(cars, quont, &tempNumber, 100, 999);
		cars[numCar].setNumber(tempNumber);
		break;
	case 2:
		cout << "Внесите изменения в поле Марка: ";
		strCheck(tempBrand);
		cars[numCar].setBrand(tempBrand);
		break;
	case 3:
		cout << "Внесите изменения в поле Стоимость проката: ";
		tempPrice = typeCheck(tempPrice, 0, 100000);
		cars[numCar].setPrice(tempPrice);
		break;
	case 4:
		cout << "Внесите изменения в поле Тип: ";
		cin >> tempType;
		cars[numCar].setType(tempType);
		break;
	default:
		cout << "Введена неверная команда.\n";
	}
	delete[] tempBrand;
	delete[] tempType;
}
void writeCar(Autos cars[], int quont) {
	char beg_end[LINESIZE]{ "----------------------------------------------------" };
	char dividingLine[LINESIZE]{ "|--|-----|---------------|--------------|----------|" };
	cout << "Машины:\n";
	cout << beg_end << endl;
	cout << '|' << " №" << '|' << "Номер" << '|' << setw(MAXSIZEBRAND) << "Марка" << '|' << setw(14) << "Стоимость" << '|' << setw(MAXSIZETYPE) << "Тип" << '|' << endl;
	for (int i = 0; i < quont; ++i) {
		cout << dividingLine << endl;
		cout << '|' << setw(2) << i + 1;
		cars[i].print();
	}
	cout << beg_end << endl;
}
void fileoutCar(Autos cars[], int quont) {
	char* filename = new char[FILENAME] {};
	cout << "Введите имя файла: ";
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
	cout << "Введите имя файла: ";
	strCheck(filename);
	fstream File(filename, ios::in | ios::binary);
	if (File.is_open()) {
		File.seekg(0, ios_base::end);
		if (File.tellg() == 0) {
			cout << "Файл пуст!\n";
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
			cout << "Информация об авто загружена!\n";
			Sleep(500);
		}
		File.close();
	}
	else {
		cout << "Не удалось открыть файл\n";
	}
	delete[] filename;
	delete[] string;
}