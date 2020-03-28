#include "decodificador_r.h"

assembly _comando_r(int opcode[6], int shamt[5], int funct[6], int rd[5], int rs[5], int rt[5], char* linha)
{
    assembly retorno;
    retorno.tipo = 'R';
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

    // rd
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = rd[i];
    printf("\nrd: ");for(i = 0; i<5;i++)printf("%d", rd[i]);
    padding += 5;

    // shamt
    for(i = 0; i < 5; i++) retorno.binario[padding + i] = shamt[i];
    printf("\nshamt: ");for(i = 0; i<5;i++)printf("%d", shamt[i]);
    padding += 5;

    // funct
    for(i = 0; i < 6; i++) retorno.binario[padding + i] = funct[i];
    printf("\nfunct: ");for(i =0; i<5;i++)printf("%d", funct[i]);

    return retorno;
}

assembly _add(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.add.opcode, shamt, comandos.add.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _and(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.and.opcode, shamt, comandos.and.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _nor(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.nor.opcode, shamt, comandos.nor.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _or(char* linha)
{
    int length = strlen(linha) - 3;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 3];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.or.opcode, shamt, comandos.or.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _slt(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.slt.opcode, shamt, comandos.slt.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}
assembly _sub(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.sub.opcode, shamt, comandos.sub.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _xor(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[5] = { 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.xor.opcode, shamt, comandos.xor.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _sll(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rs[5] = { 0, 0, 0, 0, 0 };

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int sa[5];
    binario5(atoi(strtok(NULL, ",")), sa);

    assembly retorno = _comando_r(comandos.sll.opcode, sa, comandos.sll.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}
assembly _srl(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rs[5] = { 0, 0, 0, 0, 0 };

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int sa[5];
    binario5(atoi(strtok(NULL, ",")), sa);

    assembly retorno = _comando_r(comandos.srl.opcode, sa, comandos.srl.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _div(char* linha)
{
    int length = strlen(linha) - 4;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 4];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.div.opcode, shamt, comandos.div.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _mult(char* linha)
{
    int length = strlen(linha) - 5;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 5];
    }
    temp[length] = 0;

    int rd[5];
    registrador(strtok(temp, ","), rd);

    int rs[5];
    registrador(strtok(NULL, ","), rs);

    int rt[5];
    registrador(strtok(NULL, ","), rt);

    int shamt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.div.opcode, shamt, comandos.div.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

assembly _jr(char* linha)
{
    int length = strlen(linha) - 3;
    char temp[length + 1];
    int i;
    for(i = 0; i < length; i++)
    {
        temp[i] = linha[i + 3];
    }
    temp[length] = 0;

    int rd[5] = { 0, 0, 0, 0, 0 };

    int rs[5];
    registrador(temp, rs);

    int rt[5] = { 0, 0, 0, 0, 0 };

    int shamt[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    assembly retorno = _comando_r(comandos.jr.opcode, shamt, comandos.jr.funct, rd, rs, rt, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++) printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}
