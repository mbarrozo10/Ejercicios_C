#include "validations.h"
#include "Controller.h"
#include "funciones.h"
#include "parser.h"
#include "linkedlist.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAT_LEN 2
int main(void) {
	setbuf(stdout,NULL);
	int option;
	eCategoria categoria[CAT_LEN] = {{1,"MENOR"},{2,"MAYOR"}};
	LinkedList* pList = ll_newLinkedList();

	do
			{
				controller_Menu();
				option = EnterNumberInt("Ingrese una opcion: ", "Error, Ingrese una funcion valida; ", 5, 0);

		while((option != 1 && option != 0) && controller_CheckListStatus(pList) != 0)
	    			{
	    				system("cls");
	    				printf("Primero debera cargar la lista para poder utilizar todas las funciones\n\n");
	    				controller_Menu();
	    				option = EnterNumberInt("Ingrese una opcion: ", "Error, Ingrese una opcion valida: ", 5, 0);
	    			}

			switch(option)
					{
					case 1:
						controller_loadFromText("datos_RSP_M1.csv", pList);
							break;

					case 2:
						controller_sort(pList);
							break;

					case 3:
						controller__Print(pList, categoria, CAT_LEN);
							break;

					case 4:
						controller_filter(pList,categoria, CAT_LEN);
							break;

					case 5:

							break;
					case 0:

							break;
					}

		}while(option != 0);

	    return 0;
}

