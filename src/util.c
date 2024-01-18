#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "util.h"

bool lerEntrada(Argumentos* argumentos, int argc, char** argv){

  // Verifica se o numero de argumentos esta dentro do esperado
  if(argc < 4 || argc > 5)
    return false;

  argumentos->metodo = atoi(argv[1]);
  argumentos->quantidade = atoi(argv[2]);
  argumentos->situacao = atoi(argv[3]);

  if(argumentos->metodo < 1 || argumentos->metodo > 3 || argumentos->situacao < 1 || argumentos->situacao > 3 || argumentos->quantidade > 471.705 || argumentos->quantidade < 1)
    return false;

  if(argc == 5){
    if((strcmp(argv[4], "-p") == 0) || (strcmp(argv[4], "-P") == 0))
      strcpy(argumentos->opcional, "-p\0");

    else
      return false;
  }
  
  return true;
}