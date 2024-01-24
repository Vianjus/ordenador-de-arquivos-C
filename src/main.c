#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "util.h"
#include "msg.h"
#include "intercalacao2f.h"

int main (int argc, char* argv[]){

  //Tratamento das entradas de argumentos.
  Argumentos argumentos;  
  if(lerEntrada(&argumentos, argc, argv) == false){
    msg_erro_args(argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *texto_bruto = fopen("arqs/PROVAO.TXT", "r");
  FILE *texto_bruto_bin = fopen("arqs/provao.bin", "rb"); 
  if (texto_bruto == NULL && texto_bruto_bin == NULL){
    msg_erro_arq();
    exit(EXIT_FAILURE);
  }

  if(texto_bruto_bin == NULL){
    texto_bruto_bin = fopen("arqs/provao.bin", "wb");
    txt_binarios(texto_bruto, texto_bruto_bin);
  }
  
  print_bin(texto_bruto_bin);
  intercalacaoBalanceada(texto_bruto_bin);
  print_bin(texto_bruto_bin);

  return 0;
}