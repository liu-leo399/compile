//
// Created by 刘天祺 on 2021/10/3.
//

#include "LexAnalysis.h"
#include "../includes/ioControl.h"
#include <cstring>

std::vector<Token *> tokens;

void LexAnalysis(const std::string &rawString) {
    std::string tmpToken;
    int lineNum = 1;
    int i = 0;
    TokenType type;
    while (i < rawString.length()) {
        int flag = 0;
        tmpToken = "";
        type = static_cast<TokenType>(-1);
        while (isSpace(rawString[i])) {
            if (isNextLine(rawString[i])) {
                lineNum++;
            }
            i = i + 1;
        }
        if (i>=rawString.length()) break;
        if (isAlpha(rawString[i])) {
            std::string tmp;
            tmp = "";
            do {
                tmpToken += rawString[i];
                //tmp += toLower(rawString[i]);
                tmp += rawString[i];
                i = i + 1;
            } while ((isAlpha(rawString[i]) || isDigit(rawString[i])) && i < rawString.length());
            if (tmp.compare("const") == 0) {
                type = TokenType::CONSTTK;
            } else if (tmp.compare("main") == 0) {
                type = TokenType::MAINTK;
            } else if (tmp.compare("int") == 0) {
                type = TokenType::INTTK;
            } else if (tmp.compare("break") == 0) {
                type = TokenType::BREAKTK;
            } else if (tmp.compare("continue") == 0) {
                type = TokenType::CONTINUETK;
            } else if (tmp.compare("if") == 0) {
                type = TokenType::IFTK;
            } else if (tmp.compare("else") == 0) {
                type = TokenType::ELSETK;
            } else if (tmp.compare("while") == 0) {
                type = TokenType::WHILETK;
            } else if (tmp.compare("getint") == 0) {
                type = TokenType::GETINTTK;
            } else if (tmp.compare("printf") == 0) {
                type = TokenType::PRINTFTK;
            } else if (tmp.compare("return") == 0) {
                type = TokenType::RETURNTK;
            } else if (tmp.compare("void") == 0) {
                type = TokenType::VOIDTK;
            } else {
                type = TokenType::IDENFR;
            }
        } else if (isDigit(rawString[i])) {
            do {
                tmpToken += rawString[i];
                i = i + 1;
            } while (isDigit(rawString[i]) && i < rawString.length());
            type = TokenType::INTCON;
        } else if (rawString[i] == '\'') {
            i = i + 1;
            if (i < rawString.length()) {
                if (isAlpha(rawString[i]) || isDigit(rawString[i]) || rawString[i] == '+' || rawString[i] == '-' ||
                    rawString[i] == '*' || rawString[i] == '/') {
                    tmpToken += rawString[i];
                } else {
                    throw LexingException(lineNum);
                }
                i = i + 1;
                /*if (i < rawString.length() && rawString[i] == '\'') {
                    type = TokenType::CHARCON;
                    i = i + 1;
                } else {
                    throw LexingException(lineNum);
                }*/
            } else {
                throw LexingException(lineNum);
            }
        } else if (rawString[i] == '\"') {
            tmpToken += rawString[i];
            i = i + 1;
            while (isPrint(rawString[i]) && i < rawString.length()) {
                tmpToken += rawString[i];
                i = i + 1;
            }
            if (i < rawString.length() && rawString[i] == '\"') {
                type = TokenType::STRCON;
                tmpToken += rawString[i];
                i = i + 1;
            } else {
                throw LexingException(lineNum);
            }
        } else if (rawString[i] == '!') {
            tmpToken += rawString[i];
            i++;
            if (i < rawString.length() && rawString[i] == '=') {
                tmpToken += rawString[i];
                i++;
                type = TokenType::NEQ;
            } else {
                type = TokenType::NOT;
            }
        } else if (rawString[i] == '&') {
            tmpToken += rawString[i];
            i++;
            if (i < rawString.length() && rawString[i] == '&') {
                tmpToken += rawString[i];
                i++;
                type = TokenType::AND;
            } else {
                throw LexingException(lineNum);
            }
        } else if (rawString[i] == '|') {
            tmpToken += rawString[i];
            i++;
            if (i < rawString.length() && rawString[i] == '|') {
                tmpToken += rawString[i];
                i++;
                type = TokenType::OR;
            } else {
                throw LexingException(lineNum);
            }
        } else if (rawString[i] == '+') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::PLUS;
        } else if (rawString[i] == '-') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::MINU;
        } else if (rawString[i] == '*') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::MULT;
        } else if (rawString[i] == '/') {
            if (rawString[i + 1] == '/') {
                i = i + 1;
                i = i + 1;
                while (rawString[i++] != '\n');
                lineNum++;
                continue;
            } else if (rawString[i + 1] == '*') {
                i = i + 1;
                i = i + 1;
                while (true) {
                    if (rawString[i] == '\n') {
                        lineNum++;
                    }
                    if (rawString[i] == '*' && rawString[i + 1] == '/') {
                        i = i + 1;
                        i = i + 1;
                        if (rawString[i] == '\n') {
                            i = i + 1;
                            lineNum++;
                        }
                        flag = 1;
                        break;
                    }
                    i = i + 1;
                }
                if (flag == 1)
                    continue;
            } else {
                tmpToken += rawString[i];
                i++;
                type = TokenType::DIV;
            }
        } else if (rawString[i] == '%') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::MOD;
        } else if (rawString[i] == ';') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::SEMICN;
        } else if (rawString[i] == ',') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::COMMA;
        } else if (rawString[i] == '(') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::LPARENT;
        } else if (rawString[i] == ')') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::RPARENT;
        } else if (rawString[i] == '[') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::LBRACK;
        } else if (rawString[i] == ']') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::RBRACK;
        } else if (rawString[i] == '{') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::LBRACE;
        } else if (rawString[i] == '}') {
            tmpToken += rawString[i];
            i++;
            type = TokenType::RBRACE;
        } else if (rawString[i] == '<') {
            tmpToken += rawString[i];
            i++;
            if (i < rawString.length() && rawString[i] == '=') {
                tmpToken += rawString[i];
                i++;
                type = TokenType::LEQ;
            } else {
                type = TokenType::LSS;
            }
        } else if (rawString[i] == '>') {
            tmpToken += rawString[i];
            i++;
            if (i < rawString.length() && rawString[i] == '=') {
                tmpToken += rawString[i];
                i++;
                type = TokenType::GEQ;
            } else {
                type = TokenType::GRE;
            }
        } else if (rawString[i] == '=') {
            tmpToken += rawString[i];
            i++;
            if (i < rawString.length() && rawString[i] == '=') {
                tmpToken += rawString[i];
                i++;
                type = TokenType::EQL;
            } else {
                type = TokenType::ASSIGN;
            }
        } else {
            throw LexingException(lineNum);
        }

        tokens.push_back(new Token(lineNum, tmpToken, type));
    }
   tokens.push_back(new Token());
}

void printLexingDebug() {
    for (Token *t: tokens) {
        if (t->getTokenType() != (TokenType) -1)
            fileout << *t << std::endl;
    }
}