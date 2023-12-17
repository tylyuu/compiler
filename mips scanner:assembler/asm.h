#ifndef ASSEMBLER_PARSER_H
#define ASSEMBLER_PARSER_H

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include "scanner.h"

class ParseError : public std::exception {
private:
    std::string message;
public:
    enum ErrorType {
        ILLEGAL_OPCODE,
        NO_SUCH_LABEL,
        EXPECTING_TYPE,
        END_LINE,
        DUPLICATE_LABEL
    };

    ParseError(const std::string &line, ErrorType type, const std::string &detail = "", std::string token = "register");

    const char *what() const throw() override;
};

std::string printType(Token::Kind t);

void checkType(std::string line, Token t, std::string type);

bool checkLabel(std::string line, Token t);

void LableProcess();

bool checkFormat(std::string line, const std::vector <Token> &input, const std::vector <Token::Kind> &format);

uint32_t parseTokenLine(std::string line, std::vector <Token> tokenLine, uint32_t opcode, uint32_t offset, uint32_t d,
                        uint32_t s, uint32_t t, uint32_t pc);

int output();

int main();

#endif // ASSEMBLER_PARSER_H
