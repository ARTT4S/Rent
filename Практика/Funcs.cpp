#include "Funcs.h"
using namespace std;
long long int typeCheck(long long int n) {
	bool flag = true;
	while (flag) {
		cin >> n;
		cin.clear();
		cin.ignore(32767, '\n');
		if (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Вы ввели некорректное значение! Введите другое значение: ";
		}
		else {
			flag = false;
		}
	}
	return n;
}

int typeCheck(int n, int min, int max) {
	bool flag = true;
	while (flag) {
		cin >> n;
		cin.clear();
		cin.ignore(32767, '\n');
		if ((cin.fail()) || (n < min) || (n > max)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Вы ввели некорректное значение! Введите другое значение: ";
		}
		else {
			flag = false;
		}
	}
	return n;
}

bool PhoneCheck(long long int phone1, Client* Clients, int n) {
	bool flag{ 1 };
	for (int i{}; i < n; i++) {
		if (Clients[i].GetPhone() == phone1) {
			flag = 0;
		}
	}
	return flag;
}

bool NumberCheck(int carnumber1, Autos* Cars, int n) {
	bool flag{1};
	for (int i{}; i < n; i++) {
		if (Cars[i].getNumber() == carnumber1) {
			flag = 0;
		}
	}
	return flag;
}

bool MarkCheck(char* mark1, Autos* Cars, int n) {
	bool flag{1};
	for (int i{}; i < n; i++) {
		if (strcmp(Cars[i].getBrand(), mark1)==0) {
			flag = 0;
		}
	}
	return flag;
}

void strCheck(char* string) {
	bool flag = true;
	char invalidSymbols[10] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	while (flag) {
		cin >> string;
		for (int i = 0; i < strlen(string) && flag; ++i) {
			for (int j = 0; j < 10 && flag; ++j) {
				if (string[i] == invalidSymbols[j]) {
					flag = false;
				}
			}
		}
		if (flag) {
			flag = false;
		}
		else {
			cout << "Вы ввели некорректное значение! Введите другое значение: ";
			flag = true;
		}
	}
}

bool dateSymbolCheck(char* string) {
	char validSymbols[11]{ '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	bool flag = false;
	for (int i = 0; i < strlen(string) && flag; ++i) {
		for (int j = 0; j < 11; ++j) {
			if (string[i] == validSymbols[j]) {
				flag = true;
			}
		}
		if (not(flag)) {
			flag = false;
		}
	}

	return flag;
} 

void intParse(char* string1, int *integer,  int* i, char symbol) {
	char* tempChar = new char[DATE_SIZE] {};
	for (*i; string1[*i] != symbol; ++*i) {
		if (string1[*i] != symbol) {
			tempChar[*i] = string1[*i];
		}
	}
	++* i;
	for (int i = 0; i < strlen(tempChar); ++i) {
		*integer += ((int)tempChar[i] - err) * pow(10, strlen(tempChar) - 1 - i);
	}
	delete[] tempChar;
}

void intParse(char* string1, int* integer, int* i) {
	char* tempChar = new char[DATE_SIZE] {};
	for (*i; *i < strlen(string1); ++*i) {
		tempChar[*i] = string1[*i];
	}
	for (int i = 0; i < strlen(tempChar); ++i) {
		*integer += ((int)tempChar[i] - err) * pow(10, strlen(tempChar) - 1 - i);
	}
	delete[] tempChar;
}

void dateCheck(char* date) {
	bool flag = false;
	int day{}, month{}, year{}, i{};
	while (not(flag)) {
		cin >> date;
		flag = not(dateSymbolCheck(date));
		if (flag) {
			intParse(date, &day, &i, '.');
			intParse(date, &month, &i, '.');
			intParse(date, &year, &i);
			if ((day < 0 || day > 31) || (month < 0 || month > 12) || (year < 1880 || year > 2077)) {
				flag = false;
			}
			else {
				flag = true;
			}
		}
		if (not(flag)) {
			cout << "Вы ввели некорректное значение! Введите другое значение: ";
		}
	}
}

void dateCheck(char* date1, char* date2) {
	bool flag = false;
	int day1{}, month1{}, year1{}, day2{}, month2{}, year2{}, i{};
	while (not(flag)) {
		dateCheck(date2);
		flag = not(dateSymbolCheck(date2));
		if (flag) {
			intParse(date1, &day1, &i, '.');
			intParse(date1, &month1, &i, '.');
			intParse(date1, &year1, &i);
			i = 0;
			intParse(date2, &day2, &i, '.');
			intParse(date2, &month2, &i, '.');
			intParse(date2, &year2, &i);
			if ((year2 < year1) || ((year2 > year1) && (month2 < month1)) || ((year2 > year1) && (month2 > month1) && (day2 < day1))) {
				flag = false;
			}
			else {
				flag = true;
			}
		}
		if (not(flag)) {
			cout << "Вы ввели некорректное значение! Введите другое значение: ";
		}
	}

}

void SimilaryCheckNum(Autos* Cars, int quont, int* n, int min, int max) {
	bool flag = true;
	while (flag) {
		cin >> *n;
		cin.clear();
		cin.ignore(32767, '\n');
		if ((cin.fail()) || (*n < min) || (*n > max)) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Вы ввели некорректное значение! Введите другое значение: ";
		}
		else {
			flag = false;
			for (int i = 0; i < quont; ++i) {
				if (Cars[i].getNumber() == *n) {
					flag = true;
				}
			}
			if (flag) {
				cout << "Автомобиль с таким номером уже существует. Введите другое значение: ";
			}
		}
	}
}

void SimilaryCheckPhone(Client* Clients, int quont, long long int* n) {
	bool flag = true;
	while (flag) {
		cin >> *n;
		cin.clear();
		cin.ignore(32767, '\n');
		if ((cin.fail())) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Вы ввели некорректное значение! Введите другое значение: ";
		}
		else {
			flag = false;
			for (int i = 0; i < quont; ++i) {
				if (Clients[i].GetPhone() == *n) {
					flag = true;
				}
			}
			if (flag) {
				cout << "Клиент с таким номером телефона уже существует. Введите другое значение: ";
			}
		}
	}
}

void Read(fstream &File, char* string, char symbol) {
	char read = NULL;
	for (int j = 0; read != symbol; ++j) {
		File.read((char*)&read, sizeof(read));
		if (read != symbol) {
			string[j] = read;
		}
	}
}

void Read(fstream &File, int* integer, char symbol) {
	char read = NULL;
	for (int j = 0; read != symbol; ++j) {
		File.read((char*)&read, sizeof(read));
		if (read != symbol) {
			*integer *= 10;
			*integer += (int)read - err;
		}
	}
}

void Read(fstream& File, long long int* integer, char symbol) {
	char read = NULL;
	for (int j = 0; read != symbol; ++j) {
		File.read((char*)&read, sizeof(read));
		if (read != symbol) {
			*integer *= 10;
			*integer += (int)read - err;
		}
	}
}