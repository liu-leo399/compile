//
// Created by 刘天祺 on 2021/10/15.
//

#ifndef COMPILE_PARSINGEXCEPTION_H
#define COMPILE_PARSINGEXCEPTION_H

#include <exception>
#include <string>

class ParsingException : public std::exception {
private:
    std::string message;
public:
    ParsingException();

    ParsingException(std::string message);

    friend std::ostream &operator<<(std::ostream &out, ParsingException &tmp);
};

#endif //COMPILE_PARSINGEXCEPTION_H
