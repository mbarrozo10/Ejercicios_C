/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"


typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[10];
	char status[20];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* tipoPasajerosStr, char* apellido, char* precio, char* codigo, char* status);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setStatus(Passenger* this, char* status);
int Passenger_getStatus(Passenger* this, char* status);

void* findPassengerById(int id, LinkedList* list);

int compareById(void* pasajeroUno, void* pasajeroDos);
int compareByNombre(void* pasajeroUno, void* pasajeroDos);
int compareByApellido(void* pasajeroUno, void* pasajeroDos);
int compareByTipoPasajero(void* pasajeroUno, void* pasajeroDos);
int compareByCodigo(void* pasajeroUno, void* pasajeroDos);
int compareByStatus(void* pasajeroUno, void* pasajeroDos);
int compareByPrecio(void* pasajeroUno, void* pasajeroDos);

#endif /* PASSENGER_H_ */
