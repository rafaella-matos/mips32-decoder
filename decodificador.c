#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decodificador.h"
#include "apoio.h"

// decodifica uma linha gen�rica
assembly decodificar(char* linha)
{
    // a
    if (linha[0] == 'a')
    {
        if (linha[1] == 'd' && linha[3] == ' ') return _add(linha);
        else if (linha[1] == 'd' && linha[3] == 'i') return _addi(linha);
        else if (linha[1] == 'n' && linha[3] == ' ') return _and(linha);
        else if (linha[1] == 'n' && linha[3] == 'i') return _andi(linha);
    }

    // n
    if (linha[0] == 'n') return _nor(linha);

    // o
    if (linha[0] == 'o' && linha[2] == ' ') return _or(linha);
    else if (linha[0] == 'o' && linha[2] == 'i') return _ori(linha);

    // s
    if (linha[0] == 's' && linha[1] == 'l' && linha[2] == 't' && linha[3] == ' ') return _slt(linha);
    else if (linha[0] == 's' && linha[1] == 'l' && linha[2] == 't' && linha[3] == 'i') return _slti(linha);
    else if (linha[0] == 's' && linha[1] == 'u') return _sub(linha);
    else if (linha[0] == 's' && linha[1] == 'l' && linha[2] == 'l' && linha[3] == ' ') return _sll(linha);
    else if (linha[0] == 's' && linha[1] == 'r' && linha[2] == 'l' && linha[3] == ' ') return _srl(linha);
    else if (linha[0] == 's' && linha[1] == 'w') return _sw(linha);

    // x
    if (linha[0] == 'x') return _xor(linha);

    // d
    if (linha[0] == 'd') return _div(linha);

    // m
    if (linha[0] == 'm') return _mult(linha);

    // b
    if (linha[0] == 'b' && linha[1] == 'e') return _beq(linha);
    else if (linha[0] == 'b' && linha[1] == 'n') return _bne(linha);

    // j
    if (linha[0] == 'j' && linha[1] == ' ') return _j(linha);
    else if (linha[0] == 'j' && linha[1] == 'a') return _jal(linha);
    else if (linha[0] == 'j' && linha[1] == 'r') return _jr(linha);

    // l
    if (linha[0] == 'l' && linha[1] == 'w') return _lw(linha);

    printf("Oops, comando invalido!");

    assembly x = { };
    return x;
}

assembly _comando_i(int opcode[6], int funct[6], int rs[5], int rt[5], int imm[16], char* linha)
{
    assembly retorno;
    retorno.tipo = 'I';
    retorno.linha = linha;

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

assembly _comando_j(int opcode[6], int jump[26], char* linha)
{
    assembly retorno;
    retorno.tipo = 'J';
    retorno.linha = linha;

    int padding = 0;
    int i = 0;

    // debug - "limpa" o array todo "2" (valor impossivel)
    for(i = 0; i < 32; i++) retorno.binario[i] = 2;

    // opcode
    for(i = 0; i < 6; i++) retorno.binario[padding + i] = opcode[i];
    printf("\nopcode: ");for(i = 0; i<5;i++)printf("%d", opcode[i]);
    padding += 6;

    // jump
    for(i = 0; i < 26; i++) retorno.binario[padding + i] = jump[i];
    printf("\njump: ");for(i = 0; i<26;i++)printf("%d", jump[i]);
    padding += 26;

    return retorno;
}

assembly _addi(char* linha)
{
    int length = strlen(linha) - 5;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 5];
    }
    temp[length] = 0;

    int rt[5];
    registrador(strtok(temp, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    assembly retorno = _comando_i(comandos.addi.opcode, comandos.addi.funct, rs, rt, imm, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _andi(char* linha)
{
    int length = strlen(linha) - 5;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 5];
    }
    temp[length] = 0;

    int rt[5];
    registrador(strtok(temp, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[5];
    immediate(strtok(NULL, ","), imm);

    assembly retorno = _comando_i(comandos.andi.opcode, comandos.andi.funct, rs, rt, imm, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _ori(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rt[5];
    registrador(strtok(temp, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    assembly retorno = _comando_i(comandos.ori.opcode, comandos.ori.funct, rs, rt, imm, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _slti(char* linha)
{
    int length = strlen(linha) - 5;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 5];
    }
    temp[length] = 0;

    int rt[5];
    registrador(strtok(temp, ","), rt);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    assembly retorno = _comando_i(comandos.slti.opcode, comandos.slti.funct, rs, rt, imm, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _beq(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rs[5];
    registrador(strtok(temp, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    assembly retorno = _comando_i(comandos.beq.opcode, comandos.beq.funct, rs, rt, imm, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _bne(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rs[5];
    registrador(strtok(temp, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int imm[16];
    immediate(strtok(NULL, ","), imm);

    assembly retorno = _comando_i(comandos.bne.opcode, comandos.bne.funct, rs, rt, imm, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _j(char* linha)
{
    int length = strlen(linha) - 2;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 2];
    }
    temp[length] = 0;

    int target[26];
    jump(temp, target);

    assembly retorno = _comando_j(comandos.j.opcode, target, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _jal(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int target[26];
    jump(temp, target);

    assembly retorno = _comando_j(comandos.jal.opcode, target, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _lw(char* linha)
{
    int length = strlen(linha) - 3;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 3];
    }
    temp[length] = 0;

    int rt[5];
    registrador(strtok(temp, ","), rt);

    int offset[16];
    immediate(strtok(NULL, "("), offset);

    int rs[5];
    registrador(strtok(NULL, ")"), rs);

    assembly retorno = _comando_i(comandos.lw.opcode, comandos.lw.funct, rs, rt, offset, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _sw(char* linha)
{
    int length = strlen(linha) - 3;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 3];
    }
    temp[length] = 0;

    int rt[5];
    registrador(strtok(temp, ","), rt);

    int offset[16];
    immediate(strtok(NULL, "("), offset);

    int rs[5];
    registrador(strtok(NULL, ")"), rs);

    assembly retorno = _comando_i(comandos.sw.opcode, comandos.sw.funct, rs, rt, offset, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}
