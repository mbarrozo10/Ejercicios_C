/******************************************************************************

Parcial 1 Matias Barrozo 1F

*******************************************************************************/
#include <stdio.h>
#define LEN 4

float calcularDescuento(float precio, float descuento);
void invertirCadena(char texto[],char textoInvertido[]);
int main()
{
	setbuf(stdout, NULL);
    float precio, descuento, total;
    char texto[LEN]="HOLA";
    char textoDos[LEN];
    precio=1000;
    descuento=0.90;
    total=calcularDescuento(precio, descuento);
    printf("%f",total);
    invertirCadena(texto, textoDos);
    printf("\n%s \n%s",texto,textoDos);
    return 0;
}

//Punto 1
float calcularDescuento(float precio, float descuento){
    float index;
    index=precio*descuento;
    return index;
}

//punto 2
void invertirCadena(char texto[],char textoInvertido[]){
	int aux=LEN;
	for(int i=0;i<=LEN;i++){
		textoInvertido[aux]=texto[i];
		aux--;
		if (aux==0){
			break;
		}
	}
}
