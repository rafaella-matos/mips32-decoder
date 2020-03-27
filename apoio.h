#ifndef APOIO_H_INCLUDED
#define APOIO_H_INCLUDED

typedef struct {
    int opcode[6];
    int funct[6];
} comando;

typedef struct {
    comando add   ;
    comando addi  ;
    comando and   ;
    comando andi  ;
    comando nor   ;
    comando or    ;
    comando ori   ;
    comando slt   ;
    comando slti  ;
    comando sub   ;
    comando xor   ;
    comando sll   ;
    comando srl   ;
    comando div   ;
    comando mult  ;
    comando beq   ;
    comando bne   ;
    comando j     ;
    comando jal   ;
    comando jr    ;
    comando lw    ;
    comando sw    ;
} containerComandos;

static const containerComandos comandos;

// transforma um numero decimal em binario
int* binario(int valor);

// trunca o valor binario normal para caber em 5 posicoes
int* binario5(int* valor);

// calcula o valor binario (truncado em 5) para o registrador
int* registrador(char* valor);

// calcula o valor binario para a constante imediata
int* immediate(unsigned short valor);

#endif // APOIO_H_INCLUDED
