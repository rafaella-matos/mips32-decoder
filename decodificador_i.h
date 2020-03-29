#include "tipos_comuns.h"

#ifndef DECODIFICADOR_I_H_INCLUDED
#define DECODIFICADOR_I_H_INCLUDED

/***************************************************************************
 * Decodifica um comando MIPS I
 *
 * @param opcode O código de operação
 * @param funct O código da função
 * @param rs O registrador RS
 * @param rt O registrador RT
 * @param imm O valor immediate
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _comando_i(int opcode[6], int funct[6], int rs[5], int rt[5], int imm[16]);

/***************************************************************************
 * Decodifica o comando ADDI
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _addi(char* linha);

/***************************************************************************
 * Decodifica o comando ANDI
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _andi(char* linha);

/***************************************************************************
 * Decodifica o comando ORI
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _ori(char* linha);

/***************************************************************************
 * Decodifica o comando SLTI
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _slti(char* linha);

/***************************************************************************
 * Decodifica o comando BEQ
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _beq(char* linha);

/***************************************************************************
 * Decodifica o comando BNE
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _bne(char* linha);

/***************************************************************************
 * Decodifica o comando LW
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _lw(char* linha);

/***************************************************************************
 * Decodifica o comando SW
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _sw(char* linha);

#endif // DECODIFICADOR_I_H_INCLUDED
