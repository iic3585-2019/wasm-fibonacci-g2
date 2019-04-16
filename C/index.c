#include "library/src/listas/arraylist/arraylist.h"
#include <emscripten/emscripten.h>

int main()
{
  return 0;
}

char *EMSCRIPTEN_KEEPALIVE foo()
{
  ArrayList *list = arraylist_init();

  for (int i = 0; i < 25; i++)
  {
    arraylist_append(list, i);
  }

  return "hola";
}
