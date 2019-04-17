#include "inst_old.h"
namespace mini { namespace x86 {

void write32(inst_byte*& buf, uint32_t val) {
	*buf++ = val;
	*buf++ = val >> 8;
	*buf++ = val >> 16;
	*buf++ = val >> 24;
}

void write_prefix(inst_byte*& buf, const inst_base& inst) {
	if (inst.size == OPSIZE_16)
		*buf++ = 0x66;
}

void write(inst_byte* buf, const inst_simple& inst) {
	write_prefix(buf, inst);
	*buf++ = inst.op;
}

void write(inst_byte* buf, const inst_bin& inst) {
	write_prefix(buf, inst);
	uint8_t op = inst.op;
	if (inst.size != OPSIZE_8)
		op |= 0x01;
	if (inst.dir == OPDIR_MEM_TO_REG)
		op |= 0x02;
	*buf++ = op;
	uint8_t mod = 3 << 6;
	
	switch (inst.addrmode) {
	case ADDRMODE_PTR:
		if (inst.disp == 0)
			mod = 0 << 6;
		else if (inst.disp <= 0xff)
			mod = 1 << 6;
		else
			mod = 2 << 6;
	case ADDRMODE_REG:
		*buf++ = mod | inst.src << 3 | inst.dst;
		break;
	case ADDRMODE_SIB:
		*buf++ = inst.src << 3 | 4;
		*buf++ = inst.sibscale << 6 | inst.sib_index | inst.dst;
		break;
	}

	if (inst.disp >= 0xff) {
		write32(buf, inst.disp);
	} else if (inst.disp != 0) {
		*buf++ = inst.disp;
	}
}

void write(inst_byte* buf, const inst_imm& inst) {
	write_prefix(buf, inst);

	uint8_t op = 1 << 7;
	bool small_imm;
	if (inst.size != OPSIZE_8)
		op |= 0x01;
	if (small_imm = (inst.val <= 0xFF))
		op |= 0x02;

	*buf++ = op;

	if (inst.addrmode == ADDRMODE_REG) {
		*buf++ = 3 << 6 | inst.op << 3 | inst.dst;
	} else if (inst.addrmode == ADDRMODE_SIB) {
		*buf++ = inst.op << 3 | 4;
		*buf++ = inst.sibscale << 6 | inst.sib_index << 3 | inst.dst;
	}

	if (small_imm) {
		*buf++ = inst.val;
	} else {
		write32(buf, inst.val);
	}
}

} }