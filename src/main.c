#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "util.h"

int main (int argc, char* argv[]){

  Argumentos argumentos;
  
  if(lerEntrada(&argumentos, argc, argv) == false)
    {
      printf("O modo de executar o programa esta errado ou algum argumento inserido nao e valido, execute de acordo:\n\n");
      printf("%s <metodo> <quantidade> <situacao> <chave> [-P|-p]\n", argv[0]);

      exit(1);
    }

  printf("%d %d %d %s", argumentos.metodo, argumentos.quantidade, argumentos.situacao, argumentos.opcional);
  return 0;
}