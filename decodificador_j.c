#include "tipos_comuns.h"
#include "apoio.h"
#include <string.h>
#include <stdio.h>

Assembly _comando_j(int opcode[6], int jump[26], char* linha)
{
    Assembly retorno;
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

/******************************************************************************/
Assembly _j(char* linha)
{
    strtok(linha, " ");
    int i;

    int target[26];
    char* token = strtok(NULL, ":\0");
    token[strlen(token) - 1] = '\0';
    jump(token, target);

    Assembly retorno = _comando_j(comandos.j.opcode, target, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}

/******************************************************************************/
Assembly _jal(char* linha)
{
    strtok(linha, " ");
    int i;

    int target[26];
    char* token = strtok(NULL, ":\0");
    token[strlen(token) - 1] = '\0';
    jump(token, target);

    Assembly retorno = _comando_j(comandos.jal.opcode, target, linha);

    // log - debug
    printf("\n\n--------------\n");
    printf("%s\n", linha);
    for(i = 0; i < 32; i++)
        printf("%d", retorno.binario[i]);
    printf("\n--------------\n\n");

    return retorno;
}
