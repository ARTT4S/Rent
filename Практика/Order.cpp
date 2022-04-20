#include "Order.h"
#include <string>
#include <iostream>
#include <iomanip>
Order::Order() {
    number = 0;
    carnumber = 0;
    strcpy_s(mark, MARK_SIZE, "");
    phone = 0;
    strcpy_s(date, DATE_SIZE, "");
    strcpy_s(back_date, DATE_SIZE, "");
}
void Order::SetNumber(int number1) {
    number = number1;
}
void Order::SetCarnumber(int carnumber1) {
    carnumber = carnumber1;
}
void Order::SetMark(const char* mark1) {
    strcpy_s(mark, MARK_SIZE, mark1);
}
void Order::SetPhone(const long long int phone1) {
    phone = phone1;
}
void Order::SetDate(const char* date1) {
    strcpy_s(date, DATE_SIZE, date1);
}
void Order::SetBackDate(const char* back_date1) {
    strcpy_s(back_date, DATE_SIZE, back_date1);
}
int Order::GetNumber() {
    return number;
}
int Order::GetCarnumber() {
    return carnumber;
}
char* Order::GetMark() {
    return mark;
}
long long int Order::GetPhone() {
    return phone;
}
char* Order::GetDate() {
    return date;
}
char* Order::GetBackDate() {
    return back_date;
}
void Order::print() {
    std::cout << '|' << std::setw(5) << number << '|' << std::setw(13) << carnumber << '|' << std::setw(MARK_SIZE) << mark << '|' << std::setw(ORDERPHONE_SIZE) << phone << '|' << std::setw(DATE_SIZE) << date << '|' << std::setw(DATE_SIZE+2) << back_date << '|' << std::endl;
}
Order::~Order() {
    delete[] mark;
    delete[] date;
    delete[] back_date;
}