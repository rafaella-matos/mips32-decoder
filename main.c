#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decodificador.h"
#include "tipos_comuns.h"

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
    decodificar("sll $t0,$t1,31");
    printf("\n");
    decodificar("srl $t1,$t2,31");
    printf("\n");
    decodificar("div $t1,$t2");
    printf("\n");
    decodificar("mult $t1,$t2");
    printf("\n");
    decodificar("beq $t1,$t2,65535");
    printf("\n");
    decodificar("bne $t1,$t2,65535");
    printf("\n");
    decodificar("j 67108863");
    printf("\n");
    decodificar("jal 67108863");
    printf("\n");
    decodificar("jr $t0");
    printf("\n");
    decodificar("lw $t2,65535($t0)");
    printf("\n");
    decodificar("sw $t2,65535($t0)");
    printf("\n");
    return 0;
}
