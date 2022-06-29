#include "test.h"


eComputadora* newPc(char* id, char* desc,char* precio, char* idTipo){
	eComputadora* aux;
	aux= (eComputadora*)malloc(sizeof(eComputadora));
	if (aux!=NULL){

		aux->id=atoi(id);
		strcpy(aux->descripcion,desc);
		aux->precio=atof(precio);
		aux->idTipo=atoi(idTipo);

	}
	else{
		printf("Error");
	}
	return aux;
}

int loadPc(char* path , LinkedList* list)
{
	FILE* txt;
	txt=fopen(path,"r");
	if (txt==NULL){
		printf("No se pudo abrir el archivo\n");
	}
	else{
		lectura(list,txt);
	}

	fclose(txt);

    return 1;
}

void lectura (LinkedList* list, FILE* path){
	eComputadora* p;
	char id[20];
	char descripcion[200];
	char precio[20];
	char idTipo[20];
		 fscanf(path,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);
		 while(!feof(path)){

			 fscanf(path,"%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo);
			 p=newPc(id,descripcion,precio,idTipo);
			 if(p!=NULL){
				 ll_add(list,p);
			 }
			 else{
				printf("Error");
			 }
		 }



}

int printPc(LinkedList* list)
{
	int id;
	char desc[200];
	int idTipo;
	float precio;
	int i=0;
	eComputadora *aux;
	int x=ll_len(list);
	for(i=0;i<x;i++){
		aux=(eComputadora*) ll_get(list,i);
		id=aux->id;
		strcpy(desc,aux->descripcion);
		precio=aux->precio;
		idTipo=aux->idTipo;
		if(aux!=NULL){

			if(idTipo==1){
				printf("%4d %14s %14.2f Desktop \n ",id,desc,precio);
			}
			else {
				printf("%4d %14s %14.2f Laptop \n ",id,desc,precio);
			}

		}
	}
    return i;
}
int compareByIdTipo(void* pasajeroUno, void* pasajeroDos){
	int retorno=-1;
	int idUno=0;
	int idDos=0;

	if (pasajeroUno!=NULL && pasajeroDos!=NULL){
		pc_getIdTipo((eComputadora*)pasajeroUno,&idUno);
		pc_getIdTipo((eComputadora*)pasajeroDos,&idDos);
		if(idUno>idDos){
			retorno=1;
		}else if(idUno<idDos){
			retorno=-1;
		}
		else{
			retorno=0;
		}
	}
	return retorno;
}

int pc_getIdTipo(eComputadora* this,int* idTipo){
	if(this!=NULL){
	*idTipo=this->idTipo;
	}
	return 1;
}

int pc_getprecio(eComputadora* this,float* precio){
	if(this!=NULL){
	*precio=this->precio;
	}
	return 1;
}
void precioAumenta(void* aux){
	float precio;
	int idTipo;

	pc_getprecio((eComputadora*)aux, &precio);
	pc_getIdTipo((eComputadora*)aux, &idTipo);

	if(idTipo==1){
		precio=precio*1.1;
	}
	else{
		precio=precio*1.2;
	}

	pc_setprecio((eComputadora*)aux, precio);

}

int pc_setprecio(eComputadora* this,float precio){
	if(this!=NULL){
	this->precio=precio;
	}
	return 1;
}


void savePc(LinkedList* list){
	int i=1;
		int id;
		char des[200];
		float precio;
		int idTipo;
		int cant=ll_len(list);
		eComputadora* aux;
		FILE* txt=fopen("asd.csv","w");
		if(txt==NULL){
			printf("El archivo no se pudo abrir\n");
		}
		else{
			fprintf(txt,"id,descripcion,price,tipoId\n");
			for(i=0;i<cant;i++){
				aux=(eComputadora*) ll_get(list,i);
				id=aux->id;
				strcpy(des,aux->descripcion);
				precio=aux->precio;
				idTipo=aux->idTipo;
				if(aux!=NULL){
				fprintf(txt,"%d,%s,%f,%d\n",id,des,precio,idTipo);
				}
			}
		}
		fclose(txt);
}
