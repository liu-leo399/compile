//
// Created by 刘天祺 on 2021/10/15.
//

#ifndef COMPILE_PARSING_H
#define COMPILE_PARSING_H

#include "../includes/Externs.h"
#include "ParsingException.h"
#include <set>

void ParsingAnalysis();

void ParsingAnalysis();

namespace Parsing {
    void getNextToken();

    void CompUnit();

    void ConstDecl();

    void error();

    void ConstDef();

    void ConstExp();

    void AddExp();

    void ConstInitVal();

    void MulExp();

    void UnaryExp();

    void Exp();

    void PrimaryExp();

    void FuncRParams();

    void LVal();

    void Number();

    void UnaryOp();

    void RelExp();

    void EqExp();

    void LAndExp();

    void Cond();

    void LOrExp();

    void VarDecl();

    void VarDef();

    void InitVal();

    void Decl();

    void FuncType();

    void FuncFParam();

    void FuncFParams();

    void FuncDef();

    void MainFuncDef();

    void Stmt();

    void BlockItem();

    void Block();
}


#endif //COMPILE_PARSING_H
