#include "defines.h"

/*
 * GC
 * ==
 * Copy GC.
 */

size_t length_CONS()
{
	return sizeof(obj) + 2 * sizeof(size_t);
}

int alloc_CONS(mem_info* mem)
{
	if(mem->cursor + length_CONS() < mem->len){
		obj* head = (obj*)(mem->cursor + (size_t)mem->ptr);
		head->type = CONS;
		head->copied = 0;
		size_t* offset =
			(size_t*)((size_t)head + sizeof(obj));
		offset[0] = (size_t)symbol_nil;
		offset[1] = (size_t)symbol_nil;
		mem->cursor += length_CONS();
		return 0;
	}else{
		return -1;
	}
}

size_t length_INT32()
{
	return sizeof(obj) + sizeof(int32_t);
}

int alloc_INT32(mem_info* mem)
{
	if(mem->cursor + length_INT32() < mem->len){
		obj* head = (obj*)(mem->cursor + (size_t)mem->ptr);
		head->type = INT32;
		head->copied = 0;
		int32_t* integer = (int32_t*)((size_t)head
					      + sizeof(obj));
		*integer = 0;
		mem->cursor += length_INT32();
		return 0;
	}else{
		return -1;
	}
}

size_t length_CHAR()
{
	return sizeof(obj) + sizeof(uint32_t);
}

int alloc_CHAR(mem_info* mem)
{
	if(mem->cursor + length_CHAR() < mem->len){
		obj* head = (obj*)(mem->cursor + (size_t)mem->ptr);
		head->type = CHAR;
		head->copied = 0;
		uint32_t* character = (uint32_t*)((size_t)head
						  + sizeof(obj));
		*character = 0;
		mem->cursor += length_CHAR();
		return 0;
	}else{
		return -1;
	}
}

size_t length_SYMBOL(size_t length)
{
	return sizeof(obj) + sizeof(size_t)
		+ sizeof(uint32_t) * length;
}

int alloc_SYMBOL(mem_info* mem, size_t length)
{
	if(mem->cursor + length_SYMBOL(length) < mem->len){
		obj* head = (obj*)(mem->cursor + (size_t)mem->ptr);
		head->type = SYMBOL;
		head->copied = 0;
		size_t* len = (size_t*)((size_t)head + sizeof(obj));
		*len = length;
		mem->cursor += length_SYMBOL(length);
		return 0;
	}else{
		return -1;
	}
}

size_t length_ARRAY(size_t length)
{
	return sizeof(obj) + sizeof(size_t)
		+ sizeof(uint32_t) * length;
}

int alloc_ARRAY(mem_info* mem, size_t length)
{
	if(mem->cursor + length_ARRAY(length) < mem->len){
		obj* head = (obj*)(mem->cursor + (size_t)mem->ptr);
		head->type = SYMBOL;
		head->copied = 0;
		size_t* len = (size_t*)((size_t)head + sizeof(obj));
		*len = length;
		size_t* ptrs = (size_t*)((size_t)len + sizeof(size_t));
		for(size_t i=0; i<length; i++){
			ptrs[i] = (size_t)symbol_nil;
		}
		mem->cursor += length_ARRAY(length);
		return 0;
	}else{
		return -1;
	}
}

