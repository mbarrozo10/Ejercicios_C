/*
 ============================================================================
 Name        : Parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "../testing/inc/main_test.h"
#include "LinkedList.h"
#define ARCH "datos_SP.csv"
#include "biblioteca.h"
#include "test.h"


int main(void)
{
	setbuf(stdout, NULL);
	LinkedList* lista=ll_newLinkedList();

	int eleccion=0;

	do{
		eleccion=ingresarEntero("1-cargar archivo\n2-ordenar\n3-imprimir\n4-ll_map\n5-guardar llmap\n", 0, 7);
		switch(eleccion){
		case 1:
			loadPc(ARCH,lista);
			break;
		case 2:
			ll_sort(lista,compareByIdTipo,1);
			break;
		case 3:
			printPc(lista);
			break;
		case 4:
			ll_map(lista, precioAumenta);
			break;
		case 5:
			savePc(lista);
			break;
		default:
			break;
		}
	}while(eleccion!=6);
    return 0;
}

