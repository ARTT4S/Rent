#include "Autos.h"
#include "Client.h"
#include "Order.h"
#include "Funcs.h"
#include <iostream>
#include <Windows.h>
using namespace std;
void markstat(Order* Orders, int n) {
    int k{};
    char* mark1 = new char[MARK_SIZE] {};
    cout << "Введите марку автомобиля: ";
    strCheck(mark1);
    for (int i{}; i < n; i++) {
        if (strcmp(Orders[i].GetMark(), mark1) == 0) {
            k++;
        }
    }
    cout << "Было заказано " << k << " автомобилей марки " << mark1 <<"\n";
    delete[] mark1;
    system("pause");
    system("cls");
}
void clientstat(Order* Orders, int n) {
    int k{};
    long long int phone1{};
    cout << "Введите телефон: ";
    phone1 = typeCheck(phone1);
    for (int i{}; i < n; i++) {
        if (phone1 == Orders[i].GetPhone()) {
            k++;
        }
    }
    cout << "Клиентом с номером телефона " << phone1 << " было заказано " << k << " автомобилей\n";
    system("pause");
    system("cls");
}
void statmenu(Order* Orders, int n) {
    int y(-1);
    while (y != 0) {
        cout << "Список операций: \n0 - Выход в предыдущее меню\n1 - Статистика по автомобилю определенной марки\n2 - Статистика по клиенту\nВыберите операцию: ";
        y = typeCheck(y);
        switch (y) {
        case 0:
            cout << endl << "0 - Выход в предыдущее меню" << endl;
            Sleep(500);
            system("cls");
            break;
        case 1:
            system("cls");
            cout << endl << "1 - Статистика по автомобилю определенной марки" << endl;
            Sleep(500);
            markstat(Orders, n);
            break;
        case 2:
            system("cls");
            cout << endl << "2 - Статистика по клиенту" << endl;
            Sleep(500);
            clientstat(Orders, n);
            break;
        default:
            cout << "Операция под таким номером отсутствует" << endl;
            Sleep(500);
        }
    }
}