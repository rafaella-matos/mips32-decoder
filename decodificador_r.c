#include "tipos_comuns.h"
#include "apoio.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Assembly _comando_r(int opcode[6], int shamt[5], int funct[6], int rd[5], int rs[5], int rt[5])
{
    Assembly retorno;
    retorno.tipo = 'R';

    int padding = 0;
    int i = 0;

    // debug - "limpa" o array todo "2" (valor impossivel)
    for(i = 0; i < 32; i++) retorno.binario[i] = 2;

    // opcode
    for(i = 0; i < 6; i++) retorno.binario[padding + i] = opcode[i];
    //printf("\nopcode: ");for(i = 0; i<5;i++)printf("%d", opcode[i]);
    padding += 6;

    // rs
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = rs[i];
    //printf("\nrs: ");for(i = 0; i<5;i++)printf("%d", rs[i]);
    padding += 5;

    // rt
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = rt[i];
    //printf("\nrt: ");for(i = 0; i<5;i++)printf("%d", rt[i]);
    padding += 5;

    // rd
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = rd[i];
    //printf("\nrd: ");for(i = 0; i<5;i++)printf("%d", rd[i]);
    padding += 5;

    // shamt
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = shamt[i];
    //printf("\nshamt: ");for(i = 0; i<5;i++)printf("%d", shamt[i]);
    padding += 5;

    // funct
    for(i = 0; i < 6; i++) retorno.binario[padding + i] = funct[i];
    //printf("\nfunct: ");for(i =0; i<5;i++)printf("%d", funct[i]);

    return retorno;
}

Assembly _add(char* linha)
{
    int i;
    strtok(linha, " ");

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.add.opcode, shamt, comandos.add.funct, rd, rs, rt);

    // log - debug
    //printf("\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _and(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.and.opcode, shamt, comandos.and.funct, rd, rs, rt);

    // log - debug
    //printf("\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _nor(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.nor.opcode, shamt, comandos.nor.funct, rd, rs, rt);

    // log - debug
    //printf("\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _or(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.or.opcode, shamt, comandos.or.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _slt(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.slt.opcode, shamt, comandos.slt.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}
Assembly _sub(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.sub.opcode, shamt, comandos.sub.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _xor(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.xor.opcode, shamt, comandos.xor.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _sll(char* linha)
{
    strtok(linha, " ");
    int i;

    int rs[5] = { 0, 0, 0, 0, 0 };

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int sa[5];
    binario5(atoi(strtok(NULL, ",")), sa);

    Assembly retorno = _comando_r(comandos.sll.opcode, sa, comandos.sll.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}
Assembly _srl(char* linha)
{
    strtok(linha, " ");
    int i;

    int rs[5] = { 0, 0, 0, 0, 0 };

    int rd[5];
    registrador(strtok(NULL, ","), rd);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int sa[5];
    binario5(atoi(strtok(NULL, ",")), sa);

    Assembly retorno = _comando_r(comandos.srl.opcode, sa, comandos.srl.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _div(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5] = { 0, 0, 0, 0, 0 };

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.div.opcode, shamt, comandos.div.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _mult(char* linha)
{
    int i;
    strtok(linha, " ");

    int rd[5] = { 0, 0, 0, 0, 0 };

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.div.opcode, shamt, comandos.div.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}

Assembly _jr(char* linha)
{
    strtok(linha, " ");
    int i;

    int rd[5] = { 0, 0, 0, 0, 0 };

    int rs[5];
    registrador(linha, rs);

    int rt[5] = { 0, 0, 0, 0, 0 };

    int shamt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    Assembly retorno = _comando_r(comandos.jr.opcode, shamt, comandos.jr.funct, rd, rs, rt);

    // log - debug
    //printf("\n\n--------------\n");
    //for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    //printf("\n--------------\n\n");

    return retorno;
}
