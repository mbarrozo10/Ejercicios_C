#include "estruc.h"
#define OCUPADO 1
#define LIBRE 0

static int generarId();
static int idIncremental=0;
static int generarId(){
	idIncremental++;
	return idIncremental;
}
/// @brief Esta funcion hace el alta de los albumes

///
/// @param list
/// @param len
/// @param tipoAlbum
/// @param artista
/// @param tipo
/// @param genero
void altaAlbum(eAlbum list[],int len,eTipoAlbum tipoAlbum[],eArtista artista[],eTipoArtista tipo[],eGenero genero[]){
	int index;
	index= buscarLibre(list,len);
	list[index].libre=OCUPADO;
	ingresarCadena(list[index].titulo,"\nIngrese el titulo del album: ",51); //Se usa una funcion para ingresar la cadena, se le envia el texto para imprimir y el maximo de caracteres
	list[index].importe=ingresarFlotante("\nIngrese el precio del album: ",0,1300000000);//Se usa una fucion para ingresar enteros, se le envia el texto para imprimir y el minimo y maximo del valor
	list[index].publicacion.dia= ingresarEntero("\nIngrese el dia de salida:",0,32);
	list[index].publicacion.mes= ingresarEntero("\nIngrese el mes de salida:",0,13);
	list[index].publicacion.anio= ingresarEntero("\nIngrese el anio de salida:",1947,2023);
	informarArtista (artista, len);
	list[index].idArtista=ingresarEntero("\nSu opcion: ",99,103);
	informarGenero(genero, len);
	list[index].idGenero=ingresarEntero("\nSu opcion: ",999,1003);
	informarTipo(tipo, len);
	list[index].idTipo=ingresarEntero("\nSu opcion: ",9,12);
	informarTiposAlbum(tipoAlbum, len);
	list[index].idTipoAlbum=ingresarEntero("\nSu opcion: ",0,4);
	list[index].id=generarId();
}

/// @brief inicializa el campo "libre"
///
/// @param list
/// @param len
void inicializar(eAlbum list[],int len){
	int i;
	for (i=0;i<len;i++){
		list[i].libre=LIBRE;
	}
}
/// @brief Esta funcion permite modificar los distintos campos
///
/// @param list
/// @param len
void modificarAlbum(eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len){
	int id;
	int x;
	int seleccion;
	int comprobacion;
	comprobacion=comprobarAlta(list,len);
	if(comprobacion==1){
		informarNombreAlbum(list,artista,tipo,tipoAlbum,genero, len);
		id=ingresarEntero("\nIngrese el id que quiere modificar: ",-1,len);
		x=buscarId(list,len,id);
		while (x==-1){
			id=ingresarEntero("\nError, no se encontro ningun id, inrege nuevamente: ",-1,len);
			x=buscarId(list,len,id);
		}
		printf("Ingrese el valor que quiera cambiar:\n1-Titulo\n2-Fecha de publicacion\n3-Importe\n4-Tipo de album\n ");
		seleccion=ingresarEntero("Su opcion: ",0,5);
		switch (seleccion){
		case 1:
			ingresarCadena(list[x].titulo, "\nIngrese el nuevo titulo: ",51);
			printf("\nSe cambio el nombre exitosamente!!!");
			break;
		case 2:
			list[x].publicacion.dia= ingresarEntero("\nIngrese el nuevo dia de salida:",0,32);
			list[x].publicacion.mes= ingresarEntero("\nIngrese el nuevo mes de salida:",0,13);
			list[x].publicacion.anio= ingresarEntero("\nIngrese el nuevo anio de salida:",1948,2022);
			printf("\nSe cambio el nombre exitosamente!!!");
			break;
		case 3:
			list[x].importe=ingresarFlotante("\nIngrese el precio del album",0,1000000);
			printf("\nSe cambio el nombre exitosamente!!!");
			break;
		case 4:
			list[x].idTipoAlbum=ingresarEntero("\nIngrese el tipo de album:\n1-Vinilo\n2-Cinta\n3-CD",0,4);
			printf("\nSe cambio el nombre exitosamente!!!");
			break;
		default:
			printf("\nIngrese una opcion correcta");
			break;
				}
			}
	else{
		printf("\nNo hay ningun album al que modificar");
	}
}
/// @brief Esta funcion busca un indice correspondiente al ID que se le pase
///
/// @param list
/// @param len
/// @param id
/// @return
int buscarId (eAlbum list[], int len, int id){
	int x;
	for(int i=0;i<len;i++){
		if (list[i].id==id&& list[i].libre==OCUPADO){
			x=i;
			break;
		}
		else {
			x=-1;
		}
	}
	return x;
}
/// @brief Esta funcion permite dar de baja logica a un album, se le cambia el estado de OCUPADO a LIBRE
///
/// @param list
/// @param len
void bajaAlbum (eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len){
	int id;
	char eleccion;
	int index;
	int comprobacion;
	comprobacion=comprobarAlta(list,len);
	if(comprobacion==1){
		informarNombreAlbum(list,artista,tipo,tipoAlbum,genero, len);
		id = ingresarEntero("\nIngrese el id que quiera dar de baja: ",-1,len);
		index=buscarId(list,len,id);
		eleccion= ingresarCheckCaracter("Esta seguro que quiere borrar ese id? (s/n)",'s','n');
		if (eleccion=='s'){
			list[index].libre=LIBRE;
		}
	}
	else{
		printf("\nNo hay ningun album al que dar de baja ");
	}
}
/// @brief Esta funcion comprueba que haya aunque sea 1 album dado de alta
///
/// @param list
/// @param len
/// @return
int comprobarAlta (eAlbum list [],int len){
	int x;
	int i;
	for(i=0;i<len;i++){
		if(list[i].libre==OCUPADO){
			x=1;
			break;
		}
		else{
			x=0;
		}
	}

	return x;
}
/// @brief Esta funcion es el submenu de la opcion 4
///
/// @param list
/// @param len
void subMenu(eAlbum list[],int len,eGenero gen[],eTipoAlbum tipo[]){
	int x;
	float totalCant [2]={0,0}; //indice 0 guarda la suma total, indice 1 guarda la cantidad que supera el promedio
	float prom;
	int cantidadFechas;
	int comprobacion;
	comprobacion=comprobarAlta(list, len);
	if (comprobacion==1){
		x=ingresarEntero("\n1-Total, promedio de los importes y cuantos album superan\n2-Cantidad de albumes anterior a 1/1/2000\n3-Informar la cantidad de álbumes de un tipo de álbum determinado y de un género determinado\n ",0,4);
		switch(x){
		case 1:
			prom= promedio(list, len, totalCant);
			informarA(totalCant,prom);
			break;
		case 2:
			cantidadFechas=fechas(list,len);
			informarB(cantidadFechas);
			break;
		case 3:
			informarTipoGenero( list, gen,tipo, len);
			break;
		default:
			printf("Ingrese A o B");
			break;
		}
	}
	else{
		printf("\nNo hay ningun album al que informar ");
		}
}
/// @brief Esta funcion permite calcular el promedio
///
/// @param list
/// @param len
/// @param suma
/// @return
float promedio(eAlbum list[],int len, float suma[]){
	float x;
	int cant=0;
	int i;
	for (i=0;i<len;i++){
			if (list[i].libre==OCUPADO){
				suma[0]+=list[i].importe;
				cant ++;
			}
	}
	x=suma[0]/cant;
	for (i=0;i<len;i++){
		if (list[i].importe>x && list[i].libre==OCUPADO){
			suma[1]++;
		}
	}

	return x;
}
/// @brief Esta funcion permite encontrar la cantidad de albumes de determinado anio
///
/// @param list
/// @param len
/// @return
int fechas(eAlbum list[],int len){
	int x=0, anio;
	int i;
	for (i=0;i<len;i++){
		if (list[i].libre==OCUPADO){
			anio= checkInt(list[i].publicacion.anio,1947, 2000);
			if (anio==0){
				x++;
			}
		}
	}
	return x;
}
/// @brief Esta funcion es el submenu de la opcion 5
///
/// @param list
/// @param genero
/// @param artista
/// @param tipo
/// @param tipoAlbum
/// @param len
void subMenuCinco(eAlbum list[],eGenero genero[], eArtista artista[],eTipoArtista tipo[],eTipoAlbum tipoAlbum[], int len){
	int eleccion;
	int comprobacion;
	comprobacion=comprobarAlta(list,len);
	if (comprobacion==1){
		eleccion= ingresarEntero("\n1-Todos los generos\n2-Todos los tipos de artistas musicales\n3-Todos los artistas\n4-Todos los albumes\n"
								"5-Album listados segun el precio\n6-Albumes anterior a 1/1/2000\n7-Albumes que superan el promedio de precio\n"
								"8-Album de cada artista\n9-Todos los albumes de un determinado anio\n10-El album o albumes mas caros\n11-Todos los tipos de album"
								"\n12-Todos los albumes que no son de vinilo\n13-Todos los albumes de vinilo de un artista determinado\n14-listado de todos los álbumes de solistas de un año determinado.",0,15);
		switch(eleccion){
		case 1:
			informarGenero(genero, len);
			break;
		case 2:
			informarTipo(tipo, len);
			break;
		case 3:
			informarArtista(artista,len);
			break;
		case 4:
			informarNombreAlbum(list,artista,tipo,tipoAlbum,genero, len);
			break;
		case 5:
			informarNombreOrder(list,artista,tipo,tipoAlbum,genero, len);
			break;
		case 6:
			informarFechas(list,len,2001);
			break;
		case 7:
			informarPromedio(list,len);
			break;
		case 8:
			informarAlbumArtista(list,artista,len);
			break;
		case 9:
			informarFechaExacta(list,len);
			break;
		case 10:
			informarMayor(list,len);
			break;
		case 11:
			informarTiposAlbum(tipoAlbum,len);
			break;
		case 12:
			informarAlbumNoVinilo(list,len);
			break;
		case 13:
			informarAlbumViniloArtista(list, artista,len);
			break;
		case 14:
			informarFechaExactaSolista(list,genero,artista,tipoAlbum,tipo,len);
			break;
		default:
			printf("Ingrese una opcion del 1 al 13");
			break;
		}
	}
	else{
			printf("\nNo hay ningun album al que informar ");
			}
}
/// @brief Esta funcion imprime los generos
///
/// @param list
/// @param len
void informarGenero (eGenero list[],int len){
	int i;
	printf("\nLos generos son:\nID|DESCRIPCION");
	for(i=0;i<len;i++){
		if(list[i].id>999&&list[i].id<1003){
		printf("\n%d|%10s",list[i].id,list[i].descripcion);
		}
	}
}
/// @brief Esta funcion imprime los tipos de artista
///
/// @param list
/// @param len
void informarTipo (eTipoArtista list[],int len){
	int i;
	printf("\nLos tipos de artista son:\nID|DESCRIPCION");
	for(i=0;i<2;i++){
		if (list[i].id==10 ||list[i].id==11){
		printf("\n%d|%10s",list[i].id,list[i].descripcion);
		}
	}
}
/// @brief Esta funcion imprime los artista
///
/// @param list
/// @param len
void informarArtista (eArtista list[],int len){
	int i;
	printf("\nLos Artistas son:\n ID|NOMBRE\n");
	for(i=0;i<len;i++){
		if(list[i].id>99 && list[i].id<103){
		printf("%d|%10s\n",list[i].id,list[i].nombre);
		}
	}
}
/// @brief Esta funcion imprime todos los albumes
///
/// @param list
/// @param len
void informarNombreAlbum (eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len){
	int i,j,k,m,n;
	printf("\nID|%10s|DIA|MES|ANIO|IMPORTE","NOMBRE");
	for( i = 0; i < len; i++)//recorre albumes
	    {
	        if(list[i].libre == OCUPADO)
	        {
	            for( j = 0; j < 16; j++)
	            {
	                for( k = 0; k < 8; k++)
	                {
	                    for( n = 0; n < 3; n++)
	                    {
	                        for( m = 0; m < 2; m++)
	                        {
	                            if(list[i].idArtista == artista[j].id
	                                && list[i].idGenero == genero[k].id
	                                && list[i].idTipoAlbum == tipoAlbum[n].id
	                                && list[i].idTipo == tipo[m].id)
	                            {
	                        		printf("\n%2d|%10s|%3d|%3d|%d|%5.2f|%s|%s|%s|%s",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe,
	                        															artista[j].nombre,tipo[m].descripcion,genero[k].descripcion,tipoAlbum[n].datos);
	                            }
	                        }
	                    }
	                }
	            }
	        }
	    }
}


/// @brief Esta funcion informa los nombres de los albumes de forma decendiente segun el precio y ascendente segun el nombre
///
/// @param list
/// @param len
void informarNombreOrder (eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len){
	eAlbum auxiliar;
	int i;
	int x;
	for(i=0;i<len;i++){
		for  (x=i+1;x<len;x++){
			if (list[i].importe<list[x].importe&& list[i].libre==OCUPADO){
				auxiliar=list[i];
				list[i]=list[x];
				list[x]=auxiliar;
			}
			else if(list[i].importe==list[x].importe&& list[i].libre==OCUPADO){
				if(strcmpi(list[i].titulo,list[x].titulo)<0){
					auxiliar=list[i];
					list[i]=list[x];
					list[x]=auxiliar;
				}
			}
		}
	}
	informarNombreAlbum(list,artista,tipo,tipoAlbum,genero, len);

}
/// @brief Esta funcion imprime los nombres de los albumes anteriores a 1/1/2000
///
/// @param list
/// @param len
/// @param anio
void informarFechas(eAlbum list[],int len, int anio){
	int check;
	int i;
	printf("\nLos albumes anteriores a 1/1/2000 son:");
	for (i=0;i<len;i++){
		if (list[i].libre==OCUPADO){
			check= checkInt(list[i].publicacion.anio,1947, anio);
			if (check==0){
				printf("\n%2d|%10s|%3d|%3d|%d|%5.2f",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe);
			}
		}
	}
}
/// @brief Esta funcion imprime los nombres que superan el promedio del precio
///
/// @param list
/// @param len
void informarPromedio(eAlbum list[], int len){
	float prom;
	int i;
	float vector[2]={0,0};
	prom= promedio(list,len,vector);
	printf("\nLos albumes que superan el promedio (%f) son: ",prom);
	for (i=0;i<len;i++){
		if(list[i].importe>prom&&list[i].libre==OCUPADO){
			printf("\n%2d|%10s|%3d|%3d|%d|%5.2f",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe);
		}
	}
}
/// @brief Esta funcion imprime los albumes correspondientes a cada artista
///
/// @param list
/// @param art
/// @param len
void informarAlbumArtista(eAlbum list[],eArtista art[],int len){
	int i;
	for ( i=0;i<3;i++){
	printf("\nEl artista %s tiene los siguientes albumes: ",art[i].nombre);
		for (int x=0;x<len;x++){
			if (list[x].idArtista==art[i].id && list[x].libre==OCUPADO){
				printf("\n%2d|%10s|%3d|%3d|%d|%5.2f",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe);
			}
		}
	}
}
/// @brief Esta funcion informa los albumes de un anio exacto
///
/// @param list
/// @param len
void informarFechaExacta (eAlbum list[],int len){
	int eleccion;
	int i;
	eleccion=ingresarEntero("\nIngrese el anio: ",1947,2023);
	printf("Los albumes del anio %d son:",eleccion );
	for (i=0;i<len;i++){
		if (list[i].publicacion.anio==eleccion){
			printf("\n%2d|%10s|%3d|%3d|%d|%5.2f",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe);
		}
	}

}
/// @brief Esta funcion busca e imprime el album con mayo precio
///
/// @param list
/// @param len
void informarMayor(eAlbum list[],int len){
	float mayor=0;
	int bandera=0;
	int i;
	for (i=0;i<len;i++){
		if ((list[i].libre==OCUPADO && list[i].importe>mayor)||bandera==0){
			mayor=list[i].importe;
			bandera=1;
		}
	}
	printf("\nLos albumes de mayor precio son: ");
	for(i=0;i<len;i++){
		if (list[i].importe==mayor&& list[i].libre==OCUPADO){
			printf("\n%2d|%10s|%3d|%3d|%d|%5.2f",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe);
		}
	}
}
/// @brief Esta funcion imprime los tipos de albumes
///
/// @param list
/// @param len
void informarTiposAlbum (eTipoAlbum list[],int len){
	int i;
	printf("\nLos tipo de album son:\nID|DESCRIPCION");
	for(i=0;i<len;i++){
		if(list[i].id>0&&list[i].id<4){
		printf("\n%d|%10s",list[i].id,list[i].datos);
		}
	}
}
/// @brief Esta funcion imprime los albumes que no son de vinilo
///
/// @param list
/// @param len
void informarAlbumNoVinilo(eAlbum list[],int len){
	int i;
	printf("\nLos albumes que no son de vinilo son: \n");
	for (i=0;i<len;i++){
		if (list[i].idTipoAlbum!=1&&list[i].libre==OCUPADO){
			printf("\n%2d|%10s|%3d|%3d|%d|%5.2f",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe);
		}
	}
}
/// @brief Esta funcion imprime los albumes que corresponden a un artista determinado y sean de vinilo
///
/// @param list
/// @param artista
/// @param len
void informarAlbumViniloArtista(eAlbum list[], eArtista artista[],int len){
	int index;
	int aux;
	int i;
	informarArtista(artista, len);
	index= ingresarEntero("\nIngrese el id correspondiente al artista:",99,103);
	for(i=0;i<len;i++){
		if (index==artista[i].id){
			aux=i;
			break;
		}
	}
	printf("\nLos albumes de %s que son de vinilo son:",artista[aux].nombre );
	for (i=0;i<len;i++){
		if (list[i].idArtista==index &&list[i].libre==OCUPADO&& list[i].idTipoAlbum==1){
			printf("\n%2d|%10s|%3d|%3d|%d|%5.2f\n",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe);
		}
	}
}
/// @brief Busca un indice libre
///
/// @param album
/// @param len
/// @return
int buscarLibre(eAlbum album[],int len){
	int i;
	for(i=0;i<len;i++){
		if(album[i].libre==LIBRE){
			break;
		}
	}

	return i;
}

void informarTipoGenero(eAlbum this[],eGenero gen[],eTipoAlbum tipo[],int len){
	int genero,tipoAlbum,contador,i;
	contador=0;
	informarGenero(gen, len);
	genero=ingresarEntero("\nIngrese el genero del album",999,1003);
	informarTiposAlbum(tipo, len);
	tipoAlbum=ingresarEntero("\nIngrese el tipo de album",0,4);
	for(i=0;i<len;i++){ //recorre list
				if(this[i].libre==OCUPADO&&this[i].idGenero==genero&&this[i].idTipoAlbum==tipoAlbum){
					contador++;
				}
	}
	printf("\nLa cantidad de albumes que cumplen con el filtro es: %d",contador);
}

void informarFechaExactaSolista (eAlbum list[],eGenero genero[],eArtista artista[],eTipoAlbum tipoAlbum[],eTipoArtista tipo[],int len){
	int eleccion;
	int i,j,k,n,m;
	eleccion=ingresarEntero("\nIngrese el anio: ",1947,2023);
	printf("Los albumes del anio %d y solista son:",eleccion );
	for (i=0;i<len;i++){
		if (list[i].publicacion.anio==eleccion&&list[i].libre==OCUPADO&&list[i].idTipo==10){
			for( j = 0; j < 16; j++)
				            {
				                for( k = 0; k < 8; k++)
				                {
				                    for( n = 0; n < 3; n++)
				                    {
				                        for( m = 0; m < 2; m++)
				                        {
				                            if(list[i].idArtista == artista[j].id
				                                && list[i].idGenero == genero[k].id
				                                && list[i].idTipoAlbum == tipoAlbum[n].id
				                                && list[i].idTipo == tipo[m].id)
				                            {
				                        		printf("\n%2d|%10s|%3d|%3d|%d|%5.2f|%s|%s|%s|%s",list[i].id,list[i].titulo,list[i].publicacion.dia,list[i].publicacion.mes,list[i].publicacion.anio,list[i].importe,
				                        															artista[j].nombre,tipo[m].descripcion,genero[k].descripcion,tipoAlbum[n].datos);
				                            }
				                        }
				                    }
				                }

				            }
		}
	}

}
