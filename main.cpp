//
//  main.cpp
//  ECS_040_Program_03
//
//  Created by Justin Weich on 1/28/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <iomanip>

#include "registers.h"
#include "decoder.h"
#include "reader.h"
#include "instruction.h"
#include "main.h"


using namespace std;
    
    
int* address(Registers *registers, char *operand, int memory[])
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
            return  &memory[registers->regs[regNum] + index];
        } // if ptr
        else  // direct addressing
            return &(registers->regs[regNum]);
        
    } // address ()
    
int main(int argc, const char * argv[])
    {
        Reader reader;
        Decoder decoder;
        Registers registers;
        Instruction instruction;
        int memory [1001];
        initialize(&registers, memory);
        reader.read(&registers, argv[1]);
        
        while(registers.regs[eip] != 0)
        {
            reader.fetch(&instruction, &registers);
            parse(&decoder, &instruction, &registers, memory);
            execute(&decoder, &registers, memory);
            print(&registers, instruction.info);
        } // while eip not zero
        
        
        
        return 0;
    }  // main()
    
