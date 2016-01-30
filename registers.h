//
//  registers.h
//  Homework01
//
//  Created by Justin Weich on 1/6/16.
//  Copyright © 2016 Justin Weich. All rights reserved.
//

#ifndef registers_h
#define registers_h

#include <stdio.h>

typedef struct
{
    int regs[4];
} Registers;

void initialize(Registers *registers, int memory[1001]);

void print(Registers *registers, const char *instruction);

#endif
