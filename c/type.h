#ifndef _TYPE_H_
#define _TYPE_H_

#include <stddef.h>
#include <stdint.h>

#define BOOL 0
#define CONS 1
#define INT32 2
#define SYMBOL 3
#define CHAR 4
#define ARRAY 5
#define REF 6

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
 * ARRAY:
 *   obj | length (size_t) | obj[length]
 * REF:
 *   obj | offset (size_t) | array offset (size_t)
 *   If the value referred is not in an array, the array offset is 0.
 */

struct array{
	uint64_t size;
	obj* members;
};
typedef struct array array;

/* Closure is implemented as array.
 * * The compiler knows which reference to a variable is
 *   a reference to a variable in a closure.
 * * The compiler knows which variable should be closed
 *   the closure of current stack.
 * * To access a variable in a closure. Firstly, find the
 *   closure array. Secondly, obtain or change the atomic
 *   value (or reference value if is array) from the
 *   closure.
 *
 * Struct is also implemented as array.
 */

#endif
