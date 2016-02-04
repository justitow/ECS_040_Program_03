#ifndef DECODER_H
#define	DECODER_H
// Author: Sean Davis

#include "instruction.h"
#include "registers.h"

class Decoder
{
    char opcode[20];
    int *operand1;
    int *operand2;
    
    void const addl();
    void const andl();
    void const leave(Registers *registers, int memory[1001]);
    void const movl();
    void const pushl(Registers *registers, int memory[1001]);
    void const ret(Registers *registers, int memory[1001]);
    void const subl();
    
public:
    void parse(Instruction *instruction, Registers *registers,
               int memory[1001]);
    void execute(Registers *registers, int memory[1001]);


};


#endif	// DECODER_H

