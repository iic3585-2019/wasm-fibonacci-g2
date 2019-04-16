// importo el archivo linkedlist.h
#include "linkedlist.h"
// Libreria estandar de C
#include <stdlib.h>
#include <stdio.h>

//////////////////////////////////////////////////////////////////////////
//                             Funciones                                //
//////////////////////////////////////////////////////////////////////////

// TODO: debes completar las funciones que estan a continuacion
// Puedes crear otras funciones aca para el
// funcionamiento interno del arreglo dinamico
Node* node_init()
{
    Node* node = malloc(sizeof(Node));
    node ->next = NULL;
    node ->preview = NULL;
    return node;
}
/** Crea una lista inicialmente vacia y retorna el puntero */
LinkedList* linkedlist_init()
{
  LinkedList* list = malloc(sizeof(LinkedList));
  list -> head = NULL;
  list -> tail = NULL;
  list->count = 0;
  return list;
}


/** Inserta un elemento al final de la lista */
void linkedlist_append(LinkedList* list, int element)
{
  if (list -> count == 0){
    list->head = node_init();
    list->head->value = element;
    list ->tail = list->head;
  }
  else if(list->count == 1){
    Node* actual = node_init();
    actual->value = element;
    list ->tail = actual;
    actual->preview = list->head;
    list->head->next = actual;
  }
  else{
    Node* preview = list->tail;
    Node* actual = node_init();
    actual->value = element;
    list ->tail = actual;
    actual->preview = preview;
    preview->next = actual;
  }
  list->count++;
}

/** Inserta el elemento dado en la posicion indicada */
void linkedlist_insert(LinkedList* list, int element, int position)
{
  if(position == list-> count){
    linkedlist_append(list, element);
  }
  else{
    Node* node = list->head;
    for (int i = 0; i < position; i++) {
      node = node->next;
    }
    Node* actual = node_init();
    actual->value = element;
    if (position == 0){
      list->head = actual;
      node->preview = list->head;
      list->head->next = node;
      if(list->count == 1){
        list->tail = node;
      }
    }
    else{
    Node* preview = node ->preview;
    actual->next = node;
    preview->next = actual;
    actual->preview = preview;
    node->preview = actual;
    preview->next = actual;
    }
    list->count++;
  }
}

/** Elimina el elemento de la posicion indicada y lo retorna */
int linkedlist_delete(LinkedList* list, int position)
{
  Node* node = list->head;
  int valor = node->value;
  if (position == list->count - 1){
    node = list->tail;
    list->tail = node->preview;
  }
  else if(position == 0){
    list->head = node->next;
  }
  else{
    for (int i = 0; i < position; i++) {
      node = node->next;
    }
    node->next->preview = node->preview;
    node->preview->next = node->next;
  }
  free(node);
  list->count--;
  return valor;
}

/** Retorna el valor del elemento en la posicion dada */
int linkedlist_get(LinkedList* list, int position)
{
  Node* node = list->head;
  for (int i = 0; i < position; i++) {
    node = node->next;
  }
  return node->value;
}

/** Concatena a la lista una segunda lista */
void linkedlist_concatenate(LinkedList* list, LinkedList* list2)
{
  list->tail->next = list2->head;
  list2->head->preview = list->tail;
  list->tail =  list2->tail;
  list->count += list2->count;
  free(list2);
}

/** Libera todos los recursos asociados a la lista */
void linkedlist_destroy(LinkedList* list)
{
  Node* node = list->head;
  for (int i = 0; i < list->count; i++) {
    Node* aux = node->next;
    free(node);
    node = aux;
  }
  free(list);
}
