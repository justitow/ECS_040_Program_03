// Author: Sean Davis

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include "registers.h"

using namespace std;

void Registers::initialize(int memory[1001])
{
  regs[esp] = 1000;
  regs[ebp] = 996;
  regs[eip] = 100;
  regs[eax] = 0;
  memory[1000] = 0;
}  // initialize()

void Registers::print(const char *instruction)
{
    cout << left << setw(20) << instruction << " eip: "
    << setw(3) << regs[eip] << " eax: "
    << setw(3) << regs[eax] << " ebp: "
    << setw(3) << regs[ebp] << " esp: "
    << setw(3) << regs[esp]  << "\n";
}  // print()

int* Registers::address(char *operand, int memory[])
{
    static int value;
    char regNames[4][7] = {"eax", "ebp", "esp", "eip"};
    char *ptr;
    int regNum, index;
    
    if(operand == NULL)
        return NULL;
    
    if(operand[0] == '$') // immediate mode
    {
        value = atoi(&operand[1]);
        return &value;
    } // if immediate mode
    
    for(regNum = eax; regNum <= eip; regNum++)
        if(strstr(operand, regNames[regNum]))
            break;
    
    ptr = strchr(operand, '(');
    
    if(ptr) // some form of indirect addressing
    {
        *ptr = '\0';  // terminate operand string at first '('
        index = atoi(operand);  // will return 0 if no number there!
        return  &memory[regs[regNum] + index];
    } // if ptr
    else  // direct addressing
        return &(regs[regNum]);
    
} // address ()

int Registers::get(RegName reg)
{
    return regs[reg];
}

void Registers::set(RegName reg, int new_value)
{
    regs[reg] = new_value;
}
