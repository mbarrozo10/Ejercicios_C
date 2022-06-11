/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
/// @brief Asigna el passenger cuando se carga en modo texto
///
/// @param idStr
/// @param nombreStr
/// @param tipoPasajerosStr
/// @param apellido
/// @param precio
/// @param codigo
/// @param status
/// @return Passanger*
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* tipoPasajerosStr, char* apellido, char* precio, char* codigo, char* status){
	Passenger* unPasajero=Passenger_new();
	if(unPasajero!=NULL){
		Passenger_setId(unPasajero,atoi(idStr));
		Passenger_setNombre(unPasajero,nombreStr);
		Passenger_setApellido(unPasajero,apellido);
		Passenger_setPrecio(unPasajero,atof(precio));
		Passenger_setCodigoVuelo(unPasajero,codigo);
		Passenger_setTipoPasajero(unPasajero,tipoPasajerosStr);
		Passenger_setStatus(unPasajero,status);
	}else{
		printf("Ocurrio un error reservando memoria\n");
	}
		return unPasajero;
}
/// @brief Constructor de Passanger
///
/// @return Puntero a Passenger
Passenger* Passenger_new(){
	Passenger* unPasajero;
	unPasajero= (Passenger*)malloc(sizeof(Passenger));
	return unPasajero;
}
/// @brief Libera el espacio en memoria cuando se borra
///
/// @param this
void Passenger_delete(Passenger* this){
	free(this);
}
/// @brief Setea el id
///
/// @param this
/// @param id
/// @return
int Passenger_setId(Passenger* this,int id){
	int x=1;
	this->id=id;
	return x;
}
/// @brief Obtiene el id
///
/// @param this
/// @param id
/// @return
int Passenger_getId(Passenger* this,int* id){
	if(this!=NULL){
	*id=this->id;
	}
	return 1;
}

/// @brief Setea el nombre
///
/// @param this
/// @param nombre
/// @return
int Passenger_setNombre(Passenger* this,char* nombre){
	int x=1;
	if (nombre!=NULL){
	strcpy(this->nombre, nombre);
	}
	return x;
}
/// @brief Obtiene el nombre
///
/// @param this
/// @param nombre
/// @return
int Passenger_getNombre(Passenger* this,char* nombre){
	if (this!=NULL){
	strcpy(nombre,this->nombre);
	}
	return 1;
}

/// @brief Setea el apellido
///
/// @param this
/// @param apellido
/// @return
int Passenger_setApellido(Passenger* this,char* apellido){
	int x=0;
	if(apellido!=NULL){
	strcpy(this->apellido,apellido);
	}
	return x;
}

/// @brief Obtiene el apellido
///
/// @param this
/// @param apellido
/// @return
int Passenger_getApellido(Passenger* this,char* apellido){
	if (this!=NULL){
	strcpy(apellido,this->apellido);
	}
	return 1;
}

/// @brief Setea el precio
///
/// @param this
/// @param precio
/// @return
int Passenger_setPrecio(Passenger* this,float precio){
	int x=0;
	this->precio=precio;
	return x;
}
/// @brief Obtiene el precio
///
/// @param this
/// @param precio
/// @return
int Passenger_getPrecio(Passenger* this,float* precio){
	if(this!=NULL){
	*precio=this->precio;
	}
	return 1;
}

/// @brief obtiene el codigo de vuelo
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	if (this!=NULL){
	strcpy(codigoVuelo,this->codigoVuelo);
	}
	return 1;
}

/// @brief Setea el codigo de vuelo
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int x=0;
	if(codigoVuelo!=NULL){
	strupr(codigoVuelo);
	strcpy(this->codigoVuelo, codigoVuelo);
	}
	return x;
}

/// @brief Setea el tipo de pasajero
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero){
	int x=0;
	if(tipoPasajero!=NULL){
	strcpy(this->tipoPasajero,tipoPasajero);
	}
	return x;
}

/// @brief Obtiene el tipo de pasajero
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero){
	if(this!=NULL){
	strcpy(tipoPasajero,this->tipoPasajero);
	}
	return 1;
}

/// @brief Setea el estado de vuelo
///
/// @param this
/// @param status
/// @return
int Passenger_setStatus(Passenger* this, char* status){
	int x=0;
	if(status!=NULL){
	strcpy(this->status,status);
	}
	return x;
}

/// @brief Obtiene el estado de vuelo
///
/// @param this
/// @param status
/// @return
int Passenger_getStatus(Passenger* this, char* status){
	if (this!=NULL){
	strcpy(status,this->status);
	}
	return 1;
}

/// @brief Encuentra una structura por un id
///
/// @param id
/// @param list
void* findPassengerById(int id, LinkedList* list){
	Passenger* aux;
	int i=0;
	int idP;
	int x=ll_len(list);
	for(i=0;i<x;i++){
		aux=(Passenger*)ll_get(list,i);
		Passenger_getId(aux,&idP);
		if(id==idP){
			break;
		}
	}
	return aux;
}

/// @brief Compara id
///
/// @param pasajeroUno
/// @param pasajeroDos
/// @return
int compareById(void* pasajeroUno, void* pasajeroDos){
	int retorno=-1;
	int idUno=0;
	int idDos=0;

	if (pasajeroUno!=NULL && pasajeroDos!=NULL){
		Passenger_getId((Passenger*)pasajeroUno,&idUno);
		Passenger_getId((Passenger*)pasajeroDos,&idDos);
		if(idUno>idDos){
			retorno=1;
		}else if(idUno<idDos){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

/// @brief Compara nombre
///
/// @param pasajeroUno
/// @param pasajeroDos
/// @return
int compareByNombre(void* pasajeroUno, void* pasajeroDos){
	char nombreUno[50];
	char nombreDos[50];
	int retorno=0;
	int test;
	if(pasajeroUno!=NULL&&pasajeroDos!=NULL){
		Passenger_getNombre((Passenger*)pasajeroUno,nombreUno);
		Passenger_getNombre((Passenger*)pasajeroDos,nombreDos);
		strlwr(nombreUno);
		strlwr(nombreDos);
		test=strcmp(nombreUno,nombreDos);
		if(test>0){
			retorno=1;
		}
		else if(test<0){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

/// @brief Compara apellido
///
/// @param pasajeroUno
/// @param pasajeroDos
/// @return
int compareByApellido(void* pasajeroUno, void* pasajeroDos){
	char apellidoUno[50];
	char apellidoDos[50];
	int retorno=0;
	int test;
	if(pasajeroUno!=NULL&&pasajeroDos!=NULL){
		Passenger_getApellido((Passenger*)pasajeroUno,apellidoUno);
		Passenger_getApellido((Passenger*)pasajeroDos,apellidoDos);
		strlwr(apellidoUno);
		strlwr(apellidoDos);
		test=strcmp(apellidoUno,apellidoDos);
		if(test>0){
			retorno=1;
		}
		else if(test<0){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

/// @brief Compara por tipo de pasajero
///
/// @param pasajeroUno
/// @param pasajeroDos
/// @return
int compareByTipoPasajero(void* pasajeroUno, void* pasajeroDos){
	char tipoUno[50];
	char tipoDos[50];
	int retorno=0;
	int test;
	if(pasajeroUno!=NULL&&pasajeroDos!=NULL){
		Passenger_getTipoPasajero((Passenger*)pasajeroUno,tipoUno);
		Passenger_getTipoPasajero((Passenger*)pasajeroDos,tipoDos);
		strlwr(tipoUno);
		strlwr(tipoDos);
		test=strcmp(tipoUno,tipoDos);
		if(test>0){
			retorno=1;
		}
		else if(test<0){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

/// @brief Compara por codigo de vuelo
///
/// @param pasajeroUno
/// @param pasajeroDos
/// @return
int compareByCodigo(void* pasajeroUno, void* pasajeroDos){
	char codigoUno[50];
	char codigoDos[50];
	int retorno=0;
	int test;
	if(pasajeroUno!=NULL&&pasajeroDos!=NULL){
		Passenger_getCodigoVuelo((Passenger*)pasajeroUno,codigoUno);
		Passenger_getCodigoVuelo((Passenger*)pasajeroDos,codigoDos);
		strlwr(codigoUno);
		strlwr(codigoDos);
		test=strcmp(codigoUno,codigoDos);
		if(test>0){
			retorno=1;
		}
		else if(test<0){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

/// @brief Compara por estado de vuelo
///
/// @param pasajeroUno
/// @param pasajeroDos
/// @return
int compareByStatus(void* pasajeroUno, void* pasajeroDos){
	char statusUno[50];
	char statusDos[50];
	int retorno=0;
	int test;
	if(pasajeroUno!=NULL&&pasajeroDos!=NULL){
		Passenger_getStatus((Passenger*)pasajeroUno,statusUno);
		Passenger_getStatus((Passenger*)pasajeroDos,statusDos);
		strlwr(statusUno);
		strlwr(statusDos);
		test=strcmp(statusUno,statusDos);
		if(test>0){
			retorno=1;
		}
		else if(test<0){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

/// @brief Compara por precio
///
/// @param pasajeroUno
/// @param pasajeroDos
/// @return
int compareByPrecio(void* pasajeroUno, void* pasajeroDos){
	int retorno=-1;
	float precioUno=0;
	float precioDos=0;

	if (pasajeroUno!=NULL && pasajeroDos!=NULL){
		Passenger_getPrecio((Passenger*)pasajeroUno,&precioUno);
		Passenger_getPrecio((Passenger*)pasajeroDos,&precioDos);
		if(precioUno>precioDos){
			retorno=1;
		}else if(precioUno<precioDos){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}
