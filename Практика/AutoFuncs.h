#include "Autos.h"
#include <fstream>

#ifndef AUTOFUNCS_H
#define AUTOFUNCS_H
void automenu(Autos cars[], int* quont);
void deleteCar(Autos cars[], int* quont);
void addCar(Autos cars[], int* quont);
void changeCar(Autos cars[], int quont);
void writeCar(Autos cars[], int quont);
void fileinCar(Autos cars[], int* quont);
void fileoutCar(Autos cars[], int quont);
#endif
