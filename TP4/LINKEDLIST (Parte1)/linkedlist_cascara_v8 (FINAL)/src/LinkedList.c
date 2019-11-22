#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


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

    this = (LinkedList*) malloc (sizeof(LinkedList));

    if (this != NULL){

        this -> pFirstNode = NULL;
        this -> size = 0;
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

    if (this != NULL){
        returnAux = this-> size;
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
    Node* auxNode = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))
    {
        auxNode = this -> pFirstNode;

        for(int i = 0; i < nodeIndex; i ++)
        {
            auxNode = auxNode -> pNextNode;
        }
    }
    return auxNode;
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
    return getNode(this,nodeIndex);
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
    int returnAux = -1;
    Node* prev;
    Node* next;
    Node* nuevo;

    if( this != NULL)
    {
        if(nodeIndex >= 0 && nodeIndex <= ll_len(this))
        {
            nuevo = (Node*) malloc(sizeof(Node));

            if(nuevo != NULL)
            {
                nuevo -> pElement = pElement;
                nuevo -> pNextNode = NULL;

                if(nodeIndex == 0)
                {
                    nuevo -> pNextNode = this -> pFirstNode;
                    this -> pFirstNode = nuevo;
                }
                else
                {
                    prev = this -> pFirstNode;
                    next = prev -> pNextNode;

                    while( nodeIndex > 1)
                    {
                        prev  = next;
                        next  = prev -> pNextNode;
                        nodeIndex --;
                    }

                    prev -> pNextNode = nuevo;
                    nuevo -> pNextNode = next;
                }
                this -> size ++;
                returnAux = 0;
            }
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
    int returnAux = -1;


    if(this != NULL){

        addNode(this, ll_len(this), pElement);

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
    void* returnAux = NULL;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this,index);
        returnAux = auxNode -> pElement;
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
    int returnAux = -1;
    Node* auxNode;

    if(this != NULL && index >= 0 && index < ll_len(this))
    {
        auxNode = getNode(this , index);
        auxNode -> pElement = pElement;
        returnAux = 0;
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
    Node* auxNode;
    Node* prev;
    Node* next;

    if(this != NULL && index >= 0 && index < ll_len(this) && ll_len(this) > 0)
    {
        if (index == 0)
        {
            auxNode = getNode(this , index);
            this -> pFirstNode = auxNode -> pNextNode;
            free(auxNode);
            this -> size--;
            returnAux = 0;
        }
        else
        {
            auxNode = getNode(this , index);
            prev = getNode(this , index -1);
            next = getNode(this , index +1);
            prev -> pNextNode = next;
            free(auxNode);
            this -> size --;
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
    int tam = ll_len(this);

    if(this != NULL)
    {
        for (int h = 0; h < tam ; h++){
            for(int i = 0; i < tam ; i ++)
            {
                ll_remove(this , i);
                returnAux = 0;
            }
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
    Node* auxNode;

    if (this!=NULL){

        auxNode = getNode(this , 0);
        free(auxNode);
        this -> size =- ll_len(this);

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
    Node* auxNode;

    if(this!=NULL){

        for(int i = 0 ; i < ll_len(this) ; i ++){

            auxNode = getNode(this , i);

            if(auxNode -> pElement == pElement){

                returnAux = i;
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

    if (this != NULL){

        if(this -> size == 0){

            returnAux = 1;
        }
        else{

            returnAux = 0;
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
    int retorno;

    if(this != NULL && index >= 0 && index <= ll_len(this))
    {
        retorno = addNode(this, index, pElement);

        returnAux = retorno;

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
    void* auxElement;

    if(this != NULL && index >= 0 && index < ll_len(this)){

        auxElement = ll_get(this , index);
        ll_remove(this , index);
        returnAux = auxElement;
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

    if(this != NULL){

        returnAux = 0;

        if(ll_indexOf(this , pElement)!= -1){

            returnAux = 1;
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
    void* pElement;

    if(this != NULL && this2 != NULL){

      returnAux = 1;

      for(int i = 0; i < ll_len(this2); i++){

         pElement = ll_get(this2 , i);

         if(!ll_contains(this , pElement)){

             returnAux = 0;
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
    LinkedList* clone = NULL;
    void *pElement;


    if(this != NULL && from >= 0 && to <= this -> size){

        clone = ll_newLinkedList();

        for(int i = from ; i < to ; i ++){

            pElement = ll_get(this , i);
            ll_add(clone , pElement);
        }
    }
    return clone;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
     return ll_subList(this , 0 , ll_len(this));
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
    int returnAux = -1;
    void* thisA;
    void* thisB;
    int retorno;


    if(this != NULL && ll_len(this)> 0 && pFunc != NULL && (order == 0 || order == 1))
    {

        for(int i = 0 ; i < ll_len(this)-1 ; i ++)
        {

              for(int j = i + 1 ; j < ll_len(this) ; j++)
              {

                thisA = ll_get(this, i);
                thisB = ll_get(this, j);

                if(thisA != NULL && thisB != NULL)
                {
                    retorno = pFunc(thisA, thisB);

                    if((retorno == -1 && order == 0) || (retorno == 1 && order == 1))
                    {
                        ll_set(this, i, thisB);
                        ll_set(this, j, thisA);
                    }
                }
            }
        }returnAux = 0;
    }
    return returnAux;
}

