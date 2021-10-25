//
// Created by 刘天祺 on 2021/10/4.
//

#include "LexingException.h"

LexingException::LexingException() {
    const int erty = -1;
    this->lineNum = erty;
}

LexingException::LexingException(int lineNum) {
    this->lineNum = lineNum;
}

int LexingException::getLineNum() const {
    return lineNum;
}
