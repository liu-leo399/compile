//
// Created by 刘天祺 on 2021/10/15.
//

#include "ParsingException.h"

#include <utility>
#include <iostream>

ParsingException::ParsingException() {
    this->message = "Unknown Error";
}

ParsingException::ParsingException(std::string message) {
    this->message = std::move(message);
}

std::ostream &operator<<(std::ostream &out, ParsingException &tmp) {
    out << "[Parsing Error]:" << tmp.message << std::endl;
    return out;
}