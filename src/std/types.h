#include <stdint.h>
#include <stdlib.h>

#define INT_BITS 32

typedef struct {
  uint8_t val;
} u8;

typedef struct {
  uint32_t val;
} u32;

typedef struct {
  uint64_t val;
} u64;

typedef struct {
  int8_t val;
} i8;

typedef struct {
  int32_t val;
} i32;

typedef struct {
  int64_t val;
} i64;

/* String types */
enum Encoding {
  UTF_8 = 0,
  ASCII,
};

typedef struct {
  enum Encoding enc;
  u8* str;

  /* Dynamic allocation */
  size_t length;
  size_t capacity;
} str;
