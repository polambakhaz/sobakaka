#include "exec_buffer.h"

namespace mini {

ExecBuffer::ExecBuffer(size_t size)
	: m_size(size)
	, m_mem(exec_alloc(size))
{
}
ExecBuffer::~ExecBuffer() {
	exec_free(m_mem);
}

void ExecBuffer::resize(size_t size) {
	m_size = size;
	m_mem = exec_realloc(m_mem, size);
}

}
