Para inicializar el modulo de rust primero se debe ejecutar en esta carpeta el comando

```
npm install
```

Luego

```
npm run build
```

Y finalmente

```
npm start
```

Con eso el programa estara corriendo en `http://localhost:8080`, si se inspecciona y se accede a la consola del browser se veran los prints alli, para agregar mas paises simplemente se descomenta, los paises creados, se agrega el pais al arreglo `countries` y se descomenta abajo donde se esta agregando el pais al mapa.

**Nota: La primera vez que se corre `npm run build` se demora mucho**