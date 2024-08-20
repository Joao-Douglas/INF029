#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#define MAX_TODAS_ESTRUTURAS_AUXILIARES_VAZIAS 9
#define MAX_NOVO_TAMANHO_INVALIDO 10
#define MAX_NUMERO_INEXISTENTE 8
#define MAX_ESTRUTURA_AUXILIAR_VAZIA 7
#define MAX_TAMANHO_INVALIDO 4
#define MAX_SEM_ESPACO_DE_MEMORIA 3
#define MAX_POSICAO_INVALIDA 2
#define MAX_JA_TEM_ESTRUTURA_AUXILIAR 1
#define MAX_SEM_ESTRUTURA_AUXILIAR 6
#define MAX_SEM_ESPACO 5
#define MAX_SUCESSO 0
#include "EstruturaVetores.h"

int *vetorPrincipal[TAM];
int quantidadeElementosEstruturaAuxiliar[TAM];
int tamanhoEstruturaAuxiliar[TAM];
int tamanho;

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {
  posicao--;

  if (posicao < 0 || posicao >= TAM)
      return POSICAO_INVALIDA;

  if (vetorPrincipal[posicao] != NULL)
      return JA_TEM_ESTRUTURA_AUXILIAR;

  if (tamanho < 1)
      return TAMANHO_INVALIDO;

  int *estruturaAuxiliar = (int *)malloc(tamanho * sizeof(int));
  if (estruturaAuxiliar == NULL)
      return SEM_ESPACO_DE_MEMORIA;

  vetorPrincipal[posicao] = estruturaAuxiliar;
  tamanhoEstruturaAuxiliar[posicao] = tamanho;
  quantidadeElementosEstruturaAuxiliar[posicao] = 0;

  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
  posicao--;

  if (posicao < 0 || posicao >= TAM)
      return POSICAO_INVALIDA;

  if (vetorPrincipal[posicao] == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

  if (quantidadeElementosEstruturaAuxiliar[posicao] >= tamanhoEstruturaAuxiliar[posicao])
      return SEM_ESPACO;

  vetorPrincipal[posicao][quantidadeElementosEstruturaAuxiliar[posicao]++] = valor;

  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao) {
  posicao--;

  if (posicao < 0 || posicao >= TAM)
      return POSICAO_INVALIDA;

  if (vetorPrincipal[posicao] == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

  if (quantidadeElementosEstruturaAuxiliar[posicao] == 0)
      return ESTRUTURA_AUXILIAR_VAZIA;

  quantidadeElementosEstruturaAuxiliar[posicao]--;

  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
     posicao--;

      if (posicao < 0 || posicao >= TAM)
          return POSICAO_INVALIDA;

      if (vetorPrincipal[posicao] == NULL)
          return SEM_ESTRUTURA_AUXILIAR;

      if (quantidadeElementosEstruturaAuxiliar[posicao] == 0)
          return ESTRUTURA_AUXILIAR_VAZIA;

      int *estruturaAuxiliar = vetorPrincipal[posicao];
      int i, encontrado = 0;

      for (i = 0; i < quantidadeElementosEstruturaAuxiliar[posicao]; i++) {
          if (estruturaAuxiliar[i] == valor) {
              encontrado = 1;
              break;
          }
      }

      if (encontrado) {
          for (int j = i; j < quantidadeElementosEstruturaAuxiliar[posicao] - 1; j++) {
              estruturaAuxiliar[j] = estruturaAuxiliar[j + 1];
          }
          quantidadeElementosEstruturaAuxiliar[posicao]--;
          return SUCESSO;
      } else {
          return NUMERO_INEXISTENTE;
      }
  }

int ehPosicaoValida(int posicao) {
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    return SUCESSO;
}

/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  posicao--;

  if (posicao < 0 || posicao >= TAM)
      return POSICAO_INVALIDA;

  if (vetorPrincipal[posicao] == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

  for (int i = 0; i < quantidadeElementosEstruturaAuxiliar[posicao]; i++) {
      vetorAux[i] = vetorPrincipal[posicao][i];
  }

  return SUCESSO;
}

void ordenarVetor(int vetor[], int n) {
  for (int i = 0; i < tamanho - 1; i++) {
      for (int j = 0; j < tamanho - i - 1; j++) {
          if (vetor[j] > vetor[j + 1]) {
              int temp = vetor[j];
              vetor[j] = vetor[j + 1];
              vetor[j + 1] = temp;
          }
      }
  }
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
  int resultado = getDadosEstruturaAuxiliar(posicao, vetorAux);
  if (resultado == SUCESSO) {
      ordenarVetor(vetorAux, quantidadeElementosEstruturaAuxiliar[posicao]);
  }
  return resultado;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int totalElementos = 0;

  for (int i = 0; i < TAM; i++) {
      if (vetorPrincipal[i] != NULL && quantidadeElementosEstruturaAuxiliar[i] > 0) {
          for (int j = 0; j < quantidadeElementosEstruturaAuxiliar[i]; j++) {
              vetorAux[totalElementos++] = vetorPrincipal[i][j];
          }
      }
  }

  if (totalElementos == 0)
      return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  return SUCESSO;
}

int getQuantidadeElementosEstruturasAuxiliares() {
    int totalElementos = 0;

    for (int i = 0; i < TAM; i++) {
        totalElementos += quantidadeElementosEstruturaAuxiliar[i];
    }

    return totalElementos;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int resultado = getDadosDeTodasEstruturasAuxiliares(vetorAux);
  if (resultado == SUCESSO) {
      ordenarVetor(vetorAux, getQuantidadeElementosEstruturasAuxiliares());
  }
  return resultado;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
  posicao--;

  if (posicao < 0 || posicao >= TAM)
      return POSICAO_INVALIDA;

  if (vetorPrincipal[posicao] == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

  if (novoTamanho < 1)
      return NOVO_TAMANHO_INVALIDO;

  int *novaEstruturaAuxiliar = (int *)realloc(vetorPrincipal[posicao], novoTamanho * sizeof(int));
  if (novaEstruturaAuxiliar == NULL)
      return SEM_ESPACO_DE_MEMORIA;

  vetorPrincipal[posicao] = novaEstruturaAuxiliar;
  tamanhoEstruturaAuxiliar[posicao] = novoTamanho;

  if (quantidadeElementosEstruturaAuxiliar[posicao] > novoTamanho) {
      quantidadeElementosEstruturaAuxiliar[posicao] = novoTamanho;
  }

  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
  posicao--;

  if (posicao < 0 || posicao >= TAM)
      return POSICAO_INVALIDA;

  if (vetorPrincipal[posicao] == NULL)
      return SEM_ESTRUTURA_AUXILIAR;

  if (quantidadeElementosEstruturaAuxiliar[posicao] == 0)
      return ESTRUTURA_AUXILIAR_VAZIA;

  return quantidadeElementosEstruturaAuxiliar[posicao];
}

void liberarMemoriaEstruturasAuxiliares() {
    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
            quantidadeElementosEstruturaAuxiliar[i] = 0;
            tamanhoEstruturaAuxiliar[i] = 0;
        }
    }
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote() {
    No *cabecote = (No *)malloc(sizeof(No));
    if (cabecote == NULL)
        return NULL;

    cabecote->prox = NULL;
    No *atual = cabecote;
    int encontrouElementos = 0;

    for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL && quantidadeElementosEstruturaAuxiliar[i] > 0) {
            int *estruturaAuxiliar = vetorPrincipal[i];
            for (int j = 0; j < quantidadeElementosEstruturaAuxiliar[i]; j++) {
                No *novoNo = (No *)malloc(sizeof(No));
                if (novoNo == NULL) {
                    // Libera a memória alocada até agora para evitar vazamento
                    destruirListaEncadeadaComCabecote(&cabecote);
                    return NULL;
                }

                novoNo->conteudo = estruturaAuxiliar[j];
                novoNo->prox = NULL;

                atual->prox = novoNo;
                atual = novoNo;

                encontrouElementos = 1;
            }
        }
    }

    if (encontrouElementos)
        return cabecote;
    else {
        free(cabecote);
        return NULL;
    }
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[]) {
    if (inicio == NULL || inicio->prox == NULL) {
        return;
    }

    No *atual = inicio->prox;
    int i = 0;

    while (atual != NULL) {
        vetorAux[i++] = atual->conteudo;
        atual = atual->prox;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio) {
    if (inicio == NULL || *inicio == NULL) {
        return;
    }

    No *atual = *inicio;
    No *proxNo;

    while (atual != NULL) {
        proxNo = atual->prox;
        free(atual);
        atual = proxNo;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
  for (int i = 0; i < TAM; i++) {
      vetorPrincipal[i] = NULL;
      quantidadeElementosEstruturaAuxiliar[i] = 0;
      tamanhoEstruturaAuxiliar[i] = 0;
  }
  }

  // Se existir algum outro vetor ou estrutura que precisa ser inicializado,
  // faça isso aqui. Por exemplo, inicializar o vetor que armazena a quantidade
  // de elementos em cada estrutura auxiliar.
 

  // Se houver outras estruturas globais, como listas encadeadas, inicialize-as
  // aqui, se necessário.


/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
  liberarMemoriaEstruturasAuxiliares();
    }
  

  // Se houver outras estruturas globais que precisem ser liberadas, faça isso
  // aqui. Por exemplo, listas encadeadas ou outras alocações dinâmicas
  // realizadas no programa.

