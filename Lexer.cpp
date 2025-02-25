#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <unordered_set>

#include "Token.h"
#include "TokenType.h"

#include "Lexer.h"

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    std::unordered_set<std::string> keywords = { "let" }; 

    size_t index = 0;
    while (index < code.length()) {
        char ch = code[index];

        if (std::isspace(ch)) {
            index++;  // Skip whitespace
            continue;
        }

        if (std::isdigit(ch)) {
            // Handle numbers (including multi-digit)
            int num = 0;
            while (index < code.length() && std::isdigit(code[index])) {
                num = num * 10 + (code[index] - '0');
                index++;
            }
            tokens.emplace_back(TokenType::NUM, num);
            continue;
        }

        if (ch == '"') {
            // Handle strings
            index++;  // Move past opening quote
            std::string str;
            while (index < code.length() && code[index] != '"') {
                str += code[index++];
            }
            if (index < code.length()) index++;  // Skip closing quote
            tokens.emplace_back(TokenType::STRING, str);
            continue;
        }

        if (std::isalpha(ch) || ch == '_') {
            // Handle identifiers & keywords
            std::string str;
            while (index < code.length() && (std::isalnum(code[index]) || code[index] == '_')) {
                str += code[index++];
            }
            tokens.emplace_back(
                keywords.count(str) ? TokenType::KEYWORD : TokenType::IDENTIFIER, str);
            continue;
        }

        // Handle single-character tokens
        switch (ch) {
        case '+': tokens.emplace_back(TokenType::PLUS, "+"); break;
        case '-': tokens.emplace_back(TokenType::MINUS, "-"); break;
        case '*': tokens.emplace_back(TokenType::MULT, "*"); break;
        case '/': tokens.emplace_back(TokenType::DIV, "/"); break;
        case ';': tokens.emplace_back(TokenType::SEMICOLON, ";"); break;
        default: break;  // Ignore unknown characters
        }
        index++;
    }

    return tokens;
}
