/*
TP2 MATIAS BARROZO 1F
 */

#include "biblioteca.h"
#include "ArrayPassenger.h"
#define TAM 2000



int main(void) {
	setbuf(stdout, NULL);
	int eleccion;
	int x;
	Passenger list[TAM];
	Passenger carga[5]={{0,"Jose","Argento",40000,"a2392d",1,0,0},
						{1,"Lupin","Elgato",30000,"a2392d",2,0,1},
						{2,"Pepe","Argento",4000,"b29d2",3,0,0},
						{3,"Pablo","Ferrete",50000,"eg292d",3,0,1},
						{4,"Homero J","Simpson",10000,"bsa2042",1,0,1}};
	typePassenger type[3]={{1,"Economico"},{2,"Ejecutiva"},{3,"Premium"}};
	eleccion=0;
	x=initPassenger(list, TAM);
	if (x==0){
		do{
		eleccion=ingresarEntero("1-Dar alta un pasajero\n2-Modificar pasajero\n3-Dar de baja un pasajero\n4-Informar\n5-Carga Forzada\n6-Salir\n\nSu opcion: ",0,7);
		switch(eleccion){
		case 1:
			ingresarAlta(list, TAM);
			break;
		case 2:
			modificarPasajero(list,TAM,type);
			break;
		case 3:
			remover(list,type);
			break;
		case 4:
			listar(list,type);
			break;
		case 5:
			listar(carga,type);
			break;
		case 6:
			break;
		}
}while (eleccion!=6);
	}
	return 0;
}
