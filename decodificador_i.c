#include "tipos_comuns.h"
#include "apoio.h"
#include <string.h>
#include <stdio.h>

Assembly _comando_i(int opcode[6], int funct[6], int rs[5], int rt[5], int imm[16])
{
    Assembly retorno;
    retorno.tipo = 'I';

    int padding = 0;
    int i = 0;

    // debug - "limpa" o array todo "2" (valor impossivel)
    for(i = 0; i < 32; i++) retorno.binario[i] = 2;

    // opcode
    for(i = 0; i < 6; i++) retorno.binario[padding + i] = opcode[i];
    printf("\nopcode: ");for(i = 0; i<5;i++)printf("%d", opcode[i]);
    padding += 6;

    // rs
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = rs[i];
    printf("\nrs: ");for(i = 0; i<5;i++)printf("%d", rs[i]);
    padding += 5;

    // rt
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = rt[i];
    printf("\nrt: ");for(i = 0; i<5;i++)printf("%d", rt[i]);
    padding += 5;

    // imm
    for(i = 0; i < 16; i++) retorno.binario[padding + i] = imm[i];
    printf("\nimm: ");for(i = 0; i<16;i++)printf("%d", imm[i]);
    padding += 16;

    return retorno;
}

/******************************************************************************/
Assembly _addi(char* linha)
{
    strtok(linha, " ");
    int i;

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    Assembly retorno = _comando_i(comandos.addi.opcode, comandos.addi.funct, rs, rt, imm);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

/******************************************************************************/
Assembly _andi(char* linha)
{
    strtok(linha, " ");
    int i;

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[5];
    immediate(strtok(NULL, ","), imm);

    Assembly retorno = _comando_i(comandos.andi.opcode, comandos.andi.funct, rs, rt, imm);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

/******************************************************************************/
Assembly _ori(char* linha)
{
    strtok(linha, " ");
    int i;

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    Assembly retorno = _comando_i(comandos.ori.opcode, comandos.ori.funct, rs, rt, imm);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

/******************************************************************************/
Assembly _slti(char* linha)
{
    strtok(linha, " ");
    int i;

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    Assembly retorno = _comando_i(comandos.slti.opcode, comandos.slti.funct, rs, rt, imm);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

/******************************************************************************/
Assembly _beq(char* linha)
{
    strtok(linha, " ");
    int i;

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int imm[16];
    immediate(strtok(NULL, ","), imm);



    Assembly retorno = _comando_i(comandos.beq.opcode, comandos.beq.funct, rs, rt, imm);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

/******************************************************************************/
Assembly _bne(char* linha)
{
    strtok(linha, " ");
    int i;

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    Assembly retorno = _comando_i(comandos.bne.opcode, comandos.bne.funct, rs, rt, imm);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");



    return retorno;
}

/******************************************************************************/
Assembly _lw(char* linha)
{
    strtok(linha, " ");
    int i;

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int offset[16];
    immediate(strtok(NULL, "("), offset);

    int rs[5];
    registrador(strtok(NULL, ")"), rs);

    Assembly retorno = _comando_i(comandos.lw.opcode, comandos.lw.funct, rs, rt, offset);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

/******************************************************************************/
Assembly _sw(char* linha)
{
    strtok(linha, " ");
    int i;

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int offset[16];
    immediate(strtok(NULL, "("), offset);

    int rs[5];
    registrador(strtok(NULL, ")"), rs);

    Assembly retorno = _comando_i(comandos.sw.opcode, comandos.sw.funct, rs, rt, offset);

    // log - debug
    printf("\n\n--------------\n");
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}
