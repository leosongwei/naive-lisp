/* Type definitions and global variables */

#ifndef _DEFINES_H_
#define _DEFINES_H_
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

extern void* symbol_t;
extern void* symbol_nil;
extern mem_info* mem_runtime;
extern size_t mem_limit;

#define CONS 1
#define INT32 2
#define SYMBOL 3
#define CHAR 4
#define ARRAY 5
#define FUNCTION 6
#define CLOSURE 7

/* meta data of obj */
struct obj{
	char type;
	char copied;
};
typedef struct obj obj;

/*
 * CONS:
 *   obj | CAR_ptr(void*) | CDR_ptr(void*)
 * INT32:
 *   obj | int32_t
 * CHAR:
 *   obj | uint32_t
 * SYMBOL
 *   obj | length(size_t) | uint32_t[length]
 * ARRAY:
 *   obj | length(size_t) | ptrs (void*)[length]
 * FUNCTION:
 *   obj | Arg_NUM(char) | length(size_t) | x86_64 op code
 * CLOSURE:
 *   obj | ARG_NUM(char) | func_ptr(void*)
 *   | value_num(size_t)
 *   | values_ptr (void*)[length]
 */

struct mem_info {
	// ptr: memory returned by malloc()
	void* ptr;
	// len: length given to malloc();
	size_t len;
	// cursor: Next available address,
	//   when avail >= len, call GC
	size_t cursor;
};
typedef struct mem_info mem_info;

#endif
