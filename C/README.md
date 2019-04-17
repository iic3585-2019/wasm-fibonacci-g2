emcc -o index.js ./library/src/listas/arraylist/arraylist.c index.c -s NO_EXIT_RUNTIME=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["ccall", "cwrap"]' --emrun

emrun.py --no_browser . 
