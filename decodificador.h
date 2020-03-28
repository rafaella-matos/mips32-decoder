#ifndef DECODIFICADOR_H_INCLUDED
#define DECODIFICADOR_H_INCLUDED

typedef struct {
    char* linha;
    char tipo;
    int binario[32];
} assembly;

assembly decodificar(char* linha);

assembly _comando_r(int* opcode, int* shamt, int* funct, int* rd, int* rs, int* rt, char* linha);
assembly _comando_i(int* opcode, int* funct, int* rs, int* rt, int* imm, char* linha);
assembly _comando_j(int* opcode, int* jump, char* linha);

assembly _add(char* linha);
assembly _addi(char* linha);
assembly _and(char* linha);
assembly _andi(char* linha);
assembly _nor(char* linha);
assembly _or(char* linha);
assembly _ori(char* linha);
assembly _slt(char* linha);
assembly _slti(char* linha);
assembly _sub(char* linha);
assembly _xor(char* linha);
assembly _sll(char* linha);
assembly _srl(char* linha);
assembly _div(char* linha);
assembly _mult(char* linha);
assembly _beq(char* linha);
assembly _bne(char* linha);
assembly _j(char* linha);
assembly _jal(char* linha);
assembly _jr(char* linha);
assembly _lw(char* linha);
assembly _sw(char* linha);

#endif // DECODIFICADOR_H_INCLUDED
