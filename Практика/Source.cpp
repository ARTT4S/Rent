#include <iostream>
#include <windows.h>
#include "Autos.h"
#include "Client.h"
#include "Order.h"
#include "AutoFuncs.h"
#include "ClientFuncs.h"
#include "OrderFuncs.h"
#include "StatFuncs.h"
#include "Funcs.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int y{1}, n{}, quont{}, l{};
    Client* Clients = new Client[CLIENT_SIZE]{};
    Autos* Cars = new Autos[AUTO_SIZE]{};
    Order* Orders = new Order[ORDER_SIZE]{};
    cout << "Начало работы программы" << endl;
    while (y != 0) {
        cout << "Список операций: \n1 - Автомобили\n2 - Клиенты\n3 - Заказы\n4 - Статистика\n0 - Выход\nВыберите операцию: ";
        y = typeCheck(y);
        switch (y) {
            case 1:
                system("cls");
                automenu(Cars, &quont);
                break;
            case 2:
                system("cls");
                clientmenu(Clients, &n);
                break;
            case 3:
                system("cls");
                ordermenu(Orders, Cars, Clients, &l, &quont, &n);
                break;
            case 4:
                system("cls");
                statmenu(Orders, l);
                break;
            case 0:
                cout << endl << "0 - Выход" << endl;
                break;
            default:
                cout << "Операция под таким номером отсутствует" << endl;
        }
    }
    return 0;
}
