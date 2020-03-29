#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "decodificador.h"
#include "decodificador_r.h"
#include "decodificador_i.h"
#include "decodificador_j.h"
#include "apoio.h"
#include "tipos_comuns.h"

/******************************************************************************/
Assembly decodificar(char* linha)
{
    // Cria duas cópias: uma para verificar o comando e outra para o comando em si.
    // Isso porque 'strtok' altera a string...
    char copia1[strlen(linha)];
    char copia2[strlen(linha)];
    for(int i = 0; i < strlen(linha); i++)
    {
        copia1[i] = linha[i];
        copia2[i] = linha[i];
    }
    char* tokenComando = strtok(copia1, " ");

         if (strcmp(tokenComando, comandos.add.prefixo) == 0)  return _add(copia2);
    else if (strcmp(tokenComando, comandos.addi.prefixo) == 0) return _addi(copia2);
    else if (strcmp(tokenComando, comandos.and.prefixo) == 0)  return _and(copia2);
    else if (strcmp(tokenComando, comandos.andi.prefixo) == 0) return _andi(copia2);
    else if (strcmp(tokenComando, comandos.nor.prefixo) == 0)  return _nor(copia2);
    else if (strcmp(tokenComando, comandos.or.prefixo) == 0)   return _or(copia2);
    else if (strcmp(tokenComando, comandos.ori.prefixo) == 0)  return _ori(copia2);
    else if (strcmp(tokenComando, comandos.slt.prefixo) == 0)  return _slt(copia2);
    else if (strcmp(tokenComando, comandos.slti.prefixo) == 0) return _slti(copia2);
    else if (strcmp(tokenComando, comandos.sub.prefixo) == 0)  return _sub(copia2);
    else if (strcmp(tokenComando, comandos.sll.prefixo) == 0)  return _sll(copia2);
    else if (strcmp(tokenComando, comandos.srl.prefixo) == 0)  return _srl(copia2);
    else if (strcmp(tokenComando, comandos.sw.prefixo) == 0)   return _sw(copia2);
    else if (strcmp(tokenComando, comandos.xor.prefixo) == 0)  return _xor(copia2);
    else if (strcmp(tokenComando, comandos.div.prefixo) == 0)  return _div(copia2);
    else if (strcmp(tokenComando, comandos.mult.prefixo) == 0) return _mult(copia2);
    else if (strcmp(tokenComando, comandos.beq.prefixo) == 0)  return _beq(copia2);
    else if (strcmp(tokenComando, comandos.bne.prefixo) == 0)  return _bne(copia2);
    else if (strcmp(tokenComando, comandos.j.prefixo) == 0)    return _j(copia2);
    else if (strcmp(tokenComando, comandos.jal.prefixo) == 0)  return _jal(copia2);
    else if (strcmp(tokenComando, comandos.jr.prefixo) == 0)   return _jr(copia2);
    else if (strcmp(tokenComando, comandos.lw.prefixo) == 0)   return _lw(copia2);

    else
    {
        printf("O comando informado não é válido");
        Assembly retornoVazio = {};
        return retornoVazio;
    }
}
