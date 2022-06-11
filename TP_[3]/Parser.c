#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
//#include "Parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int x=0;;
	char nombre[50];
	char apellido[50];
	char id[50];
	char precio[50];
	char codigo[20];
	char tipo [50];
	char status[50];
	Passenger* p;
	fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,tipo,status);
	while (!feof(pFile)){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,apellido,precio,codigo,tipo,status);
		p=Passenger_newParametros(id,nombre,tipo,apellido,precio,codigo, status);
		if(p!=NULL){
			ll_add(pArrayListPassenger,p);
			x=-1;
		}
		else{
			printf("Error al asignar el pasajero\n");
		}

	}
    return x;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int x=0;;
	Passenger* p=NULL;
	if (pArrayListPassenger!=NULL&&pFile!=NULL){
		while (!feof(pFile)){
			p=Passenger_new();
			if(p!=NULL&&fread(p,sizeof(Passenger),1,pFile)){
				ll_add(pArrayListPassenger,p);
			}
			else{
				printf("error");
			}
			x=-1;
		}
		}
    return x;
}
