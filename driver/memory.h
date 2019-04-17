#ifndef _MINI_MEMORY_H
#define _MINI_MEMORY_H

#include <cstddef>

namespace mini {

typedef unsigned char* exec_ptr;

exec_ptr exec_alloc(size_t size);
exec_ptr exec_realloc(exec_ptr ptr, size_t size);
void exec_free(exec_ptr ptr);

}

#endif
