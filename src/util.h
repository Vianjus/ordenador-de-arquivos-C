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

bool lerEntrada(Argumentos*, int, char**);