//
// Created by 刘天祺 on 2021/9/28.
//

#include <sstream>
#include "ioControl.h"

const std::string inputFile = "testfile.txt";
const std::string outputFile = "output.txt";

/*std::string read() {
    std::ifstream t(inputFile);
    //std::string str((std::istreambuf_iterator<char>(t)),
    //                std::istreambuf_iterator<char>());
    std::stringstream ss;
    ss << t.rdbuf();
    t.close();
    std::string s = ss.str();


    return s;
}*/

std::string read() {
    std::ifstream t(inputFile);
    std::string str((std::istreambuf_iterator<char>(t)),
                    std::istreambuf_iterator<char>());
    return str;
}

std::ofstream fileout = std::ofstream(outputFile, std::ios::out | std::ios::trunc);
