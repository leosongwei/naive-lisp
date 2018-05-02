#include <sys/mman.h>
#include <fcntl.h>
#include "defines.h"

mem_info alloc_memory(size_t length)
// by pass the glibc malloc(), gain memory from kernel.
{
	mem_info info;
	int fd = open ("/dev/zero", O_RDONLY);
	info.ptr = mmap(NULL, length, PROT_EXEC|PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
	close (fd);

	if(info.ptr == MAP_FAILED){
		info.len = 0;
		return info;
	}
	info.len = length;
	info.cursor = 1; // 0 is NULL, don't care this minor waste.
	return info;
}

void free_memory(mem_info info)
{
	if(info.ptr == MAP_FAILED){
		return;
	}
	mprotect(info.ptr, info.len, PROT_WRITE|PROT_READ);
	munmap(info.ptr, info.len);
}
