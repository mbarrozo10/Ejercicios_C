/*
 =1. (4 puntos) Crear un array de caracteres (con vocales y consonantes) en memoria dinámica y una función que reciba dicho array.
 La función deberá ajustar el tamaño del array a la cantidad consonantes que haya en el mismo quedándose únicamente con los elementos
  que cumplan con dicha característica. Ej: (perro)->(prr)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void funcion (char* cadena, char* tmpCad);
void load(char* archivo);
void save(char* archivo);
int main() {
	setbuf(stdout, NULL);
char* array=(char*)malloc(sizeof(array));
char* tmpArray=(char*)malloc(sizeof(array));

strcpy(array,"pepefasff");
funcion(array, tmpArray);

strcpy(array,tmpArray);




printf("%s\n", array);

save(array);
load(tmpArray);

return 0;
}
// punto 1
void funcion (char* array, char* tmpArray){
	int a = strlen(array);
	int i;
	int j=0;
	for (i = 0; i < a; i++)
	{
	    if (array[i] != 'a' && array[i] != 'e' && array[i] != 'i' && array[i] != 'o' && array[i] != 'u')
	    {
	    	tmpArray[j] = array[i];
	        j++;
	    }
	}

	tmpArray[j] = '\0';

	free(array);
}

//punto 2
//
/*  Todas la variables que se declaran de manera convencioanl se guardan en el Stack o pila, para poder guardarlas en el heap o Monton
 * 	para esto se usa malloc, que te devuelve un puntero a espacio de memoria dinamica reservado, una vez que se termino de usar esta
 * 	variable, para liberrar el espacio se usa la funcion Free.
*/

//punto 3

void save(char* archivo){
	FILE* txt=fopen("asd.bin","wb");
	if(txt==NULL){
		printf("El archivo no se pudo abrir\n");
	}
				fwrite(archivo,sizeof(archivo),1,txt);
	fclose(txt);
}

void load(char* archivo){
	FILE* pFile= fopen("asd.bin","rb");
	char* aux=(char*)malloc(sizeof(archivo));
		if (pFile!=NULL){
				if(fread(aux,sizeof(archivo),1,pFile)){
					printf("\n el dato cargado es %s",aux);
				}
				else{
					printf("error");
				}
			}
		fclose(pFile);
}

//https://onlinegdb.com/gv__FmjlU
