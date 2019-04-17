#ifndef _MINI_EXEC_BUFFER_H
#define _MINI_EXEC_BUFFER_H

#include <mini/memory.h>

namespace mini {

class ExecBuffer {
public:
	ExecBuffer(size_t size);
	~ExecBuffer();

	void resize(size_t size);

private:
	ExecBuffer(const ExecBuffer& buf);
	ExecBuffer& operator=(const ExecBuffer& buf);

	size_t m_size;
	exec_ptr m_mem;
};

}

#endif
