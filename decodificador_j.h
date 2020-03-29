#include "tipos_comuns.h"

#ifndef DECODIFICADOR_J_H_INCLUDED
#define DECODIFICADOR_J_H_INCLUDED

/***************************************************************************
 * Decodifica um comando MIPS I
 *
 * @param opcode O código de operação
 * @param jump O valor para pulo
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _comando_j(int opcode[6], int jump[26]);

/***************************************************************************
 * Decodifica o comando J
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _j(char* linha);

/***************************************************************************
 * Decodifica o comando JAL
 * @param linha A linha a ser decodificada
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly _jal(char* linha);

#endif // DECODIFICADOR_J_H_INCLUDED
