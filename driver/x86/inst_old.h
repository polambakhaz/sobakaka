#ifndef _MINI_X86_INOOST_H
#define _MINI_X86_INOOST_H

#include <cstdint>

namespace mini { namespace x86 {

typedef unsigned char inst_byte;

enum reg32 {
	REG32_EAX = 0,
	REG32_ECX = 1,
	REG32_EDX = 2,
	REG32_EBX = 3,
	REG32_ESP = 4,
	REG32_EBP = 5,
	REG32_ESI = 6,
	REG32_EDI = 7,
};
enum op_dir {
	OPDIR_REG_TO_MEM = 0,
	OPDIR_MEM_TO_REG = 1,
};
enum op_size {
	OPSIZE_8,
	OPSIZE_16,
	OPSIZE_32,
};
enum addr_mode {
	ADDRMODE_SIB = 0,
	ADDRMODE_REG = 1,
	ADDRMODE_PTR = 2,
};
enum sib_scale {
	SIBSCALE_1 = 0,
	SIBSCALE_2 = 1,
	SIBSCALE_4 = 2,
	SIBSCALE_8 = 3,
};

struct inst_base {
	uint16_t op;
	op_size size;
};

struct inst_simple : inst_base {
};

struct inst_mem : inst_base {
	addr_mode addrmode;
	reg32 dst;
	sib_scale sibscale;
	reg32 sib_index;
	uint32_t disp;
};

struct inst_bin : inst_mem {
	reg32 src;
	op_dir dir;
};

struct inst_imm : inst_mem {
	uint32_t val;
};

void write32(inst_byte*& buf, uint32_t val);
void write_prefix(inst_byte*& buf, const inst_base& inst);
void write(inst_byte* buf, const inst_bin& inst);
void write(inst_byte* buf, const inst_imm& inst);
void write(inst_byte* buf, const inst_simple& inst);

} }

#endif