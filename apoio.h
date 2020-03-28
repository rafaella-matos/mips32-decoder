#ifndef APOIO_H_INCLUDED
#define APOIO_H_INCLUDED

typedef struct {
    int opcode[6];
    int funct[6];
} comando;

struct Comandos {
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
};
struct Comandos comandos;

// transforma um numero decimal em binario
void binario(int valor, int* vetor);

// trunca o valor binario normal para caber em 5 posicoes
void binario5(int* valor, int* vetor);

// calcula o valor binario (truncado em 5) para o registrador
void registrador(char* valor, int* vetor);

// calcula o valor binario para a constante imediata
void immediate(char* valor, int* vetor);

// calcula o valor binario para a constante imediata
void jump(char* valor, int* vetor);

void shift(char* valor, int* retorno);

#endif // APOIO_H_INCLUDED
