#include "ArrayPassenger.h"
#define TRUE 1
#define FALSE 0
#define TAM 2000


static int idIncremental=0;
static int GetId();
static int GetId()
{
    return idIncremental++;
}
/// @brief Inicializa el vector de la estructura
///
/// @param list
/// @param len
/// @return
int initPassenger(Passenger list[],int len){
	for (int i=0;i<=len;i++){
		list[i].isEmpty=TRUE;
	}
	return 0;
}

/// @brief Agrega los valores a la posicion id del vector de estructuras
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flycode
/// @param statusFlight
/// @return
int addPassenger(Passenger list[],int len, int id,char name[],char lastName[],float price, int typePassenger, char flycode[],int statusFlight){
	list[id].id=id;
	strcpy(list[id].name,name);
	strcpy(list[id].lastName,lastName);
	list[id].price=price;
	list[id].typePassenger=typePassenger;
	strcpy(list[id].flycode,flycode);
	list[id].isEmpty=FALSE;
	list[id].statusFlight=statusFlight;
	return -1;
}

/// @brief Busca un pasajero por ID
///
/// @param list
/// @param len
/// @param id
/// @return
int findPassengerById(Passenger list[],int len, int id){
	int retorno;
	for(int i=0;i<len;i++){
	if (list[i].id==id && list[id].isEmpty==FALSE){
		retorno=i;
		break;
		}
	else{
		retorno=-1;
	}
	}
	return retorno;
}

/// @brief Remueve un pasajero, pidiendo el id
///
/// @param list
/// @param len
/// @param id
/// @return
int removePassenger(Passenger list[],int len, int id){
	int busqueda;
	char seleccion;
	int retorno=0;
	busqueda=findPassengerById(list,len,id);
	if(busqueda!=-1){
		printf("\nEl nombre es %s, esta seguro que quiere borrar?  (S/N)",list[busqueda].name);
		seleccion=ingresarCheckCaracter("\nSu opcion:",'s','n');
		if (seleccion=='s'){
			list[busqueda].isEmpty=TRUE;
			retorno=1;
		}
	}
	else{
	retorno=-1;
	}
return retorno;
}

/// @brief Ordena el vector alfabeticamente por el apellido y dependiendo del orden que se desea (ascendente y descendente)
///
/// @param list
/// @param len
/// @param order
/// @return
int sortPassenger(Passenger list[],int len, int order){
	int x=0;
	Passenger aux;
	if (order==0){
		for (int i=0;i<=len-1;i++){
			for(int j=i+1;j<=len;j++){
				if ((strcmpi(list[i].lastName,list[j].lastName)>0)&&(list[i].isEmpty==FALSE&&list[j].isEmpty==FALSE)){
					aux=list[i];
					list[i]=list[j];
					list[j]=aux;
				}
				else if (strcmpi(list[i].lastName,list[j].lastName)==0&&(list[i].isEmpty==FALSE&&list[j].isEmpty==FALSE)){
					if (list[i].typePassenger>list[j].typePassenger){
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
		}
		x=1;
	}else{
		for (int i=0;i<=len-1;i++){
					for(int j=i+1;j<=len;j++){
						if (strcmpi(list[i].lastName,list[j].lastName)<0&&(list[i].isEmpty==FALSE&&list[j].isEmpty==FALSE)){
							aux=list[i];
							list[i]=list[j];
							list[j]=aux;
						}
						else if (strcmpi(list[i].lastName,list[j].lastName)==0&&(list[i].isEmpty==FALSE&&list[j].isEmpty==FALSE)){
							if (list[i].typePassenger<list[j].typePassenger){
								aux=list[i];
								list[i]=list[j];
								list[j]=aux;
							}
						}
					}
				}
		x=1;
	}
	return x;
}

/// @brief Imprime el vector de la estructura
///
/// @param list
/// @param len
/// @return
int printPassenger(Passenger list[], int len, typePassenger type[] ){
	int x=0;
	for (int i=0;i<=len;i++){
		for (int j=0;j<=4;j++){
			if (list[i].isEmpty==FALSE&& list[i].typePassenger==type[j].id){
				if(list[i].statusFlight==1){
					printf("\n |ID|\tNAME|\tLASTNAME|\tPRICE|\tFLYCODE|\tTYPE PASSENGER|\tSTATUS FLIGHT|"
							"\n |%d|\t%s|\t%s|\t%f|\t%s|\t%s|\t%s|",list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,type[j].descripcion,"ACTIVO");
					x=1;
					break;
				}
				else{
					printf("\n |ID|\tNAME|\tLASTNAME|\tPRICE|\tFLYCODE|\tTYPE PASSENGER|\tSTATUS FLIGHT|"
							"\n |%d|\t%s|\t%s|\t%f|\t%s|\t%s|\t%s|",list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,type[j].descripcion,"INACTIVO");
					x=1;
				}
			}
		}
	}
	return x;
}

/// @brief Ordena el vector por el codigo de vuelo, dependiendo del orden ascendente y descendente
///
/// @param list
/// @param len
/// @param order
/// @return
int sortPassengerByCode(Passenger list[], int len, int order,typePassenger type []){
	int x=0;
		Passenger aux;
		if (order==0&& len>1){
			for (int i=0;i<=len-1;i++){
				for(int j=i+1;j<=len;j++){
					if ((strcmpi(list[i].flycode,list[j].flycode)>0)&&(list[i].isEmpty==FALSE&&list[j].isEmpty==FALSE)){
						aux=list[i];
						list[i]=list[j];
						list[j]=aux;
					}
				}
			}
			x=1;
		}else if(order==1 && len>1){
			for (int i=0;i<=len-1;i++){
						for(int j=i+1;j<=len;j++){
							if (strcmpi(list[i].flycode,list[j].flycode)<0&&(list[i].isEmpty==FALSE&&list[j].isEmpty==FALSE)){
								aux=list[i];
								list[i]=list[j];
								list[j]=aux;
							}
						}
					}
			x=1;
		}
		else{
			x=-1;
		}
		for (int i=0;i<len;i++){
			for (int j=0;j<4;j++){
				if (list[i].isEmpty==FALSE&&list[i].statusFlight==1&&list[i].typePassenger==type[j].id){
					printf("\n |ID|\tNAME|\tLASTNAME|\tPRICE|\tFLYCODE|\tTYPE PASSENGER|\tSTATUS FLIGHT|"
							"\n |%d|\t%s|\t%s|\t%f|\t%s|\t%s|\t%d|",list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,type[j].descripcion,list[i].statusFlight);
					break;
				}
			}
		}
		return x;
}

/// @brief Pide los datos para pasarselos al alta
///
/// @param list
/// @param tam
void ingresarAlta(Passenger list[],int tam){
	char eleccion='s';
	char nombre[51];
	char apellido[51];
	float precio;
	int tipo;
	char codigo[10];
	int status;
	int comprobacion;
	for (int i=0;i<=tam;i++){
		if (list[i].isEmpty==TRUE){
			ingresarCadenaCheck(nombre,"\nIngrese el nombre del pasajero: ",51);
			ingresarCadenaCheck(apellido,"\nIngrese el apellido del pasajero: ",51);
			precio=ingresarEntero("\nIngresar el precio del boleto: ",0,30000000);
			tipo= ingresarEntero("\nIngrese el tipo de pasajero: 1-Economio/ 2-Ejecutiva/ 3-Premium", 0,4);
			pedirCodigoAlfa(codigo);
			status=ingresarEntero("\nIngrese el estado del vuelo: (1-ACTIVO / 2-INACTIVO",0,3);
			comprobacion=addPassenger(list,tam,GetId(),nombre,apellido,precio,tipo,codigo,status);
			if (comprobacion==-1){
				printf("\nSe cargo todo correctamente!!\n");
				eleccion=ingresarCheckCaracter("\nQuiere ingresar otro pasajero? (s/n) ",'s','n');
				if (eleccion=='n'){
				break;
				}
			}
		}
	}
}
/// @brief Modifica un pasajero pidiendo el id
///
/// @param list
/// @param tam
void modificarPasajero (Passenger list[], int tam,typePassenger type[]){
	int x;
	int id;
	int eleccion;
	char nombre[51];
	char apellido[51];
	float precio;
	int tipo;
	char codigo[10];
	if(comprobarAlta(list)){
		printPassenger(list,TAM,type);
		id=ingresarEntero("\nIngrese el Id del pasajero que busca: ",-1,2001);
		x=findPassengerById(list,tam,id);
		while (x==-1){
			id=ingresarEntero("\nIngrese el Id del pasajero que busca: ",-1,2001);
			x=findPassengerById(list,tam,id);
		}
		eleccion=ingresarEntero("\nIngrese la opcion que desea cambiar:\n1-Nombre\n2-Apellido\n3-Precio\n4-Tipo de pasajero\n5-Codigo de vuelo\n6-Salir",0,7);
		switch (eleccion){
			case 1:
				ingresarCadenaCheck(list[x].name,"\nIngrese el nuevo nombre : ",51);
				strcpy(list[x].lastName,nombre);
				break;
			case 2:
				ingresarCadenaCheck(list[x].lastName,"\nIngrese el nuevo Apellido : ",51);
				strcpy(list[x].lastName,apellido);
				break;
			case 3:
				precio=ingresarEntero("\nIngrese el nuevo precio: ",0,200000000);
				list[x].price=precio;
				break;
			case 4:
				tipo=ingresarEntero("\nIngrese en nuevo tipo de pasajero: 1-Economio/ 2-Ejecutiva/ 3-Premium \nSu ingreso: ",0,4);
				list[x].typePassenger=tipo;
				break;
			case 5:
				pedirCodigoAlfa(codigo);
				strcpy(list[x].flycode,codigo);
				break;
			case 6:
				break;
				}
	}
	else{
		printf("\nTodava no se ingreso ningun alta");
	}
}
/// @brief Pide el id del pasajero a borrar y pide una confirmacion
///
/// @param list
void remover(Passenger list[],typePassenger type[]){
	int id;
	int baja;
	if(comprobarAlta(list)){
		printPassenger(list,TAM,type);
		id=ingresarEntero("\nIngrese el id que quiere borrar",-1,TAM);
		baja= removePassenger(list, TAM, id);
		if (baja==1){
			printf("Se borro exitosamente!!");
		}
	}
	else{
		printf("\nTodava no se ingreso ningun alta");
	}
}
/// @brief Comprueba que haya al menos 1 pasajero cargado
///
/// @param list
/// @return
int comprobarAlta(Passenger list[]){
	int x=0;
	for(int i=0;i<=TAM;i++){
		if(list[i].isEmpty==FALSE){
			x=1;
			break;
		}
	}
	return x;
}
/// @brief Submenu que para elegir el tipo de listado que se desea
///
/// @param list
void listar (Passenger list[],typePassenger type[]){
	int index;
	int total=0;
	int cantidad=0;
	float promedio;
	int* pTotal=&total;
	float* pPromedio=&promedio;
	int* pCantidad=&cantidad;
	int subindex;
	int comprobacion;
	int print;
	if (comprobarAlta(list)){
		do{
			index=ingresarEntero("\n1-Listar pasajeros ordenados alfabeticamente.\n2-Total y promedio de los pasajes y cuantos superan ese promedio"
								"\n3-Listar pasajeros ordenados por codigo de vuelo\n4-Salir\nSu opcion: ",0,5);
			switch(index){
			case 1:
				subindex=ingresarEntero("\nIngrese el orden en que quiera listar (0-DOWN/1-UP) ",-1,2);
				comprobacion= sortPassenger(list,TAM,subindex);
				if(comprobacion==1){
					print=printPassenger(list,TAM,type);
					if(print==1){
						printf("\nTodo salio ok");
					}
				}
				else{
					printf("\nAlgo ha salido mal!");
				}
				break;
			case 2:
				calcularPromedio(list,pTotal,pCantidad,pPromedio);
				printf("\nEl total es de : %d\nEl promedio es de: %f\nLa cantidad que superan el promedio es: %d",total,promedio,cantidad);
				break;
			case 3:
				subindex=ingresarEntero("\nIngrese el orden en que quiera listar (0-DOWN/1-UP) ",-1,2);
				comprobacion= sortPassengerByCode(list,TAM,subindex,type);
				if(comprobacion==1){
						printf("\nTodo salio ok");
				}
				else{
					printf("\nAlgo ha salido mal!");
				}
				break;
			case 4:
				break;
			}
		}while (index!=4);
	}
	else{
		printf("\nTodava no se ingreso ningun alta");

	}
}
/// @brief Calcula el promedio, la suma total y la cantidad de pasajeros que superan ese promedio
///
/// @param list
/// @param pTotal
/// @param pCanti
/// @param pPromedio
void calcularPromedio (Passenger list[],int* pTotal, int* pCanti, float* pPromedio){
	int cont=0;
	for(int i=0;i<=TAM;i++){
		if (list[i].isEmpty==FALSE){
			*pTotal+=list[i].price;
			cont++;
		}
	}
	*pPromedio= (*pTotal)/cont;
	for(int i=0;i<=TAM;i++){
			if (list[i].price>*pPromedio&&list[i].isEmpty==FALSE){
				(*pCanti)+=1;
			}
		}
}
