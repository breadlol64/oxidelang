#pragma once

#include <vector>
#include <string>

#include "Token.h"

class Lexer {
public:
	std::string code;
	Lexer(std::string code) : code(code) {};
	std::vector<Token> tokenize();
};
