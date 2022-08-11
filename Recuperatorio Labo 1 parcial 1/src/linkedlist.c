#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

/*

struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;

  */

static Node* getNode(LinkedList* this, int nodeIndex);


static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));

    if(this != NULL)
    {
    	this->pFirstNode = NULL;
    	this->size = 0;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{

	int returnAux = -1;
	if(this != NULL)
	{
		returnAux = this->size;
	}

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		pNode = this->pFirstNode;

				for(int i = 0 ; i < nodeIndex ; i ++)
				{
					pNode = pNode->pNextNode;
				}
	}
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	Node*  pNode = NULL;
	Node* pPreviousNode = NULL ;
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len)
    {
    	pNode = (Node*)malloc(sizeof(Node));

    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		pNode->pNextNode = NULL;

    		if(nodeIndex == 0)
    		{
    			pNode->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNode;
    		}
    		else
    		{
    			pPreviousNode = getNode(this, nodeIndex -1);
    			if(pPreviousNode != NULL)
    			{
    				pNode->pNextNode = pPreviousNode->pNextNode;
					pPreviousNode->pNextNode = pNode;
    			}
    		}
    		this->size++;
    		returnAux = 0;
    	}
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{

	int lastIndex = ll_len(this);
    int returnAux = -1;

    if(this != NULL && addNode(this, lastIndex, pElement) == 0)
    {
    	this->size = lastIndex  +1;
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
	Node* pNode = NULL;
    void* returnAux = NULL;
    int len = ll_len(this);

    if(this != NULL && index <= len && index >= 0)
    {
    pNode = getNode(this, index);
		if(pNode != NULL)
		{
			returnAux = (Node*) pNode->pElement;
		}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
	Node* pNode = NULL;
	int  returnAux = -1;
	int len = ll_len(this);

	    if(this != NULL && index <= len && index >= 0)
	    {
	    pNode = getNode(this, index);
			if(pNode != NULL)
			{
				pNode->pElement = pElement;
				returnAux = 0;
			}
	    }


    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNode = NULL;
    Node* pPreviousNode = NULL;
    int len = ll_len(this);

    if(this != NULL && index < len && index >= 0)
    {
    	pNode = getNode(this, index);
    	pPreviousNode = getNode(this, index -1);
    	{
    		if(index == 0)
    		{
    			this->pFirstNode = pNode->pNextNode ;
    		}
    		else
    		{
    			pPreviousNode->pNextNode = pNode->pNextNode;
    		}
    		free(pNode);
    		this->size--;
			returnAux = 0;
    	}
    }

    return returnAux;
}
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int  len = ll_len(this);
    if(this != NULL)
    {
    	for(int i = 0; i < len ; i ++)
    	{
    		ll_remove(this, i);
    		returnAux = 0;
    	}
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
       if(this != NULL)
       {
    	   ll_clear(this);
    	   free(this);
    	   returnAux = 0;
       }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode = NULL;
    int len  = ll_len(this);

    if(this != NULL)
    {
    	for(int i = 0 ; i < len; i ++)
    	{
    		pNode = getNode(this, i);
    		if(pElement == pNode->pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);
    if(this != NULL)
    {
    	if( len != 0 )
    	{
    		returnAux = 0;
    	}
	  else
		{
			returnAux = 1;
		}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);

    if(this != NULL && index <= len && index >= 0 )
    {
		addNode(this, index, pElement);
		returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);

    if(this != NULL && index <= len && index >= 0 )
    {
    	returnAux = (Node*) ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len = ll_len(this);
    void* pElementAux;

    if(this != NULL)
    {
    		returnAux = 0;
			for(int i = 0 ; i < len ; i ++)
			{
					pElementAux =(Node*)ll_get(this, i);
					if(pElement == pElementAux)
					{
						returnAux  = 1;
						break;
					}
			}
	}


    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len = ll_len(this2);
    void* pElementAux;

	if(this != NULL && this2 != NULL)
    {
		returnAux = 1;

		for(int i = 0; i < len; i ++)
		{
			pElementAux = (Node*)ll_get(this2, i);

			if(ll_contains(this, pElementAux) == 0)
			{
				returnAux = 0;
				break;
			}
		}
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    void* pElement;

    if(this != NULL && from >= 0 && from <= len && to >= from && to <= len)
    {
    	 cloneArray = ll_newLinkedList();
    	 if(cloneArray != NULL)
    	 {
    		 for(int i = from ; i < to ; i ++)
			{
				pElement = (Node*)ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
    	 }
    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int len = ll_len(this);
    void* pElement;

    if(this != NULL)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		 for(int i = 0 ; i < len ; i ++)
			{
				pElement = (Node*)ll_get(this, i);
				ll_add(cloneArray, pElement);
			}
    	}

    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len = ll_len(this);
    void* pElementAux;

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
    		for(int i = 0; i< len - 1; i ++)
    		{
    			for(int j = i+1 ; j < len ; j++)
    			{
    				if(pFunc (ll_get(this,i), ll_get(this,j) ) < 0 &&   order == 0 )
    				{
    					pElementAux = (Node*)ll_get(this, j);
    					ll_set(this, j, ll_get(this, i));
    					ll_set(this, i, pElementAux);
    				}
    				else if(pFunc(ll_get(this,i), ll_get(this,j) ) > 0 && order == 1)
					{
						pElementAux = (Node*)ll_get(this, i);
						ll_set(this, i, ll_get(this, j));
						ll_set(this, j, pElementAux);
					}
    				returnAux = 0;
    			}
    		}

    }

    return returnAux;

}

int ll_map(LinkedList* this, void (*pFunc)(void*))
{
    int rtn = -1;
    int len =ll_len(this);;
    void* pElement;

    if (this != NULL && pFunc != NULL)
	{

        for (int i = 0; i < len; i++)
        {
            pElement = ll_get(this, i);
            pFunc(pElement);
	}
        rtn = 0;
    }
    return rtn;
}

LinkedList* ll_filter(LinkedList* this, int (*pFunc) (void*))
{
	int len = ll_len(this);
	void* pElement = NULL;
	LinkedList* this2;


	if(this != NULL)
	{
		this2 = ll_newLinkedList();

		if(this2 != NULL)
		{
			for(int i = 0; i < len ; i ++)
					{
						pElement =  ll_get(this, i);

						if(pFunc (pElement) == 1)
						{
							ll_add(this2, pElement);
						}
					}
		}

	}
	return this2;

}
