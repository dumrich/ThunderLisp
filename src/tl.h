#ifndef TL_HEADER
#define TL_HEADER

#include <stdio.h>

#define OPT 00
#define EMIT 01

/* Supported Architectures */
typedef enum {
    x64_Linux,
    arm_Linux,
    x64_FreeBSD,
    arm_NetBSD
} arch;

typedef struct {
    /* Main file */
    FILE* fp;

    /* 8 Bit field
       Opt: f || t
       Emit: BIN || ASM
       Bits 6 to 8 empty
     */
    unsigned char par;

    /* Target Architecture */
    arch a;

    /* Output file */
    char* filename;

} args;

args* collect_args(int argc, char** argv);
void free_args(args*);
#endif
