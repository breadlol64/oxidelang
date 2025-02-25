#include <iostream>
#include <vector>
#include <unordered_map>

#include "Lexer.h"
#include "Token.h"
#include "TokenType.h"

void print_tokens(const std::vector<Token>& tokens) {
    static const std::unordered_map<TokenType, std::string> tokenTypeToString = {
        {TokenType::NUM, "NUM"},
        {TokenType::PLUS, "PLUS"},
        {TokenType::MINUS, "MINUS"},
        {TokenType::MULT, "MULT"},
        {TokenType::DIV, "DIV"},
        {TokenType::NEWLINE, "NEWLINE"},
        {TokenType::SEMICOLON, "SEMICOLON"},
        {TokenType::LPAREN, "LPAREN"},
        {TokenType::RPAREN, "RPAREN"},
        {TokenType::STRING, "STRING"},
        {TokenType::KEYWORD, "KEYWORD"},
        {TokenType::IDENTIFIER, "IDENTIFIER"}
    };

    for (const Token& token : tokens) {
        auto it = tokenTypeToString.find(token.type);
        std::string strTokenType = (it != tokenTypeToString.end()) ? it->second : "UNKNOWN";

        std::cout << strTokenType << ": ";
        if (std::holds_alternative<std::string>(token.value)) {
            std::cout << std::get<std::string>(token.value);
        }
        else {
            std::cout << std::get<int>(token.value);
        }
        std::cout << std::endl;
    }
}

int main() {
	std::string program = "let msg12 = \"Hello, World!\"; let num = 12+3";
	Lexer lexer(program);
	std::vector<Token> tokens = lexer.tokenize();

	print_tokens(tokens);

	return 0;
}

