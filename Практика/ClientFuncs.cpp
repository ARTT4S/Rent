#include <iomanip>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "ClientFuncs.h"
#include "Funcs.h"
using namespace std;
void clientmenu(Client* Clients, int* n) {
    int y(-1);
    while (y != 0) {
        cout << "Список операций: \n0 - Выход в предыдущее меню\n1 - Добавление клиента\n2 - Изменение данных о клиенте\n3 - Удаление клиента\n4 - Вывод списка клиентов\n5 - Запись списка клиентов в файл\n6 - Ввод списка клиентов из файла\nВыберите операцию: ";
        y = typeCheck(y);
        switch (y) {
        case 0:
            cout << endl << "0 - Выход в предыдущее меню" << endl;
            Sleep(500);
            system("cls");
            break;
        case 1:
            system("cls");
            cout << endl << "1 - Добавление клиента" << endl;
            Sleep(500);
            addclient(Clients, n);
            break;
        case 2:
            system("cls");
            cout << endl << "2 - Изменение данных о клиенте" << endl;
            Sleep(500);
            changeclient(Clients, n);
            break;
        case 3:
            system("cls");
            cout << endl << "3 - Удаление клиента" << endl;
            Sleep(500);
            deleteclient(Clients, n);
            break;
        case 4:
            system("cls");
            cout << endl << "4 - Вывод списка клиентов" << endl;
            Sleep(500);
            showclients(Clients, *n);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << endl << "5 - Запись списка клиентов в файл" << endl;
            Sleep(500);
            fileinclient(Clients, *n);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << endl << "6 - Ввод списка клиентов из файла" << endl;
            Sleep(500);
            fileoutclient(Clients, n);
            system("pause");
            system("cls");
            break;
        default:
            cout << "Операция под таким номером отсутствует" << endl;
            Sleep(500);
        }
    }
}
void addclient(Client* Clients, int* n) {
    if (*n != CLIENT_SIZE) {
        char* lname1 = new char[NAME_SIZE] {};
        char* fname1 = new char[NAME_SIZE] {};
        char* sname1 = new char[NAME_SIZE] {};
        char* adress1 = new char[ADRESS_SIZE] {};
        long long int phone1{};
        int drive_experience1{};
        cout << "Введите фамилию: ";
        strCheck(lname1);
        cout << "Введите имя: ";
        strCheck(fname1);
        cout << "Введите отчество: ";
        strCheck(sname1);
        cout << "Введите адрес: ";
        getchar();
        gets_s(adress1, ADRESS_SIZE);
        cout << "Введите телефон: ";
        SimilaryCheckPhone(Clients, *n, &phone1);
        cout << "Введите стаж вождения: ";
        drive_experience1 = typeCheck(drive_experience1, 0, 60);
        Clients[*n].SetLName(lname1);
        Clients[*n].SetFName(fname1);
        Clients[*n].SetSName(sname1);
        Clients[*n].SetAdress(adress1);
        Clients[*n].SetPhone(phone1);
        Clients[*n].SetDriveExperience(drive_experience1);
        (*n)++;
        /*delete[] lname1;
        delete[] fname1;
        delete[] sname1;
        delete[] adress1;*/
    }
    else {
        cout << "Список клиентов уже заполнен" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}
void changeclient(Client* Clients, int* n) {
    int i{}, y{};
    showclients(Clients, *n);
    cout << "Данные какого клиента требуется изменить: ";
    i = typeCheck(i);
    i--;
    while ((i < 0) || (i >= *n)) {
        cout << "Такого клиента нет, введите номер ещё раз: ";
        i = typeCheck(i);
        i--;
    }
    cout << "Список данных о клиенте:" << endl;
    cout << "1 - Фамилия" << endl;
    cout << "2 - Имя" << endl;
    cout << "3 - Отчество" << endl;
    cout << "4 - Адрес" << endl;
    cout << "5 - Телефон" << endl;
    cout << "6 - Стаж вождения" << endl;
    cout << "Что требуется изменить: ";
    y = typeCheck(y);
    switch (y) {
    case 1:
    {
        char* lname1 = new char[NAME_SIZE] {};
        cout << "Введите фамилию: ";
        strCheck(lname1);
        Clients[i].SetLName(lname1);
        delete[] lname1;
        break;
    }
    case 2:
    {
        char* fname1 = new char[NAME_SIZE] {};
        cout << "Введите имя: ";
        strCheck(fname1);
        Clients[i].SetFName(fname1);
        delete[] fname1;
        break;
    }
    case 3:
    {
        char* sname1 = new char[NAME_SIZE] {};
        cout << "Введите отчество: ";
        strCheck(sname1);
        Clients[i].SetSName(sname1);
        delete[] sname1;
        break;
    }
    case 4:
    {
        char* adress1 = new char[ADRESS_SIZE] {};
        cout << "Введите адрес: ";
        getchar();
        gets_s(adress1, ADRESS_SIZE);
        Clients[i].SetAdress(adress1);
        delete[] adress1;
        break;
    }
    case 5:
    {
        long long int phone1{};
        cout << "Введите телефон: ";
        SimilaryCheckPhone(Clients, *n, &phone1);
        Clients[i].SetPhone(phone1);
        break;
    }
    case 6:
    {
        int drive_experience1{};
        cout << "Введите стаж вождения: ";
        drive_experience1 = typeCheck(drive_experience1, 0, 60);
        Clients[i].SetDriveExperience(drive_experience1);
        break;
    }
    default:
        cout << "Данных под таким номером не существует" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}
void deleteclient(Client* Clients, int* n) {
    int i{};
    Client temp{};
    showclients(Clients, *n);
    cout << "Данные какого клиента требуется удалить: ";
    i = typeCheck(i, 1, *n);
    i--;
    for (i; (i < *n) && (i != *n - 1); i++) {
        temp = Clients[i];
        Clients[i] = Clients[i + 1];
        Clients[i + 1] = temp;
    }
    (*n)--;
    Clients[*n].SetLName("");
    Clients[*n].SetFName("");
    Clients[*n].SetSName("");
    Clients[*n].SetAdress("");
    Clients[*n].SetPhone(0);
    Clients[*n].SetDriveExperience(0);
    cout << "Данные о клиенте удалены\n";
    cout << endl;
    system("pause");
    system("cls");
}
void showclients(Client* Clients, int n) {
    cout << "____________________________________________________________________________________________________________________\n";
    cout << "|Номер|" << setw(NAME_SIZE+1) << "Фамилия|" << setw(NAME_SIZE+1) << "Имя|" << setw(NAME_SIZE+1) << "Отчество|" << setw(ADRESS_SIZE+1) << "Адрес|" << setw(PHONE_SIZE+2) << "Телефон|" << "Стаж вождения|\n";
    for (int i{}; i < n; i++) {
        cout << "|-----|----------------|----------------|----------------|------------------------------|------------|-------------|\n";
        cout << "|  " << i + 1 << "  |";
        Clients[i].print();
    }
    cout << "|_____|________________|________________|________________|______________________________|____________|_____________|\n";
    cout << endl;
}

void fileinclient(Client* Clients, int quont) {
    char* filename = new char[FILE_SIZE] {};
    cout << "Введите имя файла: ";
    strCheck(filename);
    ofstream file(filename, ios_base::trunc | ios_base::out | ios_base::binary);
    char symbol = '|';
    char* drive_experience1 = new char[2]{};
    char* lname1 = new char[NAME_SIZE] {};
    char* fname1 = new char[NAME_SIZE]{};
    char* sname1 = new char[NAME_SIZE] {};
    char* adress1 = new char[ADRESS_SIZE] {};
    char* phone1 = new char[_MAX_U64TOSTR_BASE2_COUNT] {};
    for (int i = 0; i < quont; ++i) {
        _itoa_s(Clients[i].GetDriveExperience(), drive_experience1, 2, 10);
        lname1 = Clients[i].GetLName();
        fname1 = Clients[i].GetFName();
        sname1 = Clients[i].GetSName();
        adress1 = Clients[i].GetAdress();
        _i64toa_s(Clients[i].GetPhone(), phone1, _MAX_U64TOSTR_BASE2_COUNT, 10);
        file.write((char*)drive_experience1, strlen(drive_experience1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)lname1, strlen(lname1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)fname1, strlen(fname1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)sname1, strlen(sname1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)adress1, strlen(adress1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)phone1, strlen(phone1));
        file.write((char*)&symbol, sizeof(symbol));
    }
    delete[] filename;
    /*delete[] drive_experience1;
    delete[] lname1;
    delete[] fname1;
    delete[] sname1;
    delete[] adress1;
    delete[] phone1;*/
}

void fileoutclient(Client* Clients, int *quont) {
    char* filename = new char[FILE_SIZE] {};
    cout << "Введите имя файла: ";
    strCheck(filename);
    fstream File(filename, ios_base::in | ios_base::binary);
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
            *quont = count / 6;
            File.clear();
            File.seekg(0, ios_base::beg);
            for (int i = 0; i < *quont; ++i) {
                char* lname1 = new char[NAME_SIZE] {};
                char* fname1 = new char[NAME_SIZE] {};
                char* sname1 = new char[NAME_SIZE] {};
                char* adress1 = new char[ADRESS_SIZE] {};
                long long int tempPhone1{};
                int drive_experience1 = 0;
                Read(File, &drive_experience1, '|');
                Clients[i].SetDriveExperience(drive_experience1);
                Read(File, lname1, '|');
                Clients[i].SetLName(lname1);
                Read(File, fname1, '|');
                Clients[i].SetFName(fname1);
                Read(File, sname1, '|');
                Clients[i].SetSName(sname1);
                Read(File, adress1, '|');
                Clients[i].SetAdress(adress1);
                Read(File, &tempPhone1, '|');
                Clients[i].SetPhone(tempPhone1);
                delete[] lname1;
                delete[] fname1;
                delete[] sname1;
                delete[] adress1;
            }
            cout << "Информация о клиенте загружена!\n";
            Sleep(500);
        }
        File.close();
    }
    else {
        cout << "Не удалось открыть файл\n";
    }
    delete[] filename;
}