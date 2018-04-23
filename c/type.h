#ifndef _TYPE_H_

#include <stddef.h>
#include <stdint.h>

#define BOOL 0
#define CONS 1
#define INT32 2
#define SYMBOL 3
#define CHAR 4
#define ARRAY 5

/* meta data of obj */
struct obj{
	char type;
	char copied;
};
typedef struct obj obj;

/*
 * BOOL is a C Char, stored right after the obj.
 * INT32 is a C INT, stored right after the obj.
 * CHAR is a C UINT32, stored right after the obj.
 *
 * the STRING(not implemented yet) may be defined as an ARRAY of CHARs.
 *
 * CONS:
 *   obj | CAR offset (size_t) | CDR offset (size_t)
 * SYMBOL:
 *   obj | length (size_t) | uint_32[length]
 */


struct array{
	uint64_t size;
	obj* members;
};
typedef struct array array;

#endif
