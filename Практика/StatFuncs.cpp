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
    cout << "������� ����� ����������: ";
    strCheck(mark1);
    for (int i{}; i < n; i++) {
        if (strcmp(Orders[i].GetMark(), mark1) == 0) {
            k++;
        }
    }
    cout << "���� �������� " << k << " ����������� ����� " << mark1 <<"\n";
    delete[] mark1;
    system("pause");
    system("cls");
}
void clientstat(Order* Orders, int n) {
    int k{};
    long long int phone1{};
    cout << "������� �������: ";
    phone1 = typeCheck(phone1);
    for (int i{}; i < n; i++) {
        if (phone1 == Orders[i].GetPhone()) {
            k++;
        }
    }
    cout << "�������� � ������� �������� " << phone1 << " ���� �������� " << k << " �����������\n";
    system("pause");
    system("cls");
}
void statmenu(Order* Orders, int n) {
    int y(-1);
    while (y != 0) {
        cout << "������ ��������: \n0 - ����� � ���������� ����\n1 - ���������� �� ���������� ������������ �����\n2 - ���������� �� �������\n�������� ��������: ";
        y = typeCheck(y);
        switch (y) {
        case 0:
            cout << endl << "0 - ����� � ���������� ����" << endl;
            Sleep(500);
            system("cls");
            break;
        case 1:
            system("cls");
            cout << endl << "1 - ���������� �� ���������� ������������ �����" << endl;
            Sleep(500);
            markstat(Orders, n);
            break;
        case 2:
            system("cls");
            cout << endl << "2 - ���������� �� �������" << endl;
            Sleep(500);
            clientstat(Orders, n);
            break;
        default:
            cout << "�������� ��� ����� ������� �����������" << endl;
            Sleep(500);
        }
    }
}