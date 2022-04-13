/*
TP N°1 MATIAS BARROZO 1F
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);
	int seleccion, subseleccion, comprobacion;
	float kilometraje, aerolineas, latam, precioAerolineas[4], precioLatam[4], descuentoDebito, interesCredito, bitcoin, diferencia ;
	kilometraje=0;
	aerolineas=0;
	latam=0;
	descuentoDebito=0.90;
	interesCredito=1.25;
	bitcoin=4606954.55;
	while (seleccion!=6){
		printf("1- Ingresar kilometraje (km=%fkm)\n2- Ingresar presio del vuelo (aerolineas: %f$, latam:%f$)\n3- Calcular todos los costos\n4- Informar resultado\n5- Carga forzada\n6- Salir\nSu ingreso: ",kilometraje, aerolineas, latam);
		scanf("%d",&seleccion);
		system("cls");
		while(seleccion<1||seleccion>6){
				printf("Error\n1- Ingresar kilometraje (km=%fkm)\n2- Ingresar presio del vuelo (aerolineas: %f$, latam:%f$)\n3- Calcular todos los costos\n4- Informar resultado\n5- Carga forzada\n6- Salir\nSu ingreso: ",kilometraje,aerolineas,latam);
				scanf("%d",&seleccion);
				}
		system("cls");
		switch (seleccion){
			case 1:
				kilometraje=ingresarNumeros("Kilometraje");
				system("cls");
				break;
			case 2:
				subseleccion=subMenu(aerolineas, latam);
				if (subseleccion==1){
					aerolineas= ingresarNumeros("precio del pasaje");
				}
				else {
					latam=ingresarNumeros("precio del pasaje");
				}
				system("cls");
				break;
			case 3:
				comprobacion=comprobarIngreso(kilometraje,aerolineas,latam);
				if(comprobacion==0){
				calcularDescuentos(descuentoDebito,aerolineas,precioAerolineas, interesCredito, bitcoin, kilometraje);
				calcularDescuentos(descuentoDebito,latam,precioLatam, interesCredito, bitcoin, kilometraje);
				system("cls");
				break;
				}
				else{
					break;
				}

			case 4:
				comprobacion=comprobarIngreso(kilometraje,aerolineas,latam);
				if(comprobacion==0){
					printf ("\nKilomtros Ingresados: %fkm\n",kilometraje);
					mostrarResultados(precioAerolineas, aerolineas, "Aerolineas");
					mostrarResultados(precioLatam,latam, "Latam");
					diferencia=calcularDiferencia(aerolineas,latam);
					printf("\nLa diferencia de precio es: %f\n$",diferencia);
					system("pause");
					system("cls");
				break;
				}
				else{
					break;
				}
			case 5:
				kilometraje=7090;
				aerolineas=162965;
				latam=159339;
				calcularDescuentos(descuentoDebito,aerolineas,precioAerolineas, interesCredito, bitcoin, kilometraje);
				calcularDescuentos(descuentoDebito,latam,precioLatam, interesCredito, bitcoin, kilometraje);
				printf ("\nKilomtros Ingresados: %fkm\n",kilometraje);
				mostrarResultados(precioAerolineas, aerolineas, "Aerolineas");
				mostrarResultados(precioLatam,latam, "Latam");
				diferencia=calcularDiferencia(aerolineas,latam);
				printf("\nLa diferencia de precio es: %f\n$",diferencia);
				system("pause");
				system("cls");
				break;
			default:
				break;
			}
		}
	return 0;
}
