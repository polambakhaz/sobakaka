#ifndef _MINI_LANG_TOKEN_H
#define _MINI_LANG_TOKEN_H

#include <string>

namespace mini { namespace lang {

enum token_type {
	TOK_IDENTIFIER,
	
	TOK_KW_INT,
};

struct token {
	std::string str;
	long long num;
};

} }

#endif