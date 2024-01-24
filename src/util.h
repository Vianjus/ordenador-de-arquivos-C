#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
  int metodo;
  int quantidade;
  int situacao;
  char opcional[3];

} Argumentos;

typedef struct
{
  int id;
  double nota;
  char uf[2];
  char cidade[50];
  char curso[30];

} Registro;

bool lerEntrada(Argumentos*, int, char**);
void txt_binarios(FILE*, FILE*);
void print_bin(FILE*);
void binario_txt(FILE*, FILE*);