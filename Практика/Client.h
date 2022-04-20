#ifndef CLIENT_H
#define CLIENT_H
enum ClientConsts {
    CLIENT_SIZE = 10,
    NAME_SIZE = 16,
    ADRESS_SIZE = 30,
    PHONE_SIZE = 11,
    FILE_SIZE = 30,
};
#pragma once
class Client {
private:
    char* lname = new char[NAME_SIZE] {};
    char* fname = new char[NAME_SIZE] {};
    char* sname = new char[NAME_SIZE] {};
    char* adress = new char[ADRESS_SIZE] {};
    long long int phone{};
    int drive_experience{};
public:
    Client();
    void SetLName(const char* lname1);
    void SetFName(const char* fname1);
    void SetSName(const char* sname1);
    void SetAdress(const char* adress1);
    void SetPhone(const long long int phone1);
    void SetDriveExperience(int drive_experience1);
    char* GetLName();
    char* GetFName();
    char* GetSName();
    char* GetAdress();
    long long int GetPhone();
    int GetDriveExperience();
    void print();
    ~Client();
};
#endif
