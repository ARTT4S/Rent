#include "Autos.h"
#include "Client.h"
#include "Order.h"
#include <fstream>
#include <iostream>
using namespace std;
#ifndef FUNCS_H
#define FUNCS_H
long long int typeCheck(long long int n);
int typeCheck(int n, int min, int max);
bool PhoneCheck(long long int phone1, Client* Clients, int n);
bool NumberCheck(int carnumber1, Autos* Cars, int n);
bool MarkCheck(char* mark1, Autos* Cars, int n);
void strCheck(char* string);
bool dateSymbolCheck(char* string);
void intParse(char* string1, int* integer, int* i, char symbol);
void dateCheck(char* time);
void dateCheck(char* time1, char* time2);
void SimilaryCheckNum(Autos* Cars, int quont, int* n, int min, int max);
void SimilaryCheckPhone(Client* Clients, int quont, long long int* n);
void Read(fstream& File, char* string, char symbol);
void Read(fstream& File, int* integer, char symbol);
void Read(fstream& File, long long int* integer, char symbol);
#endif
