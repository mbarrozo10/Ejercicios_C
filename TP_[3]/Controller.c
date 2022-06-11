#include <stdio.h>
#include <stdlib.h>
#include "Passenger.h"
#include "Parser.h"
#include "biblioteca.h"
#include "LinkedList.h"
#include "Controller.h"

int idIncremental=0;
/// @brief Genera el id incremental
///
/// @return Retorna el id generado
int generarId(){
	idIncremental++;
	return idIncremental;
}
/// @brief Guarda el ultimo id en el archivo de ultimo id
///
void guardarUltimoId(){
	FILE* txt;
	txt=fopen("idmaximo.txt","w");
	if(txt!=NULL){
		fprintf(txt,"%d",idIncremental);
	}
	fclose(txt);
}
/// @brief Lee el archivo de ultimo id y lo asignal al idIncremental
///
void generarPrimerId(){
	FILE* txt;
	char test[20];
	txt=fopen("idmaximo.txt","r");
	if(txt!=NULL){
		fscanf(txt,"%s",test);
	}
	idIncremental=atoi(test);
	fclose(txt);
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 	 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	FILE *txt;
	int x=1;
	txt=fopen(path,"r");
	if (txt==NULL){
		printf("No se pudo abrir el archivo\n");
	}
	else{
		x= parser_PassengerFromText(txt,pArrayListPassenger);
	}

	if(x==-1){
	fclose(txt);
	}
    return x;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	FILE *txt;
	int x=1;
	txt=fopen(path,"rb");
	if (txt==NULL){
		printf("No se pudo abrir el archivo\n");
	}
	else{
		x= parser_PassengerFromBinary(txt,pArrayListPassenger);
	}

	if(x==-1){
	fclose(txt);
	}
    return x;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int x=1;
	Passenger* p;
	char nombre[50];
	char apellido[50];
	int id;
	float precio;
	char codigo[20];
	char tipo [50];
	int subTipo;
	char status[50];
	p=Passenger_new();
	id=generarId();
	Passenger_setId(p,id);
	ingresarCadena(nombre,"Ingrese el nombre: ",50);
	Passenger_setNombre(p,nombre);
	ingresarCadena(apellido,"Ingrese el apellido: ",50);
	Passenger_setApellido(p,apellido);
	precio=ingresarFlotante("Ingrese el precio: ",0,1000000);
	Passenger_setPrecio(p,precio);
	ingresarCadena(codigo,"Ingrese el codigo de vuelo: ",20);
	Passenger_setCodigoVuelo(p,codigo);
	subTipo=ingresarEntero("Ingrese el tipo de vuelo:\n1-First Class\n2-Executive Class\n3-Economy Class\nSu opcion: ",0,4);
	switch(subTipo){
	case 1:
		strcpy(tipo,"FirstClass");
		break;
	case 2:
		strcpy(tipo,"ExecutiveClass");
		break;
	case 3:
		strcpy(tipo,"EconomyClass");
		break;
	default:
		break;
	}
	Passenger_setTipoPasajero(p,tipo);
	subTipo=ingresarEntero("Ingrese el Status del vuelo:\n1-En vuelo\n2-Aterrizado\n3-En Horario\n4-Demorado\nSu opcion: ",0,5);
		switch(subTipo){
		case 1:
			strcpy(status,"En Vuelo");
			break;
		case 2:
			strcpy(status,"Aterrizado");
			break;
		case 3:
			strcpy(status,"En horario");
			break;
		case 4:
			strcpy(status,"Demorado");
			break;
		default:
			break;
		}
	Passenger_setStatus(p,status);
	ll_add(pArrayListPassenger,p);
    return x;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
	int x=1;
	int retorno=1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigo[20];
	char tipo [50];
	char status[50];
	int eleccion;
	int subTipo;
	Passenger* p=Passenger_new();
	x=controller_ListPassenger(pArrayListPassenger);
	if(x!=0){
		id=ingresarEntero("Ingrese el id que quiera motificar: ",0,idIncremental+1);
		p=(Passenger*)findPassengerById(id,pArrayListPassenger);
		eleccion= ingresarEntero("\nIngrese la opcion a modificar\n 1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de Pasajero\n5-Codigo de vuelo\n5-Status\nSu opcion: ",0,6);
		switch(eleccion){
		case 1:
			ingresarCadena(nombre,"Ingrese el nombre: ",50);
			x= Passenger_setNombre(p,nombre);
			if(x==1){
				printf("Se cambio el nombre\n");
			}
			break;
		case 2:
			ingresarCadena(apellido,"Ingrese el apellido: ",50);
			x= Passenger_setApellido(p,apellido);
			if(x==1){
				printf("Se cambio el apellido\n");
			}
			break;
		case 3:
			precio=ingresarFlotante("Ingrese el precio: ",0,10000000);
			x= Passenger_setPrecio(p, precio);
			if(x==1){
				printf("Se cambio el precio\n");
			}
			break;
		case 5:
			ingresarCadena(codigo,"Ingrese el codigo de vuelo: ",20);
			x= Passenger_setCodigoVuelo(p, codigo);
			if(x==1){
				printf("Se cambio el codigo de vuelo\n");
			}
			break;
		case 4:
			subTipo=ingresarEntero("Ingrese el tipo de vuelo:\n1-First Class\n2-Executive Class\n3-Economy Class\nSu opcion: ",0,4);
			switch(subTipo){
			case 1:
				strcpy(tipo,"FirstClass");
				break;
			case 2:
				strcpy(tipo,"ExecutiveClass");
				break;
			case 3:
				strcpy(tipo,"EconomyClass");
				break;
			default:
				break;
				}
			x= Passenger_setTipoPasajero(p, tipo);
			if(x==1){
				printf("Se cambio el tipo de vuelo\n");
			}
			break;
		case 6:
			subTipo=ingresarEntero("Ingrese el Status del vuelo:\n1-En vuelo\n2-Aterrizado\n3-En Horario\n4-Demorado\nSu opcion: ",0,5);
			switch(subTipo){
			case 1:
				strcpy(status,"En Vuelo");
				break;
			case 2:
				strcpy(status,"Aterrizado");
				break;
			case 3:
				strcpy(status,"En horario");
				break;
			case 4:
				strcpy(status,"Demorado");
				break;
			default:
				break;
			}
			x= Passenger_setStatus(p,status);
			if(x==1){
				printf("Se cambio el status del vuelo\n");
			}
			break;
		default:
			printf("Ingrese una opcion valida");
			break;
		}
	}
	else{
		retorno=0;
	}
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int id;
	int index;
	Passenger* p =Passenger_new();
	int x;
	char eleccion;
	x= controller_ListPassenger (pArrayListPassenger);
	if (x!=0){
		id=ingresarEntero("Ingrese el id que quiera borrar: ",0,idIncremental+1);
		p=(Passenger*)findPassengerById(id, pArrayListPassenger);
		index=ll_indexOf(pArrayListPassenger,p);
		printf("Vas a borrar a:\n%4d %14s %14s %14f %14s %14s %14s\n ",p->id,p->nombre,p->apellido,p->precio,p->codigoVuelo,p->tipoPasajero,p->status);
		eleccion=ingresarCheckCaracter("Estas seguro de que quieres borrar? S/N\n Su opcion: ",'s','n');
		if (eleccion=='s'){
			Passenger_delete(p);
			ll_remove(pArrayListPassenger,index);
		retorno=1;
		}
	}
	else{
		retorno=0;
	}

    return retorno;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int id;
	char nombre[50];
	char apellido[50];
	char tipo[50];
	float precio;
	char codigo[20];
	char status[50];
	int i=0;
	Passenger*aux;
	int x=ll_len(pArrayListPassenger);
	for(i=0;i<x;i++){
		aux=(Passenger*) ll_get(pArrayListPassenger,i);
		Passenger_getId(aux,&id);
		Passenger_getNombre(aux,nombre);
		Passenger_getApellido(aux,apellido);
		Passenger_getPrecio(aux,&precio);
		Passenger_getCodigoVuelo(aux,codigo);
		Passenger_getTipoPasajero(aux,tipo);
		Passenger_getStatus(aux,status);
		if(aux!=NULL){
		printf("%4d %14s %14s %14.2f %14s %14s %14s\n ",id,nombre,apellido,precio,codigo,tipo,status);
		}
	}
    return i;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int eleccion;
	int retorno;
	int orden;
	if(pArrayListPassenger!=NULL && ll_isEmpty(pArrayListPassenger) ==0){
		eleccion=ingresarEntero("Ingrese el valor por el cual quiere ordenar:\n1-Id\n2-Nombre\n3-Apellido\n4-Precio\n5-Tipo de pasajero\n6-Codigo de vuelo\n7-Status\n8-Salir\nSu opcion:",0,9);
		orden=ingresarEntero("Ingrese el orden:\n0-Descendente\n1-Ascendente\nSu opcion:",-1,2);
		switch(eleccion){
		case 1:
			retorno=ll_sort(pArrayListPassenger,compareById,orden);
			break;
		case 2:
			retorno=ll_sort(pArrayListPassenger,compareByNombre,orden);
			break;
		case 3:
			retorno=ll_sort(pArrayListPassenger,compareByApellido,orden);
			break;
		case 4:
			retorno=ll_sort(pArrayListPassenger,compareByPrecio,orden);
			break;
		case 5:
			retorno=ll_sort(pArrayListPassenger,compareByTipoPasajero,orden);
			break;
		case 6:
			retorno=ll_sort(pArrayListPassenger,compareByCodigo,orden);
			break;
		case 7:
			retorno=ll_sort(pArrayListPassenger,compareByStatus,orden);
			break;
		default:
			break;
		}
		retorno=1;
	}
	else{
		retorno=0;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int i=1;
	int id;
	char nombre[50];
	char apellido[50];
	char tipo[50];
	float precio;
	char codigo[20];
	char status[50];
	int cant=ll_len(pArrayListPassenger);
	Passenger* aux;
	FILE* txt=fopen(path,"w");
	if(txt==NULL){
		printf("El archivo no se pudo abrir\n");
	}
	else{
		fprintf(txt,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");
		for(i=0;i<cant;i++){
			aux=(Passenger*) ll_get(pArrayListPassenger,i);
			Passenger_getId(aux, &id);
			Passenger_getNombre(aux, nombre);
			Passenger_getApellido(aux, apellido);
			Passenger_getPrecio(aux, &precio);
			Passenger_getTipoPasajero(aux, tipo);
			Passenger_getCodigoVuelo(aux, codigo);
			Passenger_getStatus(aux, status);
			if(aux!=NULL){
			fprintf(txt,"%d,%s,%s,%f,%s,%s,%s\n",id,nombre,apellido,precio,tipo,codigo,status);
			}
		}
	}
	fclose(txt);
	guardarUltimoId();
    return cant;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int i=1;
	int cant=ll_len(pArrayListPassenger);
	Passenger* aux;
	FILE* txt=fopen(path,"wb");
	if(txt==NULL){
		printf("El archivo no se pudo abrir\n");
	}
	else{
		for(i=0;i<cant;i++){
			aux=(Passenger*) ll_get(pArrayListPassenger,i);
			if(aux!=NULL){
				fwrite(aux,sizeof(Passenger),1,txt);
			}
		}
	}
	fclose(txt);
	guardarUltimoId();
	return cant;
}
