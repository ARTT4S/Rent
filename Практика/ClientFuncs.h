#include "Client.h"

#ifndef CLIENTFUNCS_H
#define CLIENTFUNCS_H
void clientmenu(Client* Clients, int* n);
void addclient(Client* Clients, int* n);
void changeclient(Client* Clients, int* n);
void deleteclient(Client* Clients, int* n);
void showclients(Client* Clients, int n);
void fileinclient(Client* Clients, int n);
void fileoutclient(Client* Clients, int* n);
#endif