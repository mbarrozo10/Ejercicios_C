#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca.h"

struct{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int isEmpty;
	int statusFlight; //0 INACTIVO 1 ACTIVO
}typedef Passenger;

struct{
	int id;
	char descripcion[20];
}typedef typePassenger;

void ingresarAlta(Passenger list[],int tam);
void informarTest(Passenger list[],int indicador);
void modificarPasajero (Passenger list[], int tam);
void remover(Passenger list[]);
int comprobarAlta(Passenger list[]);
int initPassenger(Passenger list[],int len);
int addPassenger(Passenger list[],int len, int id,char name[],char lastName[],float price, int typePassenger, char flycode[],int statusFlight);
int findPassengerById(Passenger list[],int len, int id);
int removePassenger(Passenger list[],int len, int id);
int sortPassenger(Passenger list[],int len, int order);
int printPassenger(Passenger list[], int len,typePassenger type[]);
int sortPassengerByCode(Passenger list[], int len, int order,typePassenger type[]);
void calcularPromedio (Passenger list[],int* pTotal, int* pCanti, float* pPromedio);
void listar (Passenger list[],typePassenger type[]);

#endif
