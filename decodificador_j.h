#include "tipos_comuns.h"

#ifndef DECODIFICADOR_J_H_INCLUDED
#define DECODIFICADOR_J_H_INCLUDED

Assembly _comando_j(int opcode[6], int jump[26]);
Assembly _j(char* linha);
Assembly _jal(char* linha);

#endif // DECODIFICADOR_J_H_INCLUDED
