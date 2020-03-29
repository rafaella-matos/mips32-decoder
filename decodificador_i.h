#include "tipos_comuns.h"

#ifndef DECODIFICADOR_I_H_INCLUDED
#define DECODIFICADOR_I_H_INCLUDED

Assembly _comando_i(int opcode[6], int funct[6], int rs[5], int rt[5], int imm[16], char* linha);
Assembly _addi(char* linha);
Assembly _andi(char* linha);
Assembly _ori(char* linha);
Assembly _slti(char* linha);
Assembly _beq(char* linha);
Assembly _bne(char* linha);
Assembly _lw(char* linha);
Assembly _sw(char* linha);

#endif // DECODIFICADOR_I_H_INCLUDED
