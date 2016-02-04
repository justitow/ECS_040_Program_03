// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include "registers.h"
#include "main.h"

using namespace std;

void initialize(Registers *registers, int memory[1001])
{
  registers->regs[esp] = 1000;
  registers->regs[ebp] = 996;
  registers->regs[eip] = 100;
  registers->regs[eax] = 0;
  memory[1000] = 0;
}  // initialize()

void print(Registers *registers, const char *instruction)
{
    cout << left << setw(20) << instruction << " eip: "
    << setw(3) << registers->regs[eip] << " eax: "
    << setw(3) << registers->regs[eax] << " ebp: "
    << setw(3) <<  registers->regs[ebp] << " esp: "
    << setw(3) << registers->regs[esp]  << "\n";
    //cout << ("%-20s eip: %3d eax: %3d ebp: %3d esp: %3d\n", instruction,
    //registers->regs[eip], registers->regs[eax], registers->regs[ebp],
    //registers->regs[esp]);
}  // print()
