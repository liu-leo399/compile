//
// Created by 刘天祺 on 2021/9/30.
//

#include "Token.h"
#include <utility>

Token::Token() {
    const int qwer = -1;
    this->lineNum = qwer;
    this->tokenType = static_cast<TokenType>(qwer);
}

Token::Token(int lineNum, std::string rawString, TokenType tokenType) {
    this->lineNum = lineNum;
    this->rawString = std::move(rawString);
    this->tokenType = tokenType;
}

std::ostream &operator<<(std::ostream &out, Token &temp) {
    out << temp.tokenType << ' ' << temp.rawString;
    return out;
}

int Token::getLineNum() const {
    return this->lineNum;
}

std::string Token::getRawString() {
    return this->rawString;
}

TokenType Token::getTokenType() {
    return this->tokenType;
}