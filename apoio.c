#include <string.h>
#include <stdlib.h>
#include "apoio.h"

struct Comandos comandos = {
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0 } }, // add
    { { 0, 0, 1, 0, 0, 0 }, { } }, // addi
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 0, 0 } }, // and
    { { 0, 0, 1, 1, 0, 0 }, { } }, // andi
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 1 } }, // nor
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 0, 1 } }, // or
    { { 0, 0, 1, 1, 0, 1 }, { } }, // ori
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 1, 0, 1, 0 } }, // slt
    { { 0, 0, 1, 0, 1, 0 }, { } }, // slti
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 1, 0 } }, // sub
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 0 } }, // xor
    { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } }, // sll
    { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0 } }, // srl
    { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 1, 0 } }, // div
    { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 0, 0 } }, // mult
    { { 0, 0, 0, 1, 0, 0 }, { } }, // beq
    { { 0, 0, 0, 1, 0, 1 }, { } }, // bne
    { { 0, 0, 0, 0, 1, 0 }, { } }, // j
    { { 0, 0, 0, 0, 1, 1 }, { } }, // jal
    { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0 } }, // jr
    { { 1, 0, 0, 0, 1, 1 }, { } }, // lw
    { { 1, 0, 1, 0, 1, 1 }, { } }, // sw
};

// transforma um numero decimal em binario
void binario(int valor, int retorno[8])
{
    int i;
    for(i = 7; i >= 0; i--)
    {
        if (valor % 2 == 0) retorno[i] = 0;
        else retorno[i] = 1;

        valor = valor / 2;
    }
}

// trunca o valor binario normal para caber em 5 posicoes
void binario5(int valor, int retorno[5])
{
    int bin[8];
    binario(valor, bin);

    int i;
    for(i = 3; i < 8; i++) retorno[i - 3] = bin[i];
}
// calcula o valor binario (truncado em 5) para o registrador
void registrador(char* valor, int retorno[5])
{
    if (strcmp(valor, "$zero") == 0) binario5(0, retorno);

    else if (strcmp(valor, "$at") == 0) binario5(1, retorno);

    else if (strcmp(valor, "$v0") == 0) binario5(2, retorno);
    else if (strcmp(valor, "$v1") == 0) binario5(3, retorno);

    else if (strcmp(valor, "$a0") == 0) binario5(4, retorno);
    else if (strcmp(valor, "$a1") == 0) binario5(5, retorno);
    else if (strcmp(valor, "$a2") == 0) binario5(6, retorno);
    else if (strcmp(valor, "$a3") == 0) binario5(7, retorno);

    else if (strcmp(valor, "$t0") == 0) binario5(8, retorno);
    else if (strcmp(valor, "$t1") == 0) binario5(9, retorno);
    else if (strcmp(valor, "$t2") == 0) binario5(10, retorno);
    else if (strcmp(valor, "$t3") == 0) binario5(11, retorno);
    else if (strcmp(valor, "$t4") == 0) binario5(12, retorno);
    else if (strcmp(valor, "$t5") == 0) binario5(13, retorno);
    else if (strcmp(valor, "$t6") == 0) binario5(14, retorno);
    else if (strcmp(valor, "$t7") == 0) binario5(15, retorno);

    else if (strcmp(valor, "$s0") == 0) binario5(16, retorno);
    else if (strcmp(valor, "$s1") == 0) binario5(17, retorno);
    else if (strcmp(valor, "$s2") == 0) binario5(18, retorno);
    else if (strcmp(valor, "$s3") == 0) binario5(19, retorno);
    else if (strcmp(valor, "$s4") == 0) binario5(20, retorno);
    else if (strcmp(valor, "$s5") == 0) binario5(21, retorno);
    else if (strcmp(valor, "$s6") == 0) binario5(22, retorno);
    else if (strcmp(valor, "$s7") == 0) binario5(23, retorno);

    else binario5(255, retorno);
}

// calcula o valor binario para a constante imediata
void immediate(char* valor, int retorno[16])
{
    // transforma o valor "string" em um numero (short)
    char* pEnd;
    long numero = strtol(valor, &pEnd, 10);

    // transforma o numero em string binario
    char binarioTemp[16];
    ltoa(numero, binarioTemp, 2);

    // converte posicao a posicao a string binaria em um array de inteiro
    int i;
    for(i = 0; i < 16; i++) retorno[i] = binarioTemp[i] - 48;
}

// calcula o valor binario para a constante imediata
void jump(char* valor, int retorno[26])
{
    // transforma o valor "string" em um numero (short)
    char* pEnd;
    long long numero = (long long)strtoul(valor, &pEnd, 10);

    // transforma o numero em string binario
    char binarioTemp[32];

    lltoa(numero, binarioTemp, 2);

    // converte posicao a posicao a string binaria em um array de inteiro
    int i;
    for(i = 0; i < 26; i++) retorno[i] = binarioTemp[i] - 48;
}
