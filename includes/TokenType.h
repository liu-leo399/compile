//
// Created by 刘天祺 on 2021/9/30.
//

#ifndef COMPILE_TOKENTYPE_H
#define COMPILE_TOKENTYPE_H

#include <iostream>

enum TokenType {
    IDENFR,
    INTCON,
    STRCON,
    MAINTK,
    CONSTTK,
    INTTK,
    BREAKTK,
    CONTINUETK,
    IFTK,
    ELSETK,
    NOT,
    AND,
    OR,
    WHILETK,
    GETINTTK,
    PRINTFTK,
    RETURNTK,
    PLUS,
    MINU,
    VOIDTK,
    MULT,
    DIV,
    MOD,
    LSS,
    LEQ,
    GRE,
    GEQ,
    EQL,
    NEQ,
    ASSIGN,
    SEMICN,
    COMMA,
    LPARENT,
    RPARENT,
    LBRACK,
    RBRACK,
    LBRACE,
    RBRACE
};

std::ostream &operator<<(std::ostream &out, TokenType tp);

#endif //COMPILE_TOKENTYPE_H
