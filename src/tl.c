#include "tl.h"
#include "error.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv) {
    /* Collect Compiler Flags */
    args* flags = collect_args(argc, argv);
    printf("%s\n", flags->filename);
    /* Free Flags */

    return 0;
}

args *collect_args(int argc, char **argv) {
    args* f = malloc(sizeof(args));
    f->par = 0;
    for (int i = 1; i < argc; i++) {
        char* arg = argv[i];
        if(arg[0] == '-') {
            switch (arg[1]) {
            case 'e':
                f->par |= (1 << EMIT);
                break;
            case 'O':
                f->par |= (1 << OPT);
                break;
            case 'o':
                if(++i >= argc) {
                    /* TODO: Fix */
                    throw_err(INVALID_ARGUMENT, "");
                }
                f->filename = malloc(strlen(argv[i]));
                strncpy(f->filename, argv[i], strlen(argv[i]));
                break;
            default:
                throw_err(INVALID_ARGUMENT, arg);
            }
        } else {
            if(!(f->fp = fopen(arg, "r"))) {
                throw_err(FILE_NOT_FOUND, arg);
            }
        }
    }
    return f;
}
