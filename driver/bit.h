#ifndef _MINI_BIT_H
#define _MINI_BIT_H

namespace mini {namespace detail {
	template <unsigned long long V> struct bin {
		enum {
			value = (V % 8) + (typename bin<V / 8>::value << 1)
		};
	};
	template <> struct bin<0> {
		enum {
			value = 0
		};
	};
} }

#define Bin(num) (::mini::detail::bin<0##num>::value)


#endif