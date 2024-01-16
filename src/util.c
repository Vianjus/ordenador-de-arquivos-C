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
    
  if(argc == 5){
    strcpy(argumentos->opcional, argv[4]);

    // Se o argumento opcional for diferente de -P, entao retorna falso
    if((strcmp(argumentos->opcional, "-p") == 0) || (strcmp(argumentos->opcional, "-P") == 0))
      return false;
  }

  else
    argumentos->opcional[0] = '\0';

  if(argumentos->metodo < 1 || argumentos->metodo > 3 || argumentos->situacao < 1 || argumentos->situacao > 3 || argumentos->quantidade > 471.705 || argumentos->quantidade < 1)
    return false;

  return true;
}