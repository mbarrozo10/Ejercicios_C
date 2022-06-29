/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#define PATH "datos_SP.csv"
#include "biblioteca.h"
typedef struct{
	int id;
	char descripcion[20];
	float precio;
	int idTipo;
}eComputadora;

void lectura (LinkedList* list,char* path);
eComputadora* newPc(char* id, char* desc,char* precio, char* idTipo);
int main(void)
{
	setbuf(stdout, NULL);
	LinkedList* lista;
	lista= ll_newLinkedList();
	int eleccion;
	eleccion=ingresarEntero("1-cargar archivo\n2-ordenar\n3-imprimir\n4-ll_map\n5-guardar llmap", 0, 6);
	while(eleccion!=6){
		switch(eleccion){
		case 1:
			lectura(lista,PATH);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			break;
		}
	}
    return 0;
}

eComputadora* newPc(char* id, char* desc,char* precio, char* idTipo){
	eComputadora* aux;
	aux= (eComputadora*)malloc(sizeof(eComputadora));
	if (aux!=NULL){
		aux->id=atoi(id);
		strcpy(aux->descripcion,desc);
		aux->precio=atof(precio);
		aux->idTipo=atoi(idTipo);
	}
	else{
		printf("Error");
	}
	return aux;
}

void lectura (LinkedList* list, char* path){
	FILE* archivo;
	eComputadora* p=NULL;
	char id[20];
	char descripcion[20];
	char precio[20];
	char idTipo[20];
	 archivo=fopen(path,"r");
	 if (archivo!=NULL){
		 while(!feof(archivo)){
			 fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);
			 p=newPc(id,descripcion,precio,idTipo);
			 if(p!=NULL){
				 ll_add(list,p);
			 }
		 }
	fclose(archivo);
	 }
}





























