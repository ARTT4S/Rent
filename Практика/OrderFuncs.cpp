#include <iomanip>
#include <fstream>
#include <iostream>
#include <Windows.h>
#include "OrderFuncs.h"
#include "Funcs.h"
using namespace std;
void ordermenu(Order* Orders,Autos* Cars, Client* Clients, int* n, int* q, int* l) {
    int y(-1);
    while (y != 0) {
        cout << "������ ��������: \n0 - ����� � ���������� ����\n1 - ���������� ������\n2 - ��������� ������ � ������\n3 - �������� ������\n4 - ����� ������ �������\n5 - ������ ������ ������� � ����\n6 - ���� ������ ������� �� �����\n�������� ��������: ";
        y = typeCheck(y);
        switch (y) {
        case 0:
            cout << endl << "0 - ����� � ���������� ����" << endl;
            Sleep(500);
            system("cls");
            break;
        case 1:
            system("cls");
            cout << endl << "1 - ���������� ������" << endl;
            Sleep(500);
            addorder(Orders, Cars, Clients, n, *q, *l);
            break;
        case 2:
            system("cls");
            cout << endl << "2 - ��������� ������ � ������" << endl;
            Sleep(500);
            changeorder(Orders, Cars, Clients, n, *q, *l);
            break;
        case 3:
            system("cls");
            cout << endl << "3 - �������� ������" << endl;
            Sleep(500);
            deleteorder(Orders, n);
            break;
        case 4:
            system("cls");
            cout << endl << "4 - ����� ������ �������" << endl;
            Sleep(500);
            showorders(Orders, n);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << endl << "5 - ������ ������ ������� � ����" << endl;
            Sleep(500);
            fileinorder(Orders, n);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << endl << "6 - ���� ������ ������� �� �����" << endl;
            Sleep(500);
            fileoutorder(Orders, n);
            system("pause");
            system("cls");
            break;
        default:
            cout << "�������� ��� ����� ������� �����������" << endl;
            Sleep(500);
        }
    }
}
void addorder(Order* Orders, Autos* Cars, Client* Clients, int* n, int q, int l) {
    if (*n != ORDER_SIZE) {
        int number1{};
        int carnumber1{};
        char* mark1 = new char[MARK_SIZE] {};
        long long int phone1{};
        char* date1 = new char[DATE_SIZE] {};
        char* back_date1 = new char[DATE_SIZE] {};
        cout << "������� ����� ����������: ";
        carnumber1 = typeCheck(carnumber1, 100, 999);
        while (NumberCheck(carnumber1, Cars, q)) {
            cout << "���������� ��� ����� ������� ���� � ������, ������� ������: ";
            carnumber1 = typeCheck(carnumber1, 100, 999);
        }
        cout << "������� ����� ����������: ";
        strCheck(mark1);
        while (MarkCheck(mark1, Cars, q)) {
            cout << "���������� ����� ����� ���� � ������, ������� ������: ";
            strCheck(mark1);
        }
        cout << "������� �������: ";
        phone1 = typeCheck(phone1);
        while (PhoneCheck(phone1, Clients, l)) {
            cout << "������� � ����� ��������� ���� � ������, ������� ������: ";
            phone1 = typeCheck(phone1);
        }
        cout << "������� ���� ������: ";
        dateCheck(date1);
        cout << "������� ���� ��������: ";
        dateCheck(date1, back_date1);
        Orders[*n].SetNumber((*n)+1);
        Orders[*n].SetCarnumber(carnumber1);
        Orders[*n].SetMark(mark1);
        Orders[*n].SetPhone(phone1);
        Orders[*n].SetDate(date1);
        Orders[*n].SetBackDate(back_date1);
        (*n)++;
        /*delete[] mark1;
        delete[] date1;
        delete[] back_date1;*/
    }
    else {
        cout << "������ ������� ��� ��������" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}
void changeorder(Order* Orders, Autos* Cars, Client* Clients, int* n, int q, int l) {
    int i{}, y{};
    showorders(Orders, n);
    cout << "������ ������ ������ ��������� ��������: ";
    i = typeCheck(i);
    i--;
    while ((i < 0) || (i >= *n)) {
        cout << "������ ������ ���, ������� ����� ��� ���: ";
        i = typeCheck(i);
        i--;
    }
    cout << "������ ������ � �������:" << endl;
    cout << "1 - ����� ����������" << endl;
    cout << "2 - �����" << endl;
    cout << "3 - �������" << endl;
    cout << "4 - ���� ������" << endl;
    cout << "5 - ���� ��������" << endl;
    cout << "��� ��������� ��������: ";
    y = typeCheck(y);
    switch (y) {
    case 1:
    {
        int carnumber1{};
        cout << "������� ����� ����������: ";
        SimilaryCheckNum(Cars, q, &carnumber1, 100, 999);
        while (NumberCheck(carnumber1, Cars, q)) {
            cout << "���������� ��� ����� ������� ���� � ������, ������� ������: ";
            SimilaryCheckNum(Cars, q, &carnumber1, 100, 999);
        }
        Orders[i].SetCarnumber(carnumber1);
        break;
    }
    case 2:
    {
        char* mark1 = new char[MARK_SIZE] {};
        cout << "������� ����� ����������: ";
        strCheck(mark1);
        while (MarkCheck(mark1, Cars, q)) {
            cout << "���������� ����� ����� ���� � ������, ������� ������: ";
            strCheck(mark1);
        }
        Orders[i].SetMark(mark1);
        delete[] mark1;
        break;
    }
    case 3:
    {
        long long int phone1{};
        cout << "������� �������: ";
        SimilaryCheckPhone(Clients, *n, &phone1);
        while (PhoneCheck(phone1, Clients, l)) {
            cout << "������� � ����� ��������� ���� � ������, ������� ������: ";
            SimilaryCheckPhone(Clients, *n, &phone1);
        }
        Orders[i].SetPhone(phone1);
        break;
    }
    case 4:
    {
        char* date1 = new char[DATE_SIZE] {};
        cout << "������� ���� ������: ";
        dateCheck(date1);
        Orders[i].SetDate(date1);
        delete[] date1;
        break;
    }
    case 5:
    {
        char* back_date1 = new char[DATE_SIZE]{};
        cout << "������� ���� ��������: ";
        dateCheck(Orders[i].GetDate(), back_date1);
        Orders[i].SetBackDate(back_date1);
        delete[] back_date1;
        break;
    }
    default:
        cout << "������ ��� ����� ������� �� ����������" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}
void deleteorder(Order* Orders, int* n) {
    int i{};
    Order temp{};
    showorders(Orders, n);
    cout << "������ ������ ������ ��������� ��������: ";
    i = typeCheck(i);
    i--;
    while ((i < 0) || (i >= *n)) {
        cout << "������ ������ ���, ������� ����� ��� ���: ";
        i = typeCheck(i);
        i--;
    }
    for (i; (i < *n) && (i != *n - 1); i++) {
        temp = Orders[i];
        Orders[i] = Orders[i + 1];
        Orders[i + 1] = temp;
    }
    Orders[*n].SetNumber(0);
    Orders[*n].SetCarnumber(0);
    Orders[*n].SetMark("");
    Orders[*n].SetPhone(0);
    Orders[*n].SetDate("");
    Orders[*n].SetBackDate("");
    (*n)--;
    cout << "������ � ������ �������\n";
    cout << endl;
    system("pause");
    system("cls");
}
void showorders(Order* Orders, int* n) {
    cout << "____________________________________________________________________________\n";
    cout << "|�����|" << setw(14) << "����� ������|" << setw(MARK_SIZE+1) << "����� ������|" << setw(ORDERPHONE_SIZE+1) << "�������|" << setw(DATE_SIZE+1) << "���� ������|" << setw(DATE_SIZE+1) << "���� ��������|" << endl;
    for (int i{}; i < *n; i++) {
        cout << "|-----|-------------|---------------|------------|-----------|-------------|\n";
        Orders[i].print();
    }
    cout << "|_____|_____________|_______________|____________|___________|_____________|\n";
    cout << endl;
}
void fileinorder(Order* Orders, int* quont) {
    char* filename = new char[FILENAME] {};
    cout << "������� ��� �����: ";
    strCheck(filename);
    ofstream file(filename, ios_base::trunc | ios_base::out | ios_base::binary);
    char symbol = '|';
    char* mark1 = new char[MARK_SIZE] {};
    char* phone1 = new char[_MAX_U64TOSTR_BASE2_COUNT] {};
    char* date1 = new char[DATE_SIZE] {};
    char* back_date1 = new char[DATE_SIZE] {};
    char* number1 = new char[3] {};
    char* carnumber1 = new char[5] {};
    for (int i = 0; i < *quont; ++i) {
        mark1 = Orders[i].GetMark();
        date1 = Orders[i].GetDate();
        back_date1 = Orders[i].GetBackDate();
        _itoa_s(Orders[i].GetNumber(), number1, 3, 10);
        _itoa_s(Orders[i].GetCarnumber(), carnumber1, 5, 10);
        file.write((char*)number1, strlen(number1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)carnumber1, strlen(carnumber1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)mark1, MARK_SIZE);
        file.write((char*)&symbol, sizeof(symbol));
        _i64toa_s(Orders[i].GetPhone(), phone1, _MAX_U64TOSTR_BASE2_COUNT, 10);
        file.write((char*)phone1, strlen(phone1));
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)date1, DATE_SIZE);
        file.write((char*)&symbol, sizeof(symbol));
        file.write((char*)back_date1, DATE_SIZE);
        file.write((char*)&symbol, sizeof(symbol));
    }
    /*delete[] mark1;
    delete[] phone1;
    delete[] date1;
    delete[] back_date1;
    delete[] number1;
    delete[] carnumber1;*/
    delete[] filename;
}
void fileoutorder(Order* Orders, int* quont) {
    char* filename = new char[FILENAME] {};
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
            *quont = count / 6;
            File.clear();
            File.seekg(0, ios_base::beg);
            for (int i = 0; i < *quont; ++i) {
                int number1{};
                int carnumber1{};
                long long int tempPhone1{};
                char* mark1 = new char[MARK_SIZE] {};
                char* date1 = new char[DATE_SIZE] {};
                char* back_date1 = new char[DATE_SIZE] {};
                Read(File, &number1, '|');
                Orders[i].SetNumber(number1);
                Read(File, &carnumber1, '|');
                Orders[i].SetCarnumber(carnumber1);
                Read(File, mark1, '|');
                Orders[i].SetMark(mark1);
                Read(File, &tempPhone1, '|');
                Orders[i].SetPhone(tempPhone1);
                Read(File, date1, '|');
                Orders[i].SetDate(date1);
                Read(File, back_date1, '|');
                Orders[i].SetBackDate(back_date1);
                delete[] mark1;
                delete[] date1;
                delete[] back_date1;
            }
            cout << "���������� � ������ ���������!\n";
            Sleep(500);
        }
        File.close();
    }
    else {
        cout << "�� ������� ������� ����\n";
    }
    delete[] filename;
}