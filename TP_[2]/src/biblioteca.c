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
	printf("%s",texto);
	fflush(stdin);
	scanf("%d",&numero);
		check= checkInt(numero, min,max );
		while (check!=0){
			printf("Error! El numero ingresado no entra en las opciones permitidas!!\n%s",texto);
			fflush(stdin);
			scanf("%d",&numero);
			check= checkInt(numero, min,max );
		}
	return numero;
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
