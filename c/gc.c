#include <stdlib.h>
#include "type.h"

/*
 * GC
 * ==
 * Copy GC.
 */

int alloc_BOOL(void* memblk, size_t current)
{
}



int move_obj
(void* from, size_t from_size, void* to, size_t to_size,
 size_t from_current, size_t to_current)
{
	obj* current = (obj*)((size_t)from + from_current);
	obj* new = (obj*)((size_t)to + to_current);

	size_t size = sizeof(obj);
	switch(current->type){
	BOOL:
		size += sizeof(char);
		break;
	CONS:
		size += 2 * sizeof(size_t);
		break;
	INT32:
		size += sizeof(int32_t);
		break;
	SYMBOL:
		size_t* length = (size_t*)((size_t)current + sizeof(obj));
		size += sizeof(size_t) + (*length) * sizeof(uint32_t);
		break;
	CHAR:
		size += sizeof(int32_t);
		break;
	}

	return 0;
}

int full_gc
(void* from, size_t from_size,
 void* to, size_t to_size)
{
	size_t from_current = 0;
	size_t to_current = 0;
	size_t current_size;

	while(from_current < from_size){
		obj* current = (obj*)((size_t)from + from_current);
		switch(obj->type){
		BOOL:
			break;
		CONS:
			break;
		INT32:
			break;
		SYMBOL:
			break;
		CHAR:
			break;
		ARRAY:
			break;
		}
	}

	return 0;
}
