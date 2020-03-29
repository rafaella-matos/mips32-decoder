#include "tipos_comuns.h"

#ifndef APOIO_H_INCLUDED
#define APOIO_H_INCLUDED

/***************************************************************************
 * Transforma um numero inteiro em binário
 *
 * @param valor O valor inteiro para conversão
 * @param vetor O vetor para receber a representação
 ***************************************************************************/
void binario(int valor, int vetor[8]);

/***************************************************************************
 * Transforma um número inteiro em binário truncado em 5 posições
 *
 * @param valor O valor inteiro para conversão
 * @param vetor O vetor para receber a representação
 ***************************************************************************/
void binario5(int valor, int vetor[5]);

/***************************************************************************
 * Obtém a representação em binário para o valor literal de um registrador
 *
 * @param valor O valor literal (string) do registrador
 * @param vetor O vetor para receber a representação
 ***************************************************************************/
void registrador(char* valor, int vetor[5]);

/***************************************************************************
 * Obtém a representação em binário para o valor imediato
 *
 * @param valor O valor literal (string) para conversão
 * @param vetor O vetor para receber a representação
 ***************************************************************************/
void immediate(char* valor, int vetor[16]);

/***************************************************************************
 * Obtém a representação em binário para o valor de pulo
 *
 * @param valor O valor literal (string) para conversão
 * @param vetor O vetor para receber a representação
 ***************************************************************************/
void jump(char* valor, int vetor[26]);

#endif // APOIO_H_INCLUDED
