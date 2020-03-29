#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decodificador.h"
#include "tipos_comuns.h"

int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        char comando[1000];
        char binario[32];
        printf("Informe o comando a ser calculado: ");
        gets(comando);

        Assembly c = decodificar(comando);

        int i;
        for (i = 0; i < 32; i++)
        {
            printf("%d", c.binario[i]);
        }
    }
    else if (argc == 2)
    {
        printf("Arquivo: %s\n", argv[1]);

        FILE *leitura = fopen(argv[1], "r");

        if (leitura == NULL)
        {
            printf("Não foi possível abrir o arquivo especificado!\n");
            exit(-1);
        }

        char comando[1000];
        char binario[32];
        while(fgets(comando, 1000, leitura) != NULL)
        {
            if (comando[strlen(comando) - 1] < 40 || comando[strlen(comando) - 1] > 122)
            {
                comando[strlen(comando) - 1] = '\0';
            }

            Assembly c = decodificar(comando);

            int i;
            for (i = 0; i < 32; i++)
            {
                printf("%d", c.binario[i]);
            }

            printf("\n");
        }
    }
    else if (argc == 3)
    {
        printf("Arquivo: %s\n", argv[1]);

        FILE *leitura = fopen(argv[1], "r");
        FILE *gravacao = fopen(argv[2], "w+");

        if (leitura == NULL || gravacao == NULL)
        {
            printf("Não foi possível abrir os arquivos especificados!\n");
            exit(-1);
        }

        char comando[1000];
        char binario[32];
        while(fgets(comando, 1000, leitura) != NULL)
        {
            if (comando[strlen(comando) - 1] < 40 || comando[strlen(comando) - 1] > 122)
            {
                comando[strlen(comando) - 1] = '\0';
            }

            Assembly c = decodificar(comando);

            int i;
            for (i = 0; i < 32; i++)
            {
                fprintf(gravacao, "%d", c.binario[i]);
            }
            fprintf(gravacao, "\n");
        }
    }


    // O primeiro argumento é o nome do programa
    /*if (argc > 1)
    {
        // Imprime os argumentos
        for(int i = 1; i < argc; i++)
        {
            if (argc == 3)
            {
                existeArquivoSaida = true;
            }

            printf("Argumento: %s\n", argv[i]);
        }
    }*/


    /*decodificar("add $t0,$t2,$t3");
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
    printf("\n");*/
    return 0;
}
