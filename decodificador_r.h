#ifndef DECODIFICADOR_R_H_INCLUDED
#define DECODIFICADOR_R_H_INCLUDED

assembly _comando_r(int opcode[6], int shamt[5], int funct[6], int rd[5], int rs[5], int rt[5], char* linha);
assembly _add(char* linha);
assembly _and(char* linha);
assembly _nor(char* linha);
assembly _or(char* linha);
assembly _slt(char* linha);
assembly _sub(char* linha);
assembly _xor(char* linha);
assembly _sll(char* linha);
assembly _srl(char* linha);
assembly _div(char* linha);
assembly _mult(char* linha);
assembly _jr(char* linha);

#endif // DECODIFICADOR_R_H_INCLUDED
