#include "memory.h"

#ifdef _WIN32

#include <Windows.h>

namespace mini {

exec_ptr exec_alloc(size_t size) {
	return (exec_ptr)VirtualAlloc(NULL, size, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
}
exec_ptr exec_realloc(exec_ptr old, size_t size) {
	// Get the old size
	MEMORY_BASIC_INFORMATION info;
	VirtualQuery(old, &info, sizeof(info));

	if (size <= info.RegionSize) {
		// The memory block is large enough already
		return old;
	} else {
		// Copy and release the old info
		exec_ptr newmem = exec_alloc(size);
		CopyMemory(newmem, old, size);
		exec_free(old);
		return newmem;
	}
}
void exec_free(exec_ptr ptr) {
	VirtualFree(ptr, 0, MEM_RELEASE);
}

}

#endif
