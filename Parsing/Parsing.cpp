//
// Created by 刘天祺 on 2021/10/15.
//

#include "Parsing.h"
#include "../includes/Token.h"
#include "../includes/ioControl.h"


using namespace Parsing;
static std::vector<Token *>::iterator nextToken;
static std::set<std::string> returnFunc;


void ParsingAnalysis() {
    nextToken = tokens.begin() - 1;
    getNextToken();
    CompUnit();
}

void Parsing::getNextToken() {
    if (nextToken >= tokens.begin() && (*nextToken)->getTokenType() != (TokenType) -1) {
        fileout << *(*nextToken) << std::endl;
        //fileout << 11 << std::endl;
    }

    if (nextToken != tokens.end()) {
        nextToken++;
    }
}

void Parsing::error() {
    std::cerr << *(*nextToken) << " " << (*nextToken)->getLineNum() << std::endl;
    // throw ParsingException();
}

void Parsing::CompUnit() { //最后写
    //std::cout << (*nextToken)->getTokenType() << std::endl;
    std::cout << "111" << std::endl;

    if ((*nextToken)->getTokenType() == TokenType::CONSTTK) {
        while ((*nextToken)->getTokenType() == TokenType::CONSTTK) {
            Decl();
        }
    } else if ((*nextToken)->getTokenType() == TokenType::INTTK) {
        while ((*nextToken)->getTokenType() == TokenType::INTTK &&
               (*(nextToken + 1))->getTokenType() == TokenType::IDENFR &&
               (*(nextToken + 2))->getTokenType() != TokenType::LPARENT) {
            Decl();
        }
    }

    if ((*nextToken)->getTokenType() == TokenType::INTTK && (*(nextToken + 1))->getTokenType() == TokenType::IDENFR &&
        (*(nextToken + 2))->getTokenType() == TokenType::LPARENT) {
        FuncDef();
    }
    MainFuncDef();
    //getNextToken();
    //std::cout << "121" << std::endl;
    fileout << "<CompUnit>" << std::endl;
}

void Parsing::Decl() {
    //getNextToken();
    while ((*nextToken)->getTokenType() == TokenType::CONSTTK || (*nextToken)->getTokenType() == TokenType::INTTK) {
        if ((*nextToken)->getTokenType() == TokenType::CONSTTK) {
            ConstDecl();
        } else if ((*nextToken)->getTokenType() == TokenType::INTTK) {
            VarDecl();
        }
    }
}

void Parsing::ConstDecl() {
    getNextToken();  // print const
    getNextToken();  // print int
    do{
        ConstDef();
        if((*nextToken)->getTokenType() == TokenType::COMMA || (*nextToken)->getTokenType() == TokenType::SEMICN) {
            getNextToken(); // print , ;    指向下一个符号
        }
    }while((*(nextToken - 1))->getTokenType() == TokenType::COMMA);
    fileout << "<ConstDecl>" << std::endl;
}

void Parsing::ConstDef() {
    if ((*nextToken)->getTokenType() != TokenType::IDENFR) error();
    getNextToken(); //print ident
    while ((*nextToken)->getTokenType() == TokenType::LBRACK) {
        if ((*nextToken)->getTokenType() != TokenType::LBRACK) {
            error();
        }
        //getNextToken(); //??
        ConstExp();
        //getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::RBRACK) {
            getNextToken();
        } else {
            error();
        }
        //getNextToken();
    }
    if ((*nextToken)->getTokenType() != TokenType::ASSIGN) error();
    getNextToken();  //print =
    ConstInitVal();
    fileout << "<ConstDef>" << std::endl;
}

void Parsing::ConstInitVal() {
    if ((*nextToken)->getTokenType() == TokenType::LBRACE) {
        do {
            getNextToken();
            ConstInitVal();
        } while ((*nextToken)->getTokenType() == TokenType::COMMA);
        getNextToken();
        if ((*nextToken)->getTokenType() == TokenType::RBRACE)
            getNextToken();
    } else {
        ConstExp();
    }
    fileout << "<ConstInitVal>" << std::endl;
}

void Parsing::ConstExp() {
    AddExp();
    fileout << "<ConstExp>" << std::endl;
}

void Parsing::AddExp() {
    do {
        //getNextToken();
        MulExp();
        fileout << "<AddExp>" << std::endl;
        if((*(nextToken))->getTokenType() == TokenType::PLUS || (*(nextToken))->getTokenType() == TokenType::MINU){
            getNextToken();  // print + -  or ;
        }
    } while ((*(nextToken-1))->getTokenType() == TokenType::PLUS || (*(nextToken-1))->getTokenType() == TokenType::MINU);

}

void Parsing::MulExp() {
    do {
        //getNextToken();
        UnaryExp();
        fileout << "<MulExp>" << std::endl;
        if ((*nextToken)->getTokenType() == TokenType::MULT || (*nextToken)->getTokenType() == TokenType::DIV ||
            (*nextToken)->getTokenType() == TokenType::MOD)  {
            getNextToken(); // print * / %
        }

    } while ((*(nextToken-1))->getTokenType() == TokenType::MULT || (*(nextToken-1))->getTokenType() == TokenType::DIV ||
             (*(nextToken-1))->getTokenType() == TokenType::MOD);

}

void Parsing::Exp() {
    AddExp();
    fileout << "<Exp>" << std::endl;
}


void Parsing::UnaryExp() {
    //getNextToken();
    if ((*nextToken)->getTokenType() == TokenType::PLUS || (*nextToken)->getTokenType() == TokenType::MINU ||
        (*nextToken)->getTokenType() == TokenType::NOT) {
        UnaryOp();
        UnaryExp();
    } else if ((*nextToken)->getTokenType() == TokenType::IDENFR &&
               (*(nextToken + 1))->getTokenType() == TokenType::LPARENT) {
        getNextToken();
        if ((*nextToken)->getTokenType() == TokenType::LPARENT) {
            //error();
            getNextToken();
            FuncRParams();
            //getNextToken();
        }
        if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
        getNextToken();
    } else {
        PrimaryExp();
    }
    fileout << "<UnaryExp>" << std::endl;
}

void Parsing::UnaryOp() {
    if ((*nextToken)->getTokenType() == TokenType::PLUS || (*nextToken)->getTokenType() == TokenType::MINU ||
        (*nextToken)->getTokenType() == TokenType::NOT) {
        getNextToken();
    } else {
        error();
    }
    fileout << "<UnaryOp>" << std::endl;
}

void Parsing::PrimaryExp() {
    //getNextToken();
    if ((*nextToken)->getTokenType() == TokenType::LPARENT) {
        getNextToken();
        Exp();
        if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
        else getNextToken(); // print )
    } else if ((*nextToken)->getTokenType() == TokenType::INTCON) {
        Number();
    } else {
        LVal();
    }
    fileout << "<PrimaryExp>" << std::endl;
}

void Parsing::Number() {
    if ((*nextToken)->getTokenType() != TokenType::INTCON) error();
    getNextToken();
    fileout << "<Number>" << std::endl;
}

void Parsing::LVal() {
    // getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::IDENFR)error();
    //getNextToken();
    while ((*(nextToken + 1))->getTokenType() == TokenType::LBRACK) {
        getNextToken();
        Exp();
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::RBRACK) error();
    }
    getNextToken();
    fileout << "<LVal>" << std::endl;
}

void Parsing::FuncRParams() {
    do {
        getNextToken();
        Exp();
        getNextToken();
    } while ((*nextToken)->getTokenType() != TokenType::COMMA);
    fileout << "<FuncRParams>" << std::endl;
}

void Parsing::RelExp() {
    do {
        AddExp();
        getNextToken();
    } while ((*nextToken)->getTokenType() != TokenType::LSS || (*nextToken)->getTokenType() != TokenType::LEQ ||
             (*nextToken)->getTokenType() != TokenType::GRE || (*nextToken)->getTokenType() != TokenType::GEQ);
    fileout << "<RelExp>" << std::endl;
}

void Parsing::EqExp() {
    do {
        RelExp();
        getNextToken();
    } while ((*nextToken)->getTokenType() != TokenType::EQL || (*nextToken)->getTokenType() != TokenType::NEQ);
    fileout << "<EqExp>" << std::endl;
}

void Parsing::LAndExp() {
    do {
        EqExp();
        getNextToken();
    } while ((*nextToken)->getTokenType() != TokenType::AND);
    fileout << "<LAndExp>" << std::endl;
}

void Parsing::Cond() {
    LOrExp();
    fileout << "<Cond>" << std::endl;
}

void Parsing::LOrExp() {
    do {
        LAndExp();
        getNextToken();
    } while ((*nextToken)->getTokenType() != TokenType::OR);
    fileout << "<LOrExp>" << std::endl;
}

void Parsing::VarDecl() {
    //getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::INTTK) error();

    do {
        getNextToken();
        VarDef();
        //std::cout << (*nextToken)->getTokenType() << std::endl;
    } while ((*(nextToken))->getTokenType() == TokenType::COMMA);
    getNextToken();
    fileout << "<VarDecl>" << std::endl;
}

void Parsing::VarDef() {
    //getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::IDENFR) error();
    getNextToken();
    while ((*(nextToken))->getTokenType() == TokenType::LBRACK) {
        if ((*(nextToken))->getTokenType() != TokenType::LBRACK) error();
        getNextToken();
        ConstExp();
        //getNextToken();
        if ((*(nextToken))->getTokenType() != TokenType::RBRACK) {
            error();
        } else getNextToken();
    }
    if ((*nextToken)->getTokenType() == TokenType::ASSIGN) {
        getNextToken();
        InitVal();
    }
    fileout << "<VarDef>" << std::endl;
}

void Parsing::InitVal() {
    if ((*nextToken)->getTokenType() == TokenType::LBRACE) {
        getNextToken();
        if ((*nextToken)->getTokenType() == TokenType::LBRACE ||
            (*nextToken)->getTokenType() == TokenType::INTCON) {
            do {
                // getNextToken();
                InitVal();
                getNextToken();
            } while ((*nextToken)->getTokenType() == TokenType::COMMA);
        }
        if ((*nextToken)->getTokenType() != TokenType::RBRACE) error();
    } else {
        Exp();
    }
    fileout << "<InitVal>" << std::endl;
}

void Parsing::FuncType() {
    //getNextToken();
    std::cout << (*nextToken)->getTokenType() << std::endl;
    if ((*nextToken)->getTokenType() == TokenType::VOIDTK || (*nextToken)->getTokenType() == TokenType::INTTK) {

    } else {
        error();
    }
    fileout << "<FuncType>" << std::endl;
}

void Parsing::FuncFParam() {
    getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::INTTK) error();
    getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::IDENFR) error();
    getNextToken();
    if ((*nextToken)->getTokenType() == TokenType::LBRACK) {
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::RBRACK) error();
        getNextToken();
        while ((*nextToken)->getTokenType() != TokenType::LBRACK) {
            ConstExp();
            getNextToken();
            if ((*nextToken)->getTokenType() != TokenType::RBRACK) error();
            getNextToken();
        }
    }
    fileout << "<FuncFParam>" << std::endl;
}

void Parsing::FuncFParams() {
    do {
        getNextToken();
        FuncFParam();
    } while ((*nextToken)->getTokenType() == TokenType::COMMA);
    fileout << "<FuncFParams>" << std::endl;
}

void Parsing::FuncDef() {
    FuncType();
    getNextToken();
    //std::cout << (*nextToken)->getTokenType() << std::endl;
    if ((*nextToken)->getTokenType() != TokenType::IDENFR) error();
    getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::LPARENT) error();
    getNextToken();
    if ((*nextToken)->getTokenType() == TokenType::INTTK) {
        FuncFParams();
    }
    if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
    Block();
    fileout << "<FuncDef>" << std::endl;
}

void Parsing::MainFuncDef() {
    //getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::INTTK) error();
    getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::MAINTK) error();
    getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::LPARENT) error();
    getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
    getNextToken();
    Block();
    fileout << "<MainFuncDef>" << std::endl;
}

void Parsing::Stmt() {
    if ((*nextToken)->getTokenType() == TokenType::IDENFR) {
        //getNextToken();
        int i = 1, flag = 0;
        while ((*(nextToken + 1))->getTokenType() != TokenType::SEMICN && flag == 0) {
            if ((nextToken + 1) < tokens.end() && (*(nextToken + i))->getTokenType() == TokenType::ASSIGN) {
                flag = 1;
            }
            i++;
        }
        if (flag == 1) {
            LVal();
            //getNextToken();
            if ((*nextToken)->getTokenType() != TokenType::ASSIGN) error();
            getNextToken();
            if ((*nextToken)->getTokenType() == TokenType::GETINTTK) {
                getNextToken();
                if ((*nextToken)->getTokenType() != TokenType::LPARENT) error();
                getNextToken();
                if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
                getNextToken();
                if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
                getNextToken();
            } else {
                Exp();
                getNextToken();
                if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
            }
        } else { //有Exp
            Exp();
            getNextToken();
            if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
        }
    } else if ((*nextToken)->getTokenType() == TokenType::IFTK) {
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::LPARENT) error();
        Cond();
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
        Stmt();
        getNextToken();
        if ((*nextToken)->getTokenType() == TokenType::ELSETK) {
            Stmt();
        }
    } else if ((*nextToken)->getTokenType() == TokenType::WHILETK) {
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::LPARENT) error();
        Cond();
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
        Stmt();
    } else if ((*nextToken)->getTokenType() == TokenType::BREAKTK) {
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
    } else if ((*nextToken)->getTokenType() == TokenType::CONTINUETK) {
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
    } else if ((*nextToken)->getTokenType() == TokenType::PRINTFTK) {
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::LPARENT) error();
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::STRCON) error();
        getNextToken();
        while ((*nextToken)->getTokenType() == TokenType::COMMA) {
            getNextToken();
            Exp();
            //getNextToken();
        }
        if ((*nextToken)->getTokenType() != TokenType::RPARENT) error();
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
        getNextToken();
    } else if ((*nextToken)->getTokenType() == TokenType::RETURNTK) {
        getNextToken();
        if ((*nextToken)->getTokenType() == TokenType::LPARENT ||
            (*nextToken)->getTokenType() == TokenType::IDENFR ||
            (*nextToken)->getTokenType() == TokenType::INTCON) {
            Exp();
        }
        //
        if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
        getNextToken();
    } else if ((*nextToken)->getTokenType() == TokenType::LBRACE) {
        Block();
    } else {
        getNextToken();
        if ((*nextToken)->getTokenType() != TokenType::SEMICN) error();
    }
    fileout << "<Stmt>" << std::endl;
}

void Parsing::BlockItem() {
    if ((*nextToken)->getTokenType() == TokenType::CONSTTK || (*nextToken)->getTokenType() == TokenType::INTTK) {
        Decl();
    } else {
        Stmt();
    }
}

void Parsing::Block() {
    // std::cout << (*nextToken)->getTokenType() << "1" <<std::endl;

    if ((*nextToken)->getTokenType() != TokenType::LBRACE) error();
    getNextToken();
    while ((*nextToken)->getTokenType() == TokenType::CONSTTK || (*nextToken)->getTokenType() == TokenType::INTTK ||
           (*nextToken)->getTokenType() == TokenType::IDENFR ||
           (*nextToken)->getTokenType() == TokenType::LPARENT ||
           (*nextToken)->getTokenType() == TokenType::INTCON || (*nextToken)->getTokenType() == TokenType::LBRACE ||
           (*nextToken)->getTokenType() == TokenType::IFTK || (*nextToken)->getTokenType() == TokenType::WHILETK ||
           (*nextToken)->getTokenType() == TokenType::BREAKTK ||
           (*nextToken)->getTokenType() == TokenType::RETURNTK ||
           (*nextToken)->getTokenType() == TokenType::PRINTFTK) {
        BlockItem();
        //getNextToken();
    }
    //getNextToken();
    if ((*nextToken)->getTokenType() != TokenType::RBRACE) error();
    getNextToken();
    fileout << "<Block>" << std::endl;
}








