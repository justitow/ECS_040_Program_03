// Author: Sean Davis

#include <iostream>
#include <fstream>
#include <cstring>

#include "reader.h"
#include "registers.h"

using namespace std;

void Reader::fetch(Instruction *instruction, Registers *registers)
{
  int pos = 0;
  
  for(pos = 0; lines[pos].getAdress() != registers->get(Registers::eip); pos++);
  *instruction = lines[pos];
  registers->set(Registers::eip, registers->get(Registers::eip) + 4);
} // fetch()

void Reader::read(Registers *registers, const char *filename)
{
  char line[256], *ptr;
  int address = 100, instructionCount = 0;
  ifstream inf(filename);
  
  while(inf.getline(line, 255))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
        
    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
    
    if(*ptr != '.' && !strstr(line, "main:"))
    {
      
      lines[instructionCount].setAddress(address);
      lines[instructionCount].setInfo(ptr);
      instructionCount ++ ;
      address += 4;
    } // if not directive, nor main:
  }  // while more in file
}  // read()
