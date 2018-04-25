#ifndef _DEFINES_H_
#define _DEFINES_H_
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>

struct mem_info {
	void* ptr;
	 // memory returned by malloc()
	size_t len;
	// length given to malloc();
};
typedef struct mem_info mem_info;

#endif
