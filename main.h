#include "registers.h"

enum {eax, ebp, esp, eip};
int* address(Registers *registers, char *ptr, int memory[]);
