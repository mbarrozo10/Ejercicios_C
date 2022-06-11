#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "Parser.h"
#include "biblioteca.h"
#include "LinkedList.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);

int generarId();
void guardarUltimoId();
void generarPrimerId();

#endif /* CONTROLLER_H_ */
