#include "error.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* TODO: Make Variadic */
void throw_err(error e, const char *message) {
    switch (e) {
    case FILE_NOT_FOUND:
        fprintf(stderr, "Err 100: File %s not found\n", message);
        break;
    case INVALID_ARGUMENT:
        fprintf(stderr, "Err 101: Invalid argument '%s'\n", message);
        break;
    default:
        fprintf(stderr, "Err 200: Unexpected Error occurred\n");
    }
    exit(1);
}
