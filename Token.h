#pragma once

#include <variant>
#include <string>

#include "TokenType.h"

class Token {
public:
    TokenType type;
    std::variant<std::string, int> value;

    Token(TokenType type, std::variant<std::string, int> value): 
        type(type), value(value) {};
};