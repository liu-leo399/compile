//
// Created by 刘天祺 on 2021/9/28.
//

#ifndef COMPILE_MYTYPE_H
#define COMPILE_MYTYPE_H

#include <string>


inline bool isAlpha(char temp) {
    int dd = (temp == '_') || (temp >= 'A' && temp <= 'Z' || (temp >= 'a' && temp <= 'z'));
    return dd;
}

inline bool isDigit(char temp) {
    int dd = (temp >= '0' && temp <= '9');
    return dd;
}

inline bool isPrint(char temp) {
    int dd = (temp == 32) || (temp == 33) || (temp >= 35 && temp <= 126);
    return dd;
}

inline bool toLower(char temp) {
    int dd = (temp >= 'A' && temp <= 'Z') ? temp + (char) 32 : temp;
    return dd;
}

inline bool isSpace(char temp) {
    int dd = temp == ' ' || temp == '\t' || temp == '\n' || temp == '\r';
    return dd;
}

inline bool isNextLine(char temp) {
    return temp == '\n';
}


#endif //COMPILE_MYTYPE_H
