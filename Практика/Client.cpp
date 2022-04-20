#include <string>
#include <iostream>
#include <iomanip>
#include "Client.h"
Client::Client() {
    strcpy_s(lname, NAME_SIZE, "");
    strcpy_s(fname, NAME_SIZE, "");
    strcpy_s(sname, NAME_SIZE, "");
    strcpy_s(adress, ADRESS_SIZE, "");
    phone = 0;
    drive_experience = 0;
}
void Client::SetLName(const char* lname1) {
    strcpy_s(lname, NAME_SIZE, lname1);
}
void Client::SetFName(const char* fname1) {
    strcpy_s(fname, NAME_SIZE, fname1);
}
void Client::SetSName(const char* sname1) {
    strcpy_s(sname, NAME_SIZE, sname1);
}
void Client::SetAdress(const char* adress1) {
    strcpy_s(adress, ADRESS_SIZE, adress1);
}
void Client::SetPhone(const long long int phone1) {
    phone = phone1;
}
void Client::SetDriveExperience(int drive_experience1) {
    drive_experience = drive_experience1;
}
char* Client::GetLName() {
    return lname;
}
char* Client::GetFName() {
    return fname;
}
char* Client::GetSName() {
    return sname;
}
char* Client::GetAdress() {
    return adress;
}
long long int Client::GetPhone() {
    return phone;
}
int Client::GetDriveExperience() {
    return drive_experience;
}
void Client::print() {
    std::cout << std::setw(NAME_SIZE) << lname << '|' << std::setw(NAME_SIZE) << fname << '|' << std::setw(NAME_SIZE) << sname << '|' << std::setw(ADRESS_SIZE) << adress << '|' << std::setw(PHONE_SIZE + 1) << phone << '|' << std::setw(8) << drive_experience << "     |" << std::endl;
}
Client::~Client() {
    delete[] lname;
    delete[] fname;
    delete[] sname;
    delete[] adress;
}