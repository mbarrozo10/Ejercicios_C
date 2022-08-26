/* */
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

float ingresarNumeros(char text[]){ //se usa para ingresar numeros
	float numero;
	printf("Ingrese el %s: ",text);
	scanf("%f",&numero);
	while (numero<0){
		printf("Error, el %s no puede ser menor a 0, ingrese nuevamente: ",text);
		scanf("%f",&numero);
	}
	return numero;
}

int subMenu (float aerolineas, float latam){ //se usa para el submenu de la eleccion 2
	int numero, seleccion;
	printf("\n1-Precio vuelo Aerolineas (Se ingreso: %f$)\n2-Precio vuelo Latam (Se ingreso %f$)\nElija una opcion: ", aerolineas, latam);
	scanf("%d",&seleccion);
		while (seleccion!=1 && seleccion!=2){
			printf("Error, por favor ingrese opcion correcta:\n1-Precio vueloAerolineas (Se ingreso: %f$)\n2- Precio vuelo Latam (Se ingreso %f$)\nElija una opcion: ", aerolineas, latam);
			scanf("%d",&seleccion);
		}
		if (seleccion==1){
			numero=1;
		}
		else {
			numero=2;
		}

	return numero;
}

void calcularDescuentos(float descuento, float precio, float vector[4], float interes, float bit, float km){ //se usa para calcular todas las operaciones

	for (int x=0;x<4;x++){
		switch (x){
		case 0:
			vector[x]=precio*descuento;
			break;
		case 1:
			vector[x]=precio*interes;
			break;
		case 2:
			vector[x]=precio/bit;
			break;
		default:
			vector[x]=precio/km;
			break;
		}
	}
}
void mostrarResultados (float vector[], float precio, char text[]){ //se usa para mostrar los resultados
	printf("\n%s: %f\na)Precio con tarjeta de debito: %f$\n",text,precio ,vector[0]);
	printf("b)Precio con tarjeta de credito: %f$\n",vector[1]);
	printf("c)Precio en bitcoin: %f$\n",vector[2]);
	printf("b)Precio por kilometro: %f$\n",vector[3]);
}

float calcularDiferencia (float primerNumero, float segundoNumero){ //se usa para calcular la diferencia
	float resultado;
	if (primerNumero<=segundoNumero){
		resultado=segundoNumero-primerNumero;
	}
	else if (segundoNumero<=primerNumero){
		resultado=primerNumero-segundoNumero;
	}
	return resultado;
}

int comprobarIngreso (float kilometraje, float aerolineas, float latam){ // se usa para comprobar que haya datos cargados antes de calcular y mostrar
	int numero;
	while (kilometraje==0&& aerolineas==0&& latam==0){
			printf("Por favor, ingrese primero kilometraje y los precios\n");
			numero=1;
			return numero;
					}
	numero=0;
	return numero;

}
