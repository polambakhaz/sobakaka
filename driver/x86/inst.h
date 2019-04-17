#ifndef _MINI_X86_INST_H
#define _MINI_X86_INST_H

#include <mini/bit.h>

#include <cstdint>

namespace mini { namespace x86 {

typedef uint8_t reg_t;

enum {
	SIZE_8  = Bin(00),
	SIZE_16 = Bin(01),
	SIZE_32 = Bin(11),
};
enum {
	DIR_REG_TO_MEM = Bin(00),
	DIR_MEM_TO_REG = Bin(10),
};

enum {
	MOD_POINTER        = Bin(00),
	MOD_DISPLACE_BYTE  = Bin(01),
	MOD_DISPLACE_DWORD = Bin(10),
	MOD_REGISTER       = Bin(11),
};

enum {
	REG_AL = Bin(000),
	REG_CL = Bin(001),
	REG_DL = Bin(010),
	REG_BL = Bin(011),
	REG_AH = Bin(100),
	REG_CH = Bin(101),
	REG_DH = Bin(110),
	REG_BH = Bin(111),
};
enum {
	REG_AX = Bin(000),
	REG_CX = Bin(001),
	REG_DX = Bin(010),
	REG_BX = Bin(011),
	REG_SP = Bin(100),
	REG_BP = Bin(101),
	REG_SI = Bin(110),
	REG_DI = Bin(111),
};
enum {
	REG_EAX = Bin(000),
	REG_ECX = Bin(001),
	REG_EDX = Bin(010),
	REG_EBX = Bin(011),
	REG_ESP = Bin(100),
	REG_EBP = Bin(101),
	REG_ESI = Bin(110),
	REG_EDI = Bin(111),
};
enum {
	REG_XMM0 = Bin(000),
	REG_XMM1 = Bin(001),
	REG_XMM2 = Bin(010),
	REG_XMM3 = Bin(011),
	REG_XMM4 = Bin(100),
	REG_XMM5 = Bin(101),
	REG_XMM6 = Bin(110),
	REG_XMM7 = Bin(111),
};
enum {
	REG_SPECIAL_SIB_NO_DISP = Bin(100),
	REG_SPECIAL_DISP_ONLY   = Bin(101),
};

enum {
	SIBSCALE_1 = Bin(00),
	SIBSCALE_2 = Bin(01),
	SIBSCALE_3 = Bin(10),
	SIBSCALE_4 = Bin(11),
};

enum {
	IMM_OPCODE = Bin(10000000)
};
enum {
	IMM_SIZE_SAME = Bin(00),
	IMM_SIZE_BYTE = Bin(10),
};

inline uint8_t make_op(uint8_t op) {
	return op;
}
inline uint8_t make_op(uint8_t op, uint8_t dir, uint8_t size) {
	return op | dir | (size & 1);
}
inline uint8_t make_op_imm(uint8_t imm_size, uint8_t size) {
	return IMM_OPCODE | imm_size | (size & 1);
}
inline uint8_t make_sib(uint8_t scale, uint8_t index, uint8_t base) {
	return scale << 6 | index << 3 | base;
}
inline uint8_t make_mrm(uint8_t mod, uint8_t reg, uint8_t rm) {
	return mod << 6 | reg << 3 | rm;
}
inline uint8_t make_mrm_imm(uint8_t mod, uint8_t op, uint8_t rm) {
	return mod << 6 | op << 3 | rm;
}

} }

#endif