#include "library/src/listas/arraylist/arraylist.h"
#include <emscripten/emscripten.h>
#include <stdio.h>

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

int *EMSCRIPTEN_KEEPALIVE appendToArray(int *array, int length, int number)
{
  ArrayList *list = list_from_array(array, length);
  arraylist_append(list, number);

  return list->array;
}

int *EMSCRIPTEN_KEEPALIVE insertToArray(int *array, int length, int number, int position)
{
  ArrayList *list = list_from_array(array, length);
  arraylist_insert(list, number, position);

  return list->array;
}

int *EMSCRIPTEN_KEEPALIVE deleteFromArray(int *array, int length, int position)
{
  ArrayList *list = list_from_array(array, length);
  arraylist_delete(list, position);

  return list->array;
}

int *EMSCRIPTEN_KEEPALIVE concatenateArrays(int *left_array, int left_length, int *right_array, int right_length)
{
  ArrayList *left_list = list_from_array(left_array, left_length);
  ArrayList *right_list = list_from_array(right_array, right_length);
  arraylist_concatenate(left_list, right_list);

  return left_list->array;
}
