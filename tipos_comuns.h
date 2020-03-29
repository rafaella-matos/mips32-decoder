#ifndef TIPOS_COMUNS_H_INCLUDED
#define TIPOS_COMUNS_H_INCLUDED

typedef struct {
    char* linha;
    char tipo;
    int binario[32];
} Assembly;

/***************************************************************************
 * Representa um comando MIPS
 ***************************************************************************/
typedef struct {
    char* prefixo;
    int opcode[6];
    int funct[6];
} Comando;

/***************************************************************************
 * Representa um conjunto pré-determinado de comandos MIPS
 ***************************************************************************/
typedef struct {
    Comando add;
    Comando addi;
    Comando and;
    Comando andi;
    Comando nor;
    Comando or;
    Comando ori;
    Comando slt;
    Comando slti;
    Comando sub;
    Comando xor;
    Comando sll;
    Comando srl;
    Comando div;
    Comando mult;
    Comando beq;
    Comando bne;
    Comando j;
    Comando jal;
    Comando jr;
    Comando lw;
    Comando sw;
} Comandos;

static Comandos comandos = {
    { "add",    { 0, 0, 0, 0, 0, 0 },   { 1, 0, 0, 0, 0, 0 }    }, // add
    { "addi",   { 0, 0, 1, 0, 0, 0 },   { }                     }, // addi
    { "and",    { 0, 0, 0, 0, 0, 0 },   { 1, 0, 0, 1, 0, 0 }    }, // and
    { "andi",   { 0, 0, 1, 1, 0, 0 },   { }                     }, // andi
    { "nor",    { 0, 0, 0, 0, 0, 0 },   { 1, 0, 0, 1, 1, 1 }    }, // nor
    { "or",     { 0, 0, 0, 0, 0, 0 },   { 1, 0, 0, 1, 0, 1 }    }, // or
    { "ori",    { 0, 0, 1, 1, 0, 1 },   { }                     }, // ori
    { "slt",    { 0, 0, 0, 0, 0, 0 },   { 1, 0, 1, 0, 1, 0 }    }, // slt
    { "slti",   { 0, 0, 1, 0, 1, 0 },   { }                     }, // slti
    { "sub",    { 0, 0, 0, 0, 0, 0 },   { 1, 0, 0, 0, 1, 0 }    }, // sub
    { "xor",    { 0, 0, 0, 0, 0, 0 },   { 1, 0, 0, 1, 1, 0 }    }, // xor
    { "sll",    { 0, 0, 0, 0, 0, 0 },   { 0, 0, 0, 0, 0, 0 }    }, // sll
    { "srl",    { 0, 0, 0, 0, 0, 0 },   { 0, 0, 0, 0, 1, 0 }    }, // srl
    { "div",    { 0, 0, 0, 0, 0, 0 },   { 0, 1, 1, 0, 1, 0 }    }, // div
    { "mult",   { 0, 0, 0, 0, 0, 0 },   { 0, 1, 1, 0, 0, 0 }    }, // mult
    { "beq",    { 0, 0, 0, 1, 0, 0 },   { }                     }, // beq
    { "bne",    { 0, 0, 0, 1, 0, 1 },   { }                     }, // bne
    { "j",      { 0, 0, 0, 0, 1, 0 },   { }                     }, // j
    { "jal",    { 0, 0, 0, 0, 1, 1 },   { }                     }, // jal
    { "jr",     { 0, 0, 0, 0, 0, 0 },   { 0, 0, 1, 0, 0, 0 }    }, // jr
    { "lw",     { 1, 0, 0, 0, 1, 1 },   { }                     }, // lw
    { "sw",     { 1, 0, 1, 0, 1, 1 },   { }                     }, // sw
    };

static Comandos comandos;

#endif // TIPOS_COMUNS_H_INCLUDED
