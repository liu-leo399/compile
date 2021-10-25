#include <iostream>
#include "includes/ioControl.h"
#include "Lexing/LexAnalysis.h"
#include "Parsing/Parsing.h"

#define Lexing
#define Parsing

int main() {
    std::string rawString = read();
    //std::cout << "0" << std::endl;
    std::cout << rawString << std::endl;
    //std::cout << "1";
    try {
        LexAnalysis(rawString);
    } catch (LexingException &e) {
        std::cerr << "Lexing Error in Line " << e.getLineNum() << std::endl;
        return 0;
    }

#ifdef Lexing
    printLexingDebug();
#endif
#ifdef Parsing
    try {
        ParsingAnalysis();
    } catch (ParsingException &e) {
        std::cerr << e;
    }

#endif

    return 0;
}