#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
// Author: Sean Davis

class Instruction
{
private:
  int address;
  char * info;
public:
    char* getInfo() const;
    int getAdress();
    void setInfo(const char* new_info);
    void setAddress(int new_address);
}; //Instruction

#endif	// INSTRUCTION_H 

