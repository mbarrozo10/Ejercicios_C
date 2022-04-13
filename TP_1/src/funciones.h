
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <conio.h>
#include "ctype.h"

float ingresarNumeros (char text[]);
int subMenu(float aerolineas,float latam );
void calcularDescuentos(float descuento, float precio, float vector[4], float interes, float bit, float km);
void mostrarResultados (float vector[], float precio, char text[]);
float calcularDiferencia (float primerNumero, float segundoNumero);
int comprobarIngreso (float kilometraje, float aerolineas, float latam);
#endif /* FUNCIONES_H_ */
