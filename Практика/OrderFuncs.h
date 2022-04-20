#include "Order.h"
#include "Autos.h"
#include "Client.h"
#ifndef ORDERFUNCS_H
#define OREDRFUNCS_H
void ordermenu(Order* Orders, Autos* Cars, Client* Clients, int* n, int* q, int* l);
void addorder(Order* Orders, Autos* Cars, Client* Clients, int* n, int q, int l);
void changeorder(Order* Orders, Autos* Cars, Client* Clients, int* n, int q, int l);
void deleteorder(Order* Orders, int* n);
void showorders(Order* Orders, int* n);
void fileinorder(Order* Orders, int* n);
void fileoutorder(Order* Orders, int* n);
#endif
