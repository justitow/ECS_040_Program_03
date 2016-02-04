//
//  registers.h
//  Homework01
//
//  Created by Justin Weich on 1/6/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef registers_h
#define registers_h

#include <iostream>
#include <cstring>


class Registers
{
    int regs[4];
public:
    
    typedef enum
    {
        eax, ebp, esp, eip
    }RegName;
    
    void initialize(int memory[1001]);
    void print(const char *instruction) const;
    int* address(char *operand, int memory[]);
    int get(RegName reg) const;
    void set(RegName reg, int new_value);
    
    

};



#endif
