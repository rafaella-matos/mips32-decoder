#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decodificador.h"

int main()
{
    decodificar("add $t0,$t2,$t3");
    printf("\n");
    decodificar("addi $t1,$t4,65535");
    printf("\n");
    decodificar("and $t0,$t1,$t2");
    printf("\n");
    decodificar("andi $t2,$t1,65535");
    printf("\n");
    decodificar("nor $t0,$t1,$t2");
    printf("\n");
    decodificar("or $t0,$t1,$t2");
    printf("\n");
    decodificar("ori $t2,$t1,65535");
    printf("\n");
    decodificar("slt $t0,$t1,$t2");
    printf("\n");
    decodificar("slti $t2,$t1,65535");
    printf("\n");
    decodificar("sub $t0,$t1,$t2");
    printf("\n");
    decodificar("xor $t0,$t1,$t2");
    printf("\n");
    decodificar("sll $t0,$t2,31");
    printf("\n");
    decodificar("srl $t1,$t2,31");
    printf("\n");
    decodificar("div $t1,$t2");
    printf("\n");
    decodificar("mult $t1,$t2");
    printf("\n");
    decodificar("beq $t1,$t2,offset");
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
    decodificar("sw rt,offset(rs)");
    printf("\n");
    return 0;
}
