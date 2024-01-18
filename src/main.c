#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "util.h"

int main (int argc, char* argv[]){

  //Tratamento das entradas de argumentos.
  Argumentos argumentos;
  
  if(lerEntrada(&argumentos, argc, argv) == false){
    printf("[Erro] -> O modo de executar o programa está errado, execute de acordo:\n");
    printf("%s <método> <quantidade> <situação> [-P|-p]\n\n", argv[0]);
    printf("[!] -> Os valores aceitos:\n");
    printf("Metodos: 1=(2f Fitas)  2=(f+1 Fitas) 3=(QuickSort Ex.)\n");
    printf("Quantidades: De 1 a 471.705\n");
    printf("Situação: 1=(Ordenado Ascendente)  2=(Ordenado Descendente)  3=(Desordenado Aleatório)\n");
    exit(EXIT_FAILURE);
  }

  printf("\n%s", argumentos.opcional);

  return 0;
}