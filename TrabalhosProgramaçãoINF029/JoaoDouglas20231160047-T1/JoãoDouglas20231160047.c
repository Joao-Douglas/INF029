// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo contém as implementações das questões do trabalho do
//  aluno. Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c O aluno
//  deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:Joao Douglas
//  email:Joaodouglas-09@hotmail.com
//  Matrícula:20231160047
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "JoãoDouglas20231160047.h" // Substitua pelo seu arquivo de header renomeado
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <wchar.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  return soma;
}

int diasNoMes(int mes, int ano) {
  switch (mes) {
  case 1:  // Janeiro
  case 3:  // Março
  case 5:  // Maio
  case 7:  // Julho
  case 8:  // Agosto
  case 10: // Outubro
  case 12: // Dezembro
    return 31;
  case 4:  // Abril
  case 6:  // Junho
  case 9:  // Setembro
  case 11: // Novembro
    return 30;
  case 2: // Fevereiro
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
      return 29; // Ano bissexto
    } else {
      return 28;
    }
  default:
    return -1; // Mês inválido
  }
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}

int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[]) {
  DataQuebrada dq = quebraData(data);
  if (!dq.valido) {
    return 0; // Retorna 0 se a data é inválida
  }

  // Verifica se o mês está dentro do intervalo de 1 a 12
  if (dq.iMes < 1 || dq.iMes > 12) {
    return 0; // Retorna 0 se o mês é inválido
  }

  // Verifica se o dia está dentro do intervalo correspondente ao mês
  int diasNoMes;
  if (dq.iMes == 2) {
    // Fevereiro - Verifica se é bissexto
    diasNoMes = (dq.iAno % 400 == 0 || (dq.iAno % 4 == 0 && dq.iAno % 100 != 0))
                    ? 29
                    : 28;
  } else if (dq.iMes == 4 || dq.iMes == 6 || dq.iMes == 9 || dq.iMes == 11) {
    // Abril, Junho, Setembro, Novembro
    diasNoMes = 30;
  } else {
    // Outros meses
    diasNoMes = 31;
  }

  if (dq.iDia < 1 || dq.iDia > diasNoMes) {
    return 0; // Retorna 0 se o dia é inválido
  }

  return 1; // Retorna 1 se a data é válida
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[]) {

  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;

  if (q1(datainicial) == 0) {
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    dma.retorno = 3;
    return dma;
  } else {
    // verifique se a data final não é menor que a data inicial
    DataQuebrada dataQuebrada = quebraData(datainicial);
    DataQuebrada dataQuebrada2 = quebraData(datafinal);
    if (dataQuebrada.iAno > dataQuebrada2.iAno) {
      dma.retorno = 4;
      return dma;
    } else if (dataQuebrada.iAno == dataQuebrada2.iAno) {
      if (dataQuebrada.iMes > dataQuebrada2.iMes) {
        dma.retorno = 4;
        return dma;
      } else if (dataQuebrada.iMes == dataQuebrada2.iMes) {
        if (dataQuebrada.iDia > dataQuebrada2.iDia) {
          dma.retorno = 4;
          return dma;
        }
      }
    }
    // calcule a distancia entre as datas
    dma.qtdAnos = dataQuebrada2.iAno - dataQuebrada.iAno;
    dma.qtdMeses = dataQuebrada2.iMes - dataQuebrada.iMes;
    dma.qtdDias = dataQuebrada2.iDia - dataQuebrada.iDia;
    if (dma.qtdDias < 0) {
      dma.qtdDias = dma.qtdDias * -1;
    } else if (dma.qtdMeses < 0) {
      dma.qtdMeses = dma.qtdMeses * -1;
    } else if (dma.qtdAnos < 0) {
      dma.qtdAnos = dma.qtdAnos * -1;
    }

    // se tudo der certo
    dma.retorno = 1;
    return dma;
  }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = 0;
  char copia[1000];
  strcpy(copia, texto);
  for (int i = 0; i < strlen(texto); i++) {
    if (isCaseSensitive != 1) {
      char Maior = c - 32;
      char Menor = c + 32;
      if (texto[i] == c || texto[i] == Maior || texto[i] == Menor) {
        qtdOcorrencias++;
      }
    } else {
      char Maior = c - 32;
      char Menor = c + 32;
      if (texto[i] == Maior && c == Maior) {
        qtdOcorrencias++;
      } else if (texto[i] == Menor && c == Menor) {
        qtdOcorrencias++;
      }
    }
  }
  return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */
int q4(wchar_t *strTexto, wchar_t *strBusca, int posicoes[], int max_posicoes) {
  // Verifica se strBusca é uma string vazia
  if (wcslen(strBusca) == 0) {
    printf("Erro: A string de busca está vazia.\n");
    return -1; // Retorna um valor de erro
  }

  // Verifica se strTexto é uma string vazia
  if (wcslen(strTexto) == 0) {
    printf("Erro: A string de texto está vazia.\n");
    return -1; // Retorna um valor de erro
  }

  int qtdOcorrencias = 0;
  int tamanho_strTexto = wcslen(strTexto);
  int tamanho_strBusca = wcslen(strBusca);

  // Itera sobre os caracteres de strTexto
  for (int i = 0; i < tamanho_strTexto; i++) {
    if(strTexto[i] == -61){
      int num = strTexto[i+1];
      num = -num;
      strTexto[i+1] = num;
      strTexto[i] = strTexto[i+1];
    }
    // Se o caractere atual de strTexto for igual ao primeiro caractere de
    // strBusca
    if (strTexto[i] == strBusca[0]) {
      int j;
      // Verifica se os caracteres subsequentes também correspondem a strBusca
      for (j = 1; j < tamanho_strBusca; j++) {
        if (strTexto[i + j] != strBusca[j]) {
          break;
        }
      }
      // Se todos os caracteres correspondem, incrementa o contador e armazena
      // as posições
      if (j == tamanho_strBusca) {
        if (qtdOcorrencias * 2 >= max_posicoes) {
          printf("Erro: O array de posições é muito pequeno.\n");
          return -1; // Retorna um valor de erro
        }
        posicoes[qtdOcorrencias * 2] = i + 1;
        posicoes[qtdOcorrencias * 2 + 1] = (i + tamanho_strBusca - 1) + 1;
        qtdOcorrencias++;
      }
    }
  }

  return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num) {
  int invertido = 0;

  // Enquanto o número original for maior que zero
  while (num > 0) {
    // Obtém o último dígito do número original
    int digito = num % 10;

    // Adiciona o último dígito ao número invertido
    invertido = invertido * 10 + digito;

    // Remove o último dígito do número original
    num /= 10;
  }

  return invertido;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {
  // Convertendo os números em strings
  char strNumerobase[20];
  char strNumerobusca[20];
  sprintf(strNumerobase, "%d", numerobase);
  sprintf(strNumerobusca, "%d", numerobusca);

  int tamBase = strlen(strNumerobase);
  int tamBusca = strlen(strNumerobusca);
  int qtdOcorrencias = 0;

  // Percorre cada dígito do número base
  for (int i = 0; i <= tamBase - tamBusca; i++) {
    // Verifica se o segmento de dígitos é igual ao número de busca
    if (strncmp(&strNumerobase[i], strNumerobusca, tamBusca) == 0) {
      qtdOcorrencias++;
    }
  }

  return qtdOcorrencias;
}

DataQuebrada quebraData(char data[]) {
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno);

  dq.valido = 1;

  return dq;
}
