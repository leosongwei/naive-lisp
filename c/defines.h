#ifndef _DEFINES_H_
#define _DEFINES_H_
#include <stdint.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <stddef.h>
#include "type.h"

struct mem_info {
	// ptr: memory returned by malloc()
	void* ptr;
	// len: length given to malloc();
	size_t len;
	// avail: Next available address,
	//   when avail >= len, call GC
	size_t avail;
};
typedef struct mem_info mem_info;

#endif
