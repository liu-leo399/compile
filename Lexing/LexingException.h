//
// Created by 刘天祺 on 2021/10/4.
//

#ifndef COMPILE_LEXINGEXCEPTION_H
#define COMPILE_LEXINGEXCEPTION_H

#include <exception>

class LexingException : public std::exception {
private:
    int lineNum;

public:
    LexingException();

    explicit LexingException(int lineNum);

    int getLineNum() const;
};

#endif //COMPILE_LEXINGEXCEPTION_H
