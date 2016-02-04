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


using namespace std;
    


    
int main(int argc, const char * argv[])
    {
        Reader reader;
        Decoder decoder;
        Registers registers;
        Instruction instruction;
        int memory [1001];
        registers.initialize(memory);
        reader.read(&registers, argv[1]);
        
        while(registers.get(Registers::eip) != 0)
        {
            reader.fetch(&instruction, &registers);
            decoder.parse(&instruction, &registers, memory);
            decoder.execute(&registers, memory);
            registers.print(instruction.info);
        } // while eip not zero
        
        
        
        return 0;
    }  // main()
    
