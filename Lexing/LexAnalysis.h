//
// Created by 刘天祺 on 2021/10/3.
//

#ifndef COMPILE_LEXANALYSIS_H
#define COMPILE_LEXANALYSIS_H

#include <string>
#include <vector>
#include "../includes/Token.h"
#include "../includes/MyType.h"
#include "LexingException.h"
#include "../includes/Externs.h"



void LexAnalysis(const std::string &);

void printLexingDebug();
#endif //COMPILE_LEXANALYSIS_H
