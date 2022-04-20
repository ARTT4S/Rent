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
        cout << "Список операций: \n0 - Выход в предыдущее меню\n1 - Добавление заказа\n2 - Изменение данных о заказе\n3 - Удаление заказа\n4 - Вывод списка заказов\n5 - Запись списка заказов в файл\n6 - Ввод списка заказов из файла\nВыберите операцию: ";
        y = typeCheck(y);
        switch (y) {
        case 0:
            cout << endl << "0 - Выход в предыдущее меню" << endl;
            Sleep(500);
            system("cls");
            break;
        case 1:
            system("cls");
            cout << endl << "1 - Добавление заказа" << endl;
            Sleep(500);
            addorder(Orders, Cars, Clients, n, *q, *l);
            break;
        case 2:
            system("cls");
            cout << endl << "2 - Изменение данных о заказе" << endl;
            Sleep(500);
            changeorder(Orders, Cars, Clients, n, *q, *l);
            break;
        case 3:
            system("cls");
            cout << endl << "3 - Удаление заказа" << endl;
            Sleep(500);
            deleteorder(Orders, n);
            break;
        case 4:
            system("cls");
            cout << endl << "4 - Вывод списка заказов" << endl;
            Sleep(500);
            showorders(Orders, n);
            system("pause");
            system("cls");
            break;
        case 5:
            system("cls");
            cout << endl << "5 - Запись списка заказов в файл" << endl;
            Sleep(500);
            fileinorder(Orders, n);
            system("pause");
            system("cls");
            break;
        case 6:
            system("cls");
            cout << endl << "6 - Ввод списка заказов из файла" << endl;
            Sleep(500);
            fileoutorder(Orders, n);
            system("pause");
            system("cls");
            break;
        default:
            cout << "Операция под таким номером отсутствует" << endl;
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
        cout << "Введите номер автомобиля: ";
        carnumber1 = typeCheck(carnumber1, 100, 999);
        while (NumberCheck(carnumber1, Cars, q)) {
            cout << "Автомобиля под таким номером нету в списке, введите заново: ";
            carnumber1 = typeCheck(carnumber1, 100, 999);
        }
        cout << "Введите марку автомобиля: ";
        strCheck(mark1);
        while (MarkCheck(mark1, Cars, q)) {
            cout << "Автомобиля такой марки нету в списке, введите заново: ";
            strCheck(mark1);
        }
        cout << "Введите телефон: ";
        phone1 = typeCheck(phone1);
        while (PhoneCheck(phone1, Clients, l)) {
            cout << "Клиента с таким телефоном нету в списке, введите заново: ";
            phone1 = typeCheck(phone1);
        }
        cout << "Введите дату заказа: ";
        dateCheck(date1);
        cout << "Введите дату возврата: ";
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
        cout << "Список заказов уже заполнен" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}
void changeorder(Order* Orders, Autos* Cars, Client* Clients, int* n, int q, int l) {
    int i{}, y{};
    showorders(Orders, n);
    cout << "Данные какого заказа требуется изменить: ";
    i = typeCheck(i);
    i--;
    while ((i < 0) || (i >= *n)) {
        cout << "Такого заказа нет, введите номер ещё раз: ";
        i = typeCheck(i);
        i--;
    }
    cout << "Список данных о клиенте:" << endl;
    cout << "1 - Номер автомобиля" << endl;
    cout << "2 - Марка" << endl;
    cout << "3 - Телефон" << endl;
    cout << "4 - Дата заказа" << endl;
    cout << "5 - Дата возврата" << endl;
    cout << "Что требуется изменить: ";
    y = typeCheck(y);
    switch (y) {
    case 1:
    {
        int carnumber1{};
        cout << "Введите номер автомобиля: ";
        SimilaryCheckNum(Cars, q, &carnumber1, 100, 999);
        while (NumberCheck(carnumber1, Cars, q)) {
            cout << "Автомобиля под таким номером нету в списке, введите заново: ";
            SimilaryCheckNum(Cars, q, &carnumber1, 100, 999);
        }
        Orders[i].SetCarnumber(carnumber1);
        break;
    }
    case 2:
    {
        char* mark1 = new char[MARK_SIZE] {};
        cout << "Введите марку автомобиля: ";
        strCheck(mark1);
        while (MarkCheck(mark1, Cars, q)) {
            cout << "Автомобиля такой марки нету в списке, введите заново: ";
            strCheck(mark1);
        }
        Orders[i].SetMark(mark1);
        delete[] mark1;
        break;
    }
    case 3:
    {
        long long int phone1{};
        cout << "Введите телефон: ";
        SimilaryCheckPhone(Clients, *n, &phone1);
        while (PhoneCheck(phone1, Clients, l)) {
            cout << "Клиента с таким телефоном нету в списке, введите заново: ";
            SimilaryCheckPhone(Clients, *n, &phone1);
        }
        Orders[i].SetPhone(phone1);
        break;
    }
    case 4:
    {
        char* date1 = new char[DATE_SIZE] {};
        cout << "Введите дату заказа: ";
        dateCheck(date1);
        Orders[i].SetDate(date1);
        delete[] date1;
        break;
    }
    case 5:
    {
        char* back_date1 = new char[DATE_SIZE]{};
        cout << "Введите дату возврата: ";
        dateCheck(Orders[i].GetDate(), back_date1);
        Orders[i].SetBackDate(back_date1);
        delete[] back_date1;
        break;
    }
    default:
        cout << "Данных под таким номером не существует" << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
}
void deleteorder(Order* Orders, int* n) {
    int i{};
    Order temp{};
    showorders(Orders, n);
    cout << "Данные какого заказа требуется изменить: ";
    i = typeCheck(i);
    i--;
    while ((i < 0) || (i >= *n)) {
        cout << "Такого заказа нет, введите номер ещё раз: ";
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
    cout << "Данные о заказе удалены\n";
    cout << endl;
    system("pause");
    system("cls");
}
void showorders(Order* Orders, int* n) {
    cout << "____________________________________________________________________________\n";
    cout << "|Номер|" << setw(14) << "Номер машины|" << setw(MARK_SIZE+1) << "Марка машины|" << setw(ORDERPHONE_SIZE+1) << "Телефон|" << setw(DATE_SIZE+1) << "Дата заказа|" << setw(DATE_SIZE+1) << "Дата возврата|" << endl;
    for (int i{}; i < *n; i++) {
        cout << "|-----|-------------|---------------|------------|-----------|-------------|\n";
        Orders[i].print();
    }
    cout << "|_____|_____________|_______________|____________|___________|_____________|\n";
    cout << endl;
}
void fileinorder(Order* Orders, int* quont) {
    char* filename = new char[FILENAME] {};
    cout << "Введите имя файла: ";
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
            cout << "Информация о заказе загружена!\n";
            Sleep(500);
        }
        File.close();
    }
    else {
        cout << "Не удалось открыть файл\n";
    }
    delete[] filename;
}