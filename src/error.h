#ifndef ERROR_HEADER
#define ERROR_HEADER

typedef enum {
  FILE_NOT_FOUND, /* Err No. 100 */
  INVALID_ARGUMENT, /* Err No: 101 */
} error;

void throw_err(error, const char* message);
#endif
