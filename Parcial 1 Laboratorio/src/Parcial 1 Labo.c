/*
Parcial 1 Laboratorio
MATIAS BARROZO IF
 */

#include "estruc.h"
#define TAM 10

int main(void) {
	setbuf(stdout, NULL);
	int eleccion=0;
	eAlbum album[TAM];
  	eArtista artista[3]= {{100,"Queen"},{101,"Soda Stereo"},{102,"Metalica"}};
	eTipoArtista tipo[2]={{10,"Solista"},{11,"Banda"}};
	eGenero genero[3]={{1000,"Rock"},{1001,"Mas rock"}, {1002,"Todavia mas Rock"}};
	eTipoAlbum tipoAlbum[3]={{1,"Vinilo"},{2,"Cinta"},{3,"CD"}};

	inicializar(album,TAM);
	do{
		eleccion=ingresarEntero("\n1-Alta\n2-Modificar\n3-Baja\n4-Informar\n5-Listar\n6-Salir \nSu opcion: ",0,7);
		switch (eleccion){
		case 1:
			altaAlbum(album,TAM,tipoAlbum,artista,tipo,genero);
			break;
		case 2:
			modificarAlbum(album,artista,tipo,tipoAlbum,genero,TAM);
			break;
		case 3:
			bajaAlbum(album,artista,tipo,tipoAlbum,genero,TAM);
			break;
		case 4:
			subMenu(album,TAM,genero,tipoAlbum);
			break;
		case 5:
			subMenuCinco(album,genero,artista,tipo,tipoAlbum,TAM);
			break;
		case 6:
			break;
		default:
			printf("\nIngrese una opcion correcta!!");
			break;
		}
	}while (eleccion!=6);
	return 0;
}
