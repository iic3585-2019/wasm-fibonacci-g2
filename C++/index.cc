#include <iostream>
#include "avir/avir.h"
#include <emscripten/emscripten.h>

extern "C"
{
  avir::CImageResizerVars EMSCRIPTEN_KEEPALIVE foo()
  {
    avir::CImageResizerVars *x = new avir::CImageResizerVars();

    return *x;
  }
}

int main()
{
  avir::CImageResizerVars *x = new avir::CImageResizerVars();

  return 0;
}
