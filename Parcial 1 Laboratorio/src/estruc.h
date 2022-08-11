#ifndef ESTRUC_H
#define ESTRUC_H

#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "biblioteca.h"

typedef struct{
	int id;
	char descripcion[51];
}eGenero;

typedef struct{
	int id;
	char descripcion[51];
}eTipoArtista;

typedef struct{
	int id;
	char nombre[51];
}eArtista;

typedef struct{
	int dia;
	int mes;
	int anio;
}eFecha;

typedef struct{
	int id;
	char datos[51];
}eTipoAlbum;

typedef struct{
	int id;
	char titulo[51];
	eFecha publicacion;
	float importe;
	int idArtista;
	int idTipo;
	int idGenero;
	int idTipoAlbum;
	int libre; // 1 esta ocupado, 0 esta libre
}eAlbum;

void inicializar(eAlbum list[],int len);
void altaAlbum(eAlbum list[],int len,eTipoAlbum tipoAlbum[],eArtista artista[],eTipoArtista tipo[],eGenero genero[]);
void modificarAlbum(eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len);
int buscarId (eAlbum list[], int len, int id);
int comprobarAlta (eAlbum list [],int len);
void bajaAlbum (eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len);
void subMenu(eAlbum list[],int len,eGenero gen[],eTipoAlbum tipo[]);
float promedio(eAlbum list[],int len, float suma[]);
int fechas(eAlbum list[],int len);
void subMenuCinco(eAlbum list[],eGenero genero[], eArtista artista[],eTipoArtista tipo[], eTipoAlbum tipoAlbum[], int len);
void informarFechaExacta (eAlbum list[],int len);
void informarAlbumArtista(eAlbum list[],eArtista art[],int len);
void informarPromedio(eAlbum list[], int len);
void informarFechas(eAlbum list[],int len, int anio);
void informarNombreOrder (eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len);
void informarNombreAlbum (eAlbum list[],eArtista artista[], eTipoArtista tipo[], eTipoAlbum tipoAlbum[], eGenero genero[],int len);
void informarArtista (eArtista list[],int len);
void informarTipo (eTipoArtista list[],int len);
void informarGenero (eGenero list[],int len);
void informarMayor(eAlbum list[],int len);
void informarArtista (eArtista list[],int len);
void informarTiposAlbum (eTipoAlbum list[],int len);
void informarAlbumNoVinilo(eAlbum list[],int len);
void informarAlbumViniloArtista(eAlbum list[], eArtista artista[],int len);
int buscarLibre(eAlbum album[],int len);
void informarTipoGenero(eAlbum this[],eGenero gen[],eTipoAlbum tipo[],int len);
void informarFechaExactaSolista (eAlbum list[],eGenero genero[],eArtista artista[],eTipoAlbum tipoAlbum[],eTipoArtista tipo[],int len);

#endif
