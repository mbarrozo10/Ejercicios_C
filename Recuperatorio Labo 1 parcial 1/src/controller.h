#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "linkedlist.h"
#include "parser.h"

void controller_Menu();
int controller_CheckListStatus(LinkedList* pList);
int controller_loadFromText(char* path, LinkedList* pList);
int controller__Print(LinkedList* pList, eCategoria* categoria, int len);
int controller_sort(LinkedList* pList);
int controller_filter(LinkedList* pList,eCategoria* pCategoria,int len);
#endif /* CONTROLLER_H_ */
