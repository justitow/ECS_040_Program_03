// Author: Sean Davis

#include <cstring>
#include "instruction.h"


char* Instruction::getInfo() const
{
    return info;
    
} //Instruction::getInfo()
int Instruction::getAdress()
{
    return address;
} //Instruction::getAdress()
void Instruction::setInfo(const char* new_info)
{ 
    info = new char[strlen(new_info) + 1];
    strcpy(info, new_info);
} //Instruction::setInfo()
void Instruction::setAddress(int new_address)
{
    address = new_address;
} //Instruction::setAddress()
