#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include <string.h>
#include "Biblioteca.h"
#include "Parser.h"
#define ARCH "data.csv"
#define BIN "data.bin"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	int eleccion, opcionUno=0, opcionDos=0, opcionTres,opcionOcho=0, opcionSeis=0,opcionCuatro=0, opcionCinco=0, opcionNueve=0,opcionSiete=0;
	int flagArchivos=0;
	int flagSalir=0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    generarPrimerId();
    do{
    	eleccion=ingresarEntero("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto)\n2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario)\n"
    						"3. Alta de pasajero\n4. Modificar datos de pasajero\n5. Baja de pasajero\n6. Listar pasajeros\n7. Ordenar pasajeros\n"
    						"8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n"
    						"10. Salir\nSu opcion: ",0,11);
    	switch(eleccion){
    	case 1:
    		if(flagArchivos==0){
				opcionUno=controller_loadFromText(ARCH,listaPasajeros);
				flagArchivos=1;
				if(opcionUno==-1){
					printf("Se cargo todo ok\n");
					flagSalir= ll_len(listaPasajeros);
				}
    		}
    		else{
    			printf("Ya se cargo el archivo en modo binario\n");
    		}
    		break;
    	case 2:
    		if (flagArchivos==0){
				opcionDos=controller_loadFromBinary(BIN, listaPasajeros);
				flagArchivos=1;
				if(opcionDos==-1){
					printf("Se cargo todo ok\n");
					flagSalir= ll_len(listaPasajeros);
				}
    		}
    		else{
    			printf("Ya se cargo el archivo en modo texto\n");
    		}
    		break;
    	case 3:
    		opcionTres= controller_addPassenger(listaPasajeros);
    		if(opcionTres==1){
    			printf("Se agrego un pasajero\n");
    			flagSalir++;
    		}
    		break;
    	case 4:
    		opcionCuatro=controller_editPassenger(listaPasajeros);
    		if (opcionCuatro==0){
    			printf("No se cargo ningun pasajero para modificar\n");
    		}
    		break;
    	case 5:
    		opcionCinco=controller_removePassenger(listaPasajeros);
    		if (opcionCinco==0){
				printf("No se cargo ningun pasajero para borrar\n");
			}
    		else{
    			printf("Se borro exitosamente\n");
    			flagSalir--;
    		}
    		break;
    	case 6:
    		opcionSeis=controller_ListPassenger(listaPasajeros);
    		if(opcionSeis==0){
    			printf("No hay nada que listar\n");
    		}
    		break;
    	case 7:
    		opcionSiete=controller_sortPassenger(listaPasajeros);
    		if(opcionSiete==1){
    			printf("Se ordeno como se pidio!\n");
    		}
    		else{
    			printf("Ocurrio algun error!\n");
    		}
    		break;
    	case 8:
    		opcionOcho=controller_saveAsText(ARCH , listaPasajeros);
    		if(opcionOcho==0){
    			printf("No hay nada que guardar\n");
    		}
    		else{
				printf("Se guardo todo correctamente en archivo texto\n");
				flagSalir=0;
			}
    		break;
    	case 9:
    		opcionNueve=controller_saveAsBinary(BIN,listaPasajeros);
    		if(opcionNueve==0){
				printf("No hay nada que guardar\n");
			}
    		else{
    			printf("Se guardo todo correctamente en archivo Binario\n");
    			flagSalir=0;
    		}
    		break;
    	case 10:
    		if(flagSalir==0){
    			eleccion=11;
    		break;
    		}
    		else{
    			printf("No se guardo ningun archivo!!\n");
    			break;
    		}
    	default:
			break;
    	}

    }while(eleccion!=11);
}
