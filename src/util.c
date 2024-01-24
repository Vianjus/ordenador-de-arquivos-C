#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "util.h"

bool lerEntrada(Argumentos* argumentos, int argc, char** argv){

  if(argc < 4 || argc > 5)
    return false;

  argumentos->metodo = atoi(argv[1]);
  argumentos->quantidade = atoi(argv[2]);
  argumentos->situacao = atoi(argv[3]);

  if(argumentos->metodo < 1 || argumentos->metodo > 3 || argumentos->situacao < 1 || argumentos->situacao > 3 || argumentos->quantidade > 471705 || argumentos->quantidade < 1)
    return false;

  if(argc == 5){
    if((strcmp(argv[4], "-p") == 0) || (strcmp(argv[4], "-P") == 0))
      strcpy(argumentos->opcional, "-p\0");

    else
      return false;
  }
  
  return true;
}

void copiarProvao (int n, FILE* entrada, FILE* resultado){
  char linha[100];
  printf("%d\n",n);
  for (int i = 0; i < n*2; i++){
    printf("%d",i);
    fgets(linha, sizeof(linha), entrada);
    fputs(linha, resultado);
    printf(" - %d\n",i);
  }
}

void txt_binarios (FILE* entrada, FILE* saida){
  Registro registro;
  while (fscanf(entrada, "%d %lf", &registro.id, &registro.nota) == 2){
    fgets(registro.uf,2, entrada);
    fgets(registro.cidade, 50, entrada);
    fgets(registro.curso, 30, entrada);
    fwrite(&registro, sizeof(Registro), 1, saida);
  }
}

void print_bin (FILE *bin){
  Registro registro;
  rewind(bin);
  while (fread(&registro, sizeof(Registro), 1, bin)) {
    printf("%08d %05.1f%s %s %s\n", registro.id, registro.nota, registro.uf, registro.cidade, registro.curso);
  }
  printf("\n");
  rewind(bin);
}

void binario_txt (FILE* entrada, FILE* saida){
  Registro registro;
  rewind(entrada);
  while (feof(entrada))
  {
    fread(&registro, sizeof(Registro), 1, entrada);
    fprintf(saida, "%08d %05.1f %s %s %s", registro.id, registro.nota, registro.uf, registro.cidade, registro.curso);
  }
}