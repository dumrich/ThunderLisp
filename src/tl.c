#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct {
  FILE* fp;
  /* 8 Bit field
     Opt: t || f
     Emit: BIN || ASM 
     Baremetal: t || f
     Bits 4 to 8 empty
   */
  unsigned char par;
} args;

int main(int argc, char** argv)
{
  if(argc == 2)
    return 0;
  return 0;
}

args* collect_args(int argc, char** argv) {

}
