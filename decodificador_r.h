#include "tipos_comuns.h"

#ifndef DECODIFICADOR_R_H_INCLUDED
#define DECODIFICADOR_R_H_INCLUDED

/***************************************************************************
 * Decodifica um comando MIPS R
 *
 * @param opcode O código de operação
 * @param shamt O valor de shift
 * @param funct O código da função
 * @param rd O registrador RD
 * @param rs O registrador RS
 * @param rt O registrador RT
 * @param imm O valor immediate
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _comando_r(int opcode[6], int shamt[5], int funct[6], int rd[5], int rs[5], int rt[5]);

/***************************************************************************
 * Decodifica o comando ADD
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _add(char* linha);

/***************************************************************************
 * Decodifica o comando AND
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _and(char* linha);

/***************************************************************************
 * Decodifica o comando NOR
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _nor(char* linha);

/***************************************************************************
 * Decodifica o comando OR
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _or(char* linha);

/***************************************************************************
 * Decodifica o comando SLT
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _slt(char* linha);

/***************************************************************************
 * Decodifica o comando SUB
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _sub(char* linha);

/***************************************************************************
 * Decodifica o comando XOR
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _xor(char* linha);

/***************************************************************************
 * Decodifica o comando SLL
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _sll(char* linha);

/***************************************************************************
 * Decodifica o comando SRL
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _srl(char* linha);

/***************************************************************************
 * Decodifica o comando DIV
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _div(char* linha);

/***************************************************************************
 * Decodifica o comando MULT
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _mult(char* linha);

/***************************************************************************
 * Decodifica o comando JR
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _jr(char* linha);

#endif // DECODIFICADOR_R_H_INCLUDED
