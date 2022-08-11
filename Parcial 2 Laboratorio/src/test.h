#ifndef TEST_H
#define TEST_H

typedef struct{
	int id;
	char descripcion[200];
	float precio;
	int idTipo;
}eComputadora;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"

void lectura (LinkedList* list,FILE* path);
int loadPc(char* path , LinkedList* pArrayListPassenger);
eComputadora* newPc(char* id, char* desc,char* precio, char* idTipo);
int printPc(LinkedList* pArrayListPassenger);

int pc_getIdTipo(eComputadora* this,int* idTipo);
int compareByIdTipo(void* pasajeroUno, void* pasajeroDos);
void precioAumenta(void* aux);
int pc_setprecio(eComputadora* this,float precio);
void savePc(LinkedList* list);
#endif
