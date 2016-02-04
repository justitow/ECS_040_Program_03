// Author: Sean Davis

#include <cstring>
#include "instruction.h"


char* Instruction::getInfo() const
{
    return info;
    
}
int Instruction::getAdress() const
{
    return address;
}
void Instruction::setInfo(const char* new_info)
{
    info = new char[strlen(new_info) + 1];
    strcpy(info, new_info);
}
void Instruction::setAddress(int new_address)
{
    address = new_address;
}