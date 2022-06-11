#include "biblioteca.h"

/// @brief Permite ingresar un entero en un rango de valores
///
/// @param texto
/// @param min
/// @param max
/// @return
int ingresarEntero (char texto[], int min, int max){ //Esta funcion te permite ingresar un entero e imprimir un mensaje
	int check;
	int numero;
	char aux[51];
	int x=0;
	printf("%s",texto);
	fflush(stdin);
	scanf("%[^\n]",aux);
	x=comprobarDigito(aux,texto);
	while(x==0){
		printf("\n");
		fflush(stdin);
		scanf("%s",aux);
		x=comprobarDigito(aux,texto);
	}
	numero=atoi(aux);
	check= checkInt(numero, min,max );
	while (check!=0){
		printf("Error! El numero ingresado no entra en las opciones permitidas!!\n%s",texto);
		fflush(stdin);
		scanf("%d",&numero);
		check= checkInt(numero, min,max );
	}
	return numero;
}
/// @brief Esta funcion comprueba que se ingrese numeros y no caracteres
///
/// @param sd
/// @param texto
/// @return
int comprobarDigito (char sd[],char texto[]){
	int x;
	for (int i=0;i<strlen(sd);i++){
		if (isdigit(sd[i])==0){
			printf("\nNo es un numero %s",texto);
			x=0;
			break;
		}
		else{
			x=1;
		}
	}
	return x;
}
/// @brief Permite ingresar un string con un limite de caracteres
///
/// @param texto
/// @param imp
/// @param minimo
void ingresarCadena (char texto[],char imp[], int minimo){ //Esta funcion te permite ingresar un string
	int numero;
	printf("%s",imp);
	fflush(stdin);
	scanf("%[^\n]",texto);
	numero = checkString (texto,minimo);
	while(numero!=0){
		printf("\nError el nombre ingresado supera el minimo de caracteres!!\n %s",imp);
		fflush(stdin);
		scanf("%[^\n]",texto);
		numero = checkString (texto,minimo);
	}
}

/// @brief Comprueba que el string no supere el maximo de caracteres permitidos
///
/// @param text
/// @param minimo
/// @return
int checkString(char text[], int minimo){ //Esta funcion comprueba que un string no exceda el maximo de caracteres
	int x;
	if (strlen(text)>minimo){
		x=1;// 1 significa que supera el limite
	}
	else {
		x=0; //0 significa que esta ok
	}

	return x;
}
/// @brief Compreba que el entero ingresado este en el rango pedido
///
/// @param numero
/// @param minimo
/// @param maximo
/// @return
int checkInt (int numero, int minimo, int maximo){ //Esta funcion comprueba que un int no supere el maximo ni el minimo permitido
	int x;
	if (numero<maximo && numero>minimo){
		x=0; //0 esta ok
	}
	else{
		x=1; //1 esta mal
	}

	return x;
}
/// @brief Permite ingresar un caracter
///
/// @param text
/// @return
char ingresarCaracter (char text[]){ //Esta funcion te permite ingresar un caracter
	char x;
	printf("%s",text);
	fflush(stdin);
	scanf("%c",&x);
	return x;
}

/// @brief Comprueba que el caracter sea una de las 2 opciones dadas
///
/// @param letra
/// @param opcionUno
/// @param opcionDos
/// @return
int checkCaracter(char letra, char opcionUno, char opcionDos){ //Esta funcion permite comprobar un caracter con las posibilidades que se da
	int x;
	letra=tolower(letra);
	opcionUno=tolower(opcionUno);
	opcionDos=tolower(opcionDos);
	if (letra==opcionUno || letra==opcionDos){
		x=0; // 0 esta ok
	}
	else{
		x=1; //1 no coincide con las opciones dadas
	}
	return x;
}
/// @brief Permite ingresar un caracter y verificar que sea una de las 2 opciones dadas
///
/// @param texto
/// @param opcionUno
/// @param opcionDos
/// @return
char ingresarCheckCaracter(char texto[], char opcionUno, char opcionDos){
	char x;
	int check;
	x=ingresarCaracter(texto);
	check= checkCaracter(x,opcionUno,opcionDos);
		while (check==1){
			printf("Error por favor ingrese las opciones correctas!! (%c/%c) %s", opcionUno,opcionDos,texto);
			fflush(stdin);
			scanf("%c",&x);
			check= checkCaracter(x,opcionUno,opcionDos);
		}
	return x;
}

float ingresarFlotante(char texto[],float minimo, float maximo){
	int check;
	float numero;
	char aux[51];
	int x=0;
	printf("%s",texto);
	fflush(stdin);
	scanf("%[^\n]",aux);
	x=comprobarDigito(aux,texto);
	while(x==0){
		printf("\n");
		fflush(stdin);
		scanf("%s",aux);
		x=comprobarDigito(aux,texto);
	}
	numero=atoi(aux);
	check= checkInt(numero, minimo,maximo );
	while (check!=0){
		printf("Error! El numero ingresado no entra en las opciones permitidas!!\n%s",texto);
		fflush(stdin);
		scanf("%f",&numero);
		check= checkInt(numero, minimo,maximo );
	}
	return numero;
}

int checkFloat (float numero, float minimo, float maximo){ //Esta funcion comprueba que un float no supere el maximo ni el minimo permitido
	int x;
	if (numero<maximo && numero>minimo){
		x=0; //0 esta ok
	}
	else{
		x=1; //1 esta mal
	}

	return x;
}
