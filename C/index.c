#include "library/src/listas/arraylist/arraylist.h"
#include "library/src/listas/linkedlist/linkedlist.c"
#include <emscripten/emscripten.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
  return 0;
}

ArrayList *list_from_array(int *array, int length)
{

  ArrayList *list = arraylist_init();

  for (int i = 0; i < length; i++)
  {
    arraylist_append(list, array[i]);
  }

  return list;
}

LinkedList *list_from_linked_list(int *array, int length)
{

  LinkedList *list = linkedlist_init();

  for (int i = 0; i < length; i++)
  {
    linkedlist_append(list, array[i]);
  }

  return list;
}

int *getArrayFromLinkedList(LinkedList *list, int length)
{
  int *array = malloc(sizeof(int)* length);
	for (int i = 0; i < length; i++)
  {
    array[i] = linkedlist_get(list, i);
  }
	return array;
}

int *EMSCRIPTEN_KEEPALIVE appendToArray(int *array, int length, int number)
{
  ArrayList *list = list_from_array(array, length);
  arraylist_append(list, number);

  return list->array;
}

int *EMSCRIPTEN_KEEPALIVE appendToLinkedList(int *array, int length, int number)
{
  LinkedList *list = list_from_linked_list(array, length);
  linkedlist_append(list, number);
	int *arrayOfLinkedList = getArrayFromLinkedList(list, length);

  return arrayOfLinkedList;
}

int *EMSCRIPTEN_KEEPALIVE insertToArray(int *array, int length, int number, int position)
{
  ArrayList *list = list_from_array(array, length);
  arraylist_insert(list, number, position);

  return list->array;
}

int *EMSCRIPTEN_KEEPALIVE insertToLinkedList(int *array, int length, int number, int position)
{
  LinkedList *list = list_from_linked_list(array, length);
  linkedlist_insert(list, number, position);

	int *arrayOfLinkedList = getArrayFromLinkedList(list, length);

  return arrayOfLinkedList;
}

int *EMSCRIPTEN_KEEPALIVE deleteFromArray(int *array, int length, int position)
{
  ArrayList *list = list_from_array(array, length);
  arraylist_delete(list, position);

  return list->array;
}

int *EMSCRIPTEN_KEEPALIVE deleteFromLinkedList(int *array, int length, int position)
{
  LinkedList *list = list_from_linked_list(array, length);
  linkedlist_delete(list, position);

  int *arrayOfLinkedList = getArrayFromLinkedList(list, length);

  return arrayOfLinkedList;
}

int *EMSCRIPTEN_KEEPALIVE concatenateArrays(int *left_array, int left_length, int *right_array, int right_length)
{
  ArrayList *left_list = list_from_array(left_array, left_length);
  ArrayList *right_list = list_from_array(right_array, right_length);
  arraylist_concatenate(left_list, right_list);

  return left_list->array;
}

int *EMSCRIPTEN_KEEPALIVE concatenateLinkedLists(int *left_array, int left_length, int *right_array, int right_length)
{
  LinkedList *left_list = list_from_linked_list(left_array, left_length);
  LinkedList *right_list = list_from_linked_list(right_array, right_length);
  linkedlist_concatenate(left_list, right_list);

	int *arrayOfLinkedList = getArrayFromLinkedList(left_list, left_length + right_length);

  return arrayOfLinkedList;
}