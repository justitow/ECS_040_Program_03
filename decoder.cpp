// Author: Sean Davis
#include <iostream>
#include <cstring>

#include "decoder.h"
#include "instruction.h"
#include "registers.h"

using namespace std;

void Decoder::addl()
{
  *operand2 = *operand1 + *operand2;
}  // addl()

void Decoder::andl()
{
  *operand2 = *operand1 & *operand2;
}  // andl()

void Decoder::execute(Registers *registers, int memory[1001])
{
  const char *opcodes[] = { "addl", "andl", "leave", "movl", "pushl", "ret",
    "subl"};
  enum OpcodeNum {ADDL, ANDL, LEAVE, MOVL, PUSHL, RET, SUBL};
  int opcodeNum;
  
  for(opcodeNum = ADDL; 
    strcmp(opcode, opcodes[opcodeNum]) != 0 || opcodeNum > SUBL;
    ++opcodeNum);
  
  switch (opcodeNum)
  {
    case ADDL: addl(); break;
    case ANDL: andl(); break;
    case LEAVE: leave(registers, memory); break;
    case MOVL: movl(); break;
    case PUSHL: pushl(registers, memory); break;
    case RET: ret(registers, memory); break;
    case SUBL: subl(); break;
    default: cout << "Invalid opcode!\n";
  } // switch on oncodeNum
 
}  // execute()

void Decoder::leave(Registers *registers, const int memory[1001])
{
  //registers->regs[esp] = registers->regs[ebp];
  //registers->regs[ebp] = memory[registers->regs[esp]];
  //registers->regs[esp] += 4;
    
    registers->set(Registers::esp, registers->get(Registers::ebp));
    registers->set(Registers::ebp, memory[registers->get(Registers::esp)]);
    registers->set(Registers::esp, registers->get(Registers::esp) + 4);
}  // leave()


void Decoder::movl()
{
  *operand2 = *operand1;
}  // movl()


void Decoder::parse(Instruction *instruction, Registers *registers,
           int memory[1001])
{
  char *ptr, info[1000];
  
  strcpy(info, instruction->info);
  
  
  strcpy(opcode, strtok(info, " "));
  ptr = strtok(NULL, " ");
  
  if(ptr)
  {
    operand1 = registers->address(ptr, memory);
    ptr = strtok(NULL, " ");
    
    if(ptr)
      operand2 = registers->address(ptr, memory);
  } // if there is at least one operand
}  // parse()





void Decoder::pushl(Registers *registers, int memory[1001])
{
    registers->set(Registers::esp, registers->get(Registers::esp) - 4);
    memory[registers->get(Registers::esp)] = *operand1;
}  // pushl()


void const Decoder::ret(Registers *registers, int memory[1001])
{
    registers->set(Registers::eip, memory[registers->get(Registers::esp)]);
    registers->set(Registers::esp, registers->get(Registers::esp) + 4);
}  // ret()


void const Decoder::subl()
{
  *operand2 = *operand2 - *operand1;
}  // subl()
