#include "apoio.h"

static const containerComandos comandos = {
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 0, 0 } },
    { { 0, 0, 1, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 0, 0 } },
    { { 0, 0, 1, 1, 0, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 1 } },
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 0, 1 } },
    { { 0, 0, 1, 1, 0, 1 } },
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 1, 0, 1, 0 } },
    { { 0, 0, 1, 0, 1, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 0, 1, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 1, 0, 0, 1, 1, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 1, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 1, 0 } },
    { { 0, 0, 0, 0, 0, 0 }, { 0, 1, 1, 0, 0, 0 } },
    { { 0, 0, 0, 1, 0, 0 } },
    { { 0, 0, 0, 1, 0, 1 } },
    { { 0, 0, 0, 0, 1, 0 } },
    { { 0, 0, 0, 0, 1, 1 } },
    { { 0, 0, 0, 0, 0, 0 }, { 0, 0, 1, 0, 0, 0 } },
    { { 1, 0, 0, 0, 1, 1 } },
    { { 1, 0, 1, 0, 1, 1 } },
};

// transforma um numero decimal em binario
int* binario(int valor)
{
    static int retorno[8];
    int i;
    for(i = 7; i >= 0; i--)
    {
        if (valor % 2 == 0) retorno[i] = 0;
        else retorno[i] = 1;

        valor = valor / 2;
    }

    return retorno;
}

// trunca o valor binario normal para caber em 5 posicoes
int* binario5(int* valor)
{
    int* bin = binario(valor);

    static int retorno[5];
    int i;
    for(i = 3; i < 8; i++) retorno[i - 3] = bin[i];
    return retorno;
}

// calcula o valor binario (truncado em 5) para o registrador
int* registrador(char* valor)
{
    if (strcmp(valor, "$zero") == 0) return binario5(0);

    else if (strcmp(valor, "$at") == 0) return binario5(1);

    else if (strcmp(valor, "$v0") == 0) return binario5(2);
    else if (strcmp(valor, "$v1") == 0) return binario5(3);

    else if (strcmp(valor, "$a0") == 0) return binario5(4);
    else if (strcmp(valor, "$a1") == 0) return binario5(5);
    else if (strcmp(valor, "$a2") == 0) return binario5(6);
    else if (strcmp(valor, "$a3") == 0) return binario5(7);

    else if (strcmp(valor, "$t0") == 0) return binario5(8);
    else if (strcmp(valor, "$t1") == 0) return binario5(9);
    else if (strcmp(valor, "$t2") == 0) return binario5(10);
    else if (strcmp(valor, "$t3") == 0) return binario5(11);
    else if (strcmp(valor, "$t4") == 0) return binario5(12);
    else if (strcmp(valor, "$t5") == 0) return binario5(13);
    else if (strcmp(valor, "$t6") == 0) return binario5(14);
    else if (strcmp(valor, "$t7") == 0) return binario5(15);

    else if (strcmp(valor, "$s0") == 0) return binario5(16);
    else if (strcmp(valor, "$s1") == 0) return binario5(17);
    else if (strcmp(valor, "$s2") == 0) return binario5(18);
    else if (strcmp(valor, "$s3") == 0) return binario5(19);
    else if (strcmp(valor, "$s4") == 0) return binario5(20);
    else if (strcmp(valor, "$s5") == 0) return binario5(21);
    else if (strcmp(valor, "$s6") == 0) return binario5(22);
    else if (strcmp(valor, "$s7") == 0) return binario5(23);

    else return binario5(255);
}

// calcula o valor binario para a constante imediata
int* immediate(unsigned short valor)
{
    static int retorno[16];
    int i;
    for(i = 15; i >= 0; i--)
    {
        if (valor % 2 == 0) retorno[i] = 0;
        else retorno[i] = 1;
        printf("I - %d: %d\n", i, retorno[i]);

        valor = valor / 2;
    }
    return retorno;
}
