#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "intercalacao2f.h"

#define NUM_FITAS_ENTRADA 10
#define NUM_FITAS_SAIDA 10
#define TAM_BLOCO 4
#define MAX_MEMORIA_INTERNA 10


// Função para comparar dois registros pelo campo 'nota'
int compararRegistros(const void *a, const void *b) {
    return ((Registro*)a)->nota - ((Registro*)b)->nota;
}

// Função para realizar a intercalação balanceada
void intercalacaoBalanceada(FILE* arquivoEntrada) {
  FILE *fitasEntrada[NUM_FITAS_ENTRADA], *fitasSaida[NUM_FITAS_SAIDA];
  Registro bloco[TAM_BLOCO];
  Registro memoriaInterna[MAX_MEMORIA_INTERNA];
  char nomeFita[20];
  int i;
  
  // Inicializa as fitas de entrada
  for (i = 0; i < NUM_FITAS_ENTRADA; i++) {
    sprintf(nomeFita, "fita_entrada%d.bin", i);
    fitasEntrada[i] = fopen(nomeFita, "wb");
    if (fitasEntrada[i] == NULL) {
      perror("Erro ao abrir a fita de entrada");
      exit(EXIT_FAILURE);
    }
  }

  // Distribui os blocos iniciais nas fitas de entrada
  for (i = 0; i < NUM_FITAS_ENTRADA; i++) {
    fread(bloco, sizeof(Registro), TAM_BLOCO, arquivoEntrada);
    qsort(bloco, TAM_BLOCO, sizeof(Registro), compararRegistros);
    fwrite(bloco, sizeof(Registro), TAM_BLOCO, fitasEntrada[i]);
  }

  // Fecha o arquivo de entrada
  fclose(arquivoEntrada);

  // Inicializa as fitas de saída
  for (i = 0; i < NUM_FITAS_SAIDA; i++) {
    sprintf(nomeFita, "fita_saida%d.bin", i);
    fitasSaida[i] = fopen(nomeFita, "wb");
    if (fitasSaida[i] == NULL) {
      perror("Erro ao abrir a fita de saída");
      exit(EXIT_FAILURE);
    }
  }

  // Executa as etapas de intercalação
  int etapa = 1;
  while (1) {
    int registrosLidos = 0;

    // Lê blocos das fitas de entrada para a memória interna
    for (i = 0; i < MAX_MEMORIA_INTERNA; i++) {
      if (fread(&memoriaInterna[i], sizeof(Registro), 1, fitasEntrada[i]) == 1) 
        registrosLidos++;
      
      else 
        break;
            
    }

    // Se não há mais registros para ler, encerra o loop
    if (registrosLidos == 0)
      break;
      

    // Ordena os registros na memória interna
    qsort(memoriaInterna, registrosLidos, sizeof(Registro), compararRegistros);

    // Escreve os registros ordenados nas fitas de saída
    for (i = 0; i < registrosLidos; i++) 
      fwrite(&memoriaInterna[i], sizeof(Registro), 1, fitasSaida[i % NUM_FITAS_SAIDA]);
    

    // Avança para a próxima etapa
    etapa++;

    // Troca fitas de entrada e saída
    for (i = 0; i < NUM_FITAS_SAIDA; i++) {
      fclose(fitasSaida[i]);
      sprintf(nomeFita, "fita_saida%d.bin", i);
      fitasSaida[i] = fopen(nomeFita, "rb");
      if (fitasSaida[i] == NULL) {
        perror("Erro ao abrir a fita de saída para leitura");
        exit(EXIT_FAILURE);
      }
    }

    for (i = 0; i < NUM_FITAS_ENTRADA; i++) {
      fclose(fitasEntrada[i]);
      sprintf(nomeFita, "fita_entrada%d.bin", i);
      fitasEntrada[i] = fopen(nomeFita, "wb");
      if (fitasEntrada[i] == NULL) {
        perror("Erro ao abrir a fita de entrada");
        exit(EXIT_FAILURE);
      }
    }
  }

    // Fecha as fitas temporárias
  for (i = 0; i < NUM_FITAS_SAIDA; i++) {
    fclose(fitasSaida[i]);
    sprintf(nomeFita, "fita_saida%d.bin", i);
    remove(nomeFita);
  }

  for (i = 0; i < NUM_FITAS_ENTRADA; i++) {
    fclose(fitasEntrada[i]);
    sprintf(nomeFita, "fita_entrada%d.bin", i);
    remove(nomeFita);
  }
}

