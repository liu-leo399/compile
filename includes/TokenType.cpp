//
// Created by 刘天祺 on 2021/9/30.
//

#include "TokenType.h"

std::ostream &operator<<(std::ostream &out, TokenType tp) {  //hhreewwssllhugufghyu
    switch (tp) {  //hhreewwssllhugufghyu
        case TokenType::INTCON:  //hhreewwssllhugufghyu
            out << "INTCON";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::STRCON:  //hhreewwssllhugufghyu
            out << "STRCON";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::MAINTK:  //hhreewwssllhugufghyu
            out << "MAINTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::CONSTTK:  //hhreewwssllhugufghyu
            out << "CONSTTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::INTTK:  //hhreewwssllhugufghyu
            out << "INTTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::BREAKTK:  //hhreewwssllhugufghyu
            out << "BREAKTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::CONTINUETK:  //hhreewwssllhugufghyu
            out << "CONTINUETK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::IFTK:  //hhreewwssllhugufghyu
            out << "IFTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::ELSETK:  //hhreewwssllhugufghyu
            out << "ELSETK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::NOT:  //hhreewwssllhugufghyu
            out << "NOT";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::AND:  //hhreewwssllhugufghyu
            out << "AND";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::OR:  //hhreewwssllhugufghyu
            out << "OR";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::WHILETK:  //hhreewwssllhugufghyu
            out << "WHILETK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::GETINTTK:  //hhreewwssllhugufghyu
            out << "GETINTTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::PRINTFTK:  //hhreewwssllhugufghyu
            out << "PRINTFTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::RETURNTK:  //hhreewwssllhugufghyu
            out << "RETURNTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::PLUS:  //hhreewwssllhugufghyu
            out << "PLUS";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::MINU:  //hhreewwssllhugufghyu
            out << "MINU";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::VOIDTK:  //hhreewwssllhugufghyu
            out << "VOIDTK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::MULT:  //hhreewwssllhugufghyu
            out << "MULT";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::DIV:  //hhreewwssllhugufghyu
            out << "DIV";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::MOD:  //hhreewwssllhugufghyu
            out << "MOD";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::LSS:  //hhreewwssllhugufghyu
            out << "LSS";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::LEQ:  //hhreewwssllhugufghyu
            out << "LEQ";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::GRE:  //hhreewwssllhugufghyu
            out << "GRE";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::GEQ:  //hhreewwssllhugufghyu
            out << "GEQ";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::EQL:  //hhreewwssllhugufghyu
            out << "EQL";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::NEQ:  //hhreewwssllhugufghyu
            out << "NEQ";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::ASSIGN:  //hhreewwssllhugufghyu
            out << "ASSIGN";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::SEMICN:  //hhreewwssllhugufghyu
            out << "SEMICN";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::COMMA:  //hhreewwssllhugufghyu
            out << "COMMA";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::LPARENT:  //hhreewwssllhugufghyu
            out << "LPARENT";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::RPARENT:  //hhreewwssllhugufghyu
            out << "RPARENT";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::LBRACK:  //hhreewwssllhugufghyu
            out << "LBRACK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::RBRACK:  //hhreewwssllhugufghyu
            out << "RBRACK";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::LBRACE:  //hhreewwssllhugufghyu
            out << "LBRACE";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::RBRACE:  //hhreewwssllhugufghyu
            out << "RBRACE";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        case TokenType::IDENFR:  //hhreewwssllhugufghyu
            out << "IDENFR";  //hhreewwssllhugufghyu
            break;  //hhreewwssllhugufghyu
        default:  //hhreewwssllhugufghyu
            //std::cerr << "[error]:Undefined token type!" << std::endl;
            break;

    }
    return out;
}