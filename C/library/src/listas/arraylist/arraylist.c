// Importo el archivo arraylist.h
#include "arraylist.h"
// Libreria estandar de C
#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: Debes completar las siguientes funciones
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico

/** Crea una arraylist inicialmente vacia y retorna su puntero */
ArrayList* arraylist_init()
{
  ArrayList* list = malloc(sizeof(ArrayList));
  list -> size = 8;
  list -> count = 0;
  list -> array = malloc(sizeof(int)* list->size);
  return list;
}

/** Inserta un elemento al final de la arraylist */
void arraylist_append(ArrayList* list, int element)
{
  if (list -> count == list -> size){
    list -> size *= 2;
    int* aux = malloc(sizeof(int)* list->size);
    for (int i = 0; i < list->count; i++) {
      aux[i] = list->array[i];
    }
    free(list->array);
    list->array = aux;
  }
  list -> array[list->count] = element;
  list -> count++;

}

/** Inserta el elemento dado en la posicion indicada */
void arraylist_insert(ArrayList* list, int element, int position)
{
  if (list -> count == list -> size){
    list -> size *= 2;
    int* aux = malloc(sizeof(int)* list->size);
    for (int i = 0; i < list->count; i++) {
      aux[i] = list->array[i];
    }
    free(list->array);
    list->array = aux;
  }
  int aux = list->count;
  while (aux > position){
    list -> array[aux] = list -> array[aux - 1];
    aux--;
  };
  list -> array[position] = element;
  list -> count++;
}

/** Elimina el elemento de la posicion indicada y lo retorna */
int arraylist_delete(ArrayList* list, int position)
{
  if (list -> count == list -> size){
    list -> size *= 2;
    int* aux = malloc(sizeof(int)* list->size);
    for (int i = 0; i < list->count; i++) {
      aux[i] = list->array[i];
    }
    free(list->array);
    list->array = aux;
  }
  int element = list ->array[position];
  while (position < list -> count){
    list -> array[position] = list -> array[position + 1];
    position++;
  };
  list -> count--;
  return element;
};

/** Retorna el valor del elemento en la posicion dada */
int arraylist_get(ArrayList* list, int position)
{
  return list-> array[position];
}

/** Concatena la segunda arraylist a la primera arraylist */
void arraylist_concatenate(ArrayList* list1, ArrayList* list2)
{
  int aux = 0;
  while ((list1->count + list2->count) > list1->size){
    list1 -> size *= 2;
    int* aux = malloc(sizeof(int)* list1->size);
    for (int i = 0; i < list1->count; i++) {
      aux[i] = list1->array[i];
    }
    free(list1->array);
    list1->array = aux;
  }
  int aux2 = list1->count;
  while(list1->count < (aux2 + list2->count)){
    list1->array[list1->count] = list2->array[aux];
    list1 ->count++;
    aux++;
  }
  arraylist_destroy(list2);
}

/** Libera todos los recursos asociados a la lista */
void arraylist_destroy(ArrayList* list)
{
  free(list->array);
  free(list);
}
