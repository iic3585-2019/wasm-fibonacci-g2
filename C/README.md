Para correr el codigo se necesita instalar:
```
**emcc**: https://emscripten.org/docs/getting_started/downloads.html
**python**
```

Luego se dentro de esta carpeta se debe correr el siguiente comando para compilar: 
```
emcc -o index.js ./library/src/listas/arraylist/arraylist.c index.c -s NO_EXIT_RUNTIME=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' --emrun
```

Finalmente se debe ejecutar un server en python con:

```
python -m SimpleHTTPServer 8080

```

Y finalmente al entrar a la consola del browser se podran observar los prints hechos en el modulo `main.js`

**OJO: Es muy importante al momento de instalar emcc, cuando se importan las variables de entorno, se debe utilizar esa misma terminal para ejecutar el programa, osino hay que volver a traer las variables de entorno**