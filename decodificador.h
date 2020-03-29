#include "tipos_comuns.h"

#ifndef DECODIFICADOR_H_INCLUDED
#define DECODIFICADOR_H_INCLUDED

/***************************************************************************
 * Decodifica um comando intermediário MIPS em assembly MIPS
 *
 * @param linha O conteudo de linha para decodificação
 * @return A representação de assembly MIPS
 ***************************************************************************/
Assembly decodificar(char* linha);

#endif // DECODIFICADOR_H_INCLUDED
