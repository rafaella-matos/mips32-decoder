#include "tipos_comuns.h"

#ifndef DECODIFICADOR_R_H_INCLUDED
#define DECODIFICADOR_R_H_INCLUDED

Assembly _comando_r(int opcode[6], int shamt[5], int funct[6], int rd[5], int rs[5], int rt[5]);
Assembly _add(char* linha);
Assembly _and(char* linha);
Assembly _nor(char* linha);
Assembly _or(char* linha);
Assembly _slt(char* linha);
Assembly _sub(char* linha);
Assembly _xor(char* linha);
Assembly _sll(char* linha);
Assembly _srl(char* linha);
Assembly _div(char* linha);
Assembly _mult(char* linha);
Assembly _jr(char* linha);

#endif // DECODIFICADOR_R_H_INCLUDED
