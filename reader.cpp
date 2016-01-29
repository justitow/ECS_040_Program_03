// Author: Sean Davis
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "reader.h"
#include "registers.h"

void fetch(Reader *reader, Instruction *instruction, Registers *registers)
{
  int pos;
  
  for(pos = 0; reader->lines[pos].address != registers->regs[eip]; pos++);
  
  *instruction = reader->lines[pos];
  registers->regs[eip] += 4;
} // fetch()

void read(Reader *reader, Registers *registers, const char *filename)
{
  char line[256], *ptr;
  int address = 100, instructionCount = 0;
  FILE *fp;
  fp = fopen(filename, "r");
  
  while(fgets(line, 256, fp) != 0)
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' ';  // replace all tabs with space characters
    
    *strchr(line, '\n') = '\0';  // eliminate \n;
    
    for(ptr = line; *ptr == ' '; ptr++);  // get past leading spaces
    
    if(*ptr != '.' && !strstr(line, "main:"))
    {
      reader->lines[instructionCount].address = address;
      address += 4;
      reader->lines[instructionCount].info = (char*) malloc(strlen(ptr) + 1);
      strcpy(reader->lines[instructionCount++].info, ptr);
    } // if not directive, nor main:
  }  // while more in file
}  // read()
