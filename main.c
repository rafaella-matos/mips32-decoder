#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decodificador.h"

int main()
{
    int* temp = immediate((unsigned short)65535);
    int i;
    for(i = 0; i < 16; i++) printf("%d",temp[i]);

    //decodificar("add $t0,$t2,$t3");
    //printf("\n");
    //decodificar("addi $t1,$t4,65535");
    /*printf("\n");
    decodificar("and rd,rs,rt");
    printf("\n");
    decodificar("andi rt,rs,imm");
    printf("\n");
    decodificar("nor rd,rs,rt");
    printf("\n");
    decodificar("or rd,rs,rt");
    printf("\n");
    decodificar("ori rt,rs,imm");
    printf("\n");
    decodificar("slt rd,rs,rt");
    printf("\n");
    decodificar("slti rt,rs,imm");
    printf("\n");
    decodificar("sub rd,rs,rt");
    printf("\n");
    decodificar("xor rd,rs,rt");
    printf("\n");
    decodificar("sll rd,rt,sa");
    printf("\n");
    decodificar("srl rs,rt,sa");
    printf("\n");
    decodificar("div rs,rt");
    printf("\n");
    decodificar("mult rs,rt");
    printf("\n");
    decodificar("beq rs,rt,offset");
    printf("\n");
    decodificar("bne rs,rt,offset");
    printf("\n");
    decodificar("j target");
    printf("\n");
    decodificar("jal target");
    printf("\n");
    decodificar("jr rs");
    printf("\n");
    decodificar("lw rt,offset(rs)");
    printf("\n");
    decodificar("sw rt,offset(rs)");*/
    printf("\n");
    return 0;
}
