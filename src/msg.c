#include <stdio.h>
#include <stdbool.h>

void msg_erro_args(char *name){
  printf("[Erro] -> O modo de executar o programa está errado, execute de acordo:\n");
  printf("%s <método> <quantidade> <situação> [-P|-p]\n\n", name);
  printf("[!] -> Os valores aceitos:\n");
  printf("Metodos: 1=(2f Fitas)  2=(f+1 Fitas) 3=(QuickSort Ex.)\n");
  printf("Quantidades: De 1 a 471.705\n");
  printf("Situação: 1=(Ordenado Ascendente)  2=(Ordenado Descendente)  3=(Desordenado Aleatório)\n");
}

void msg_erro_arq(){
  printf("[Erro] -> Arquivo de texto não pode ser aberto ou localizado.\n");
}