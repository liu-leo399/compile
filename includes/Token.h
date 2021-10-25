//
// Created by 刘天祺 on 2021/9/30.
//

#ifndef COMPILE_TOKEN_H
#define COMPILE_TOKEN_H

#include <string>
#include "TokenType.h"

class Token {
private:
    int lineNum;
    std::string rawString;
    TokenType tokenType;
public:
    Token();

    Token(int lineNum, std::string rawString, TokenType tokenType);

    TokenType getTokenType();

    friend std::ostream &operator<<(std::ostream &out, Token &temp);

    int getLineNum() const;

    std::string getRawString();
};


#endif //COMPILE_TOKEN_H
