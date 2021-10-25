cmake_minimum_required(VERSION 3.20)
project(compile)

set(CMAKE_CXX_STANDARD 11)

add_executable(compile main.cpp includes/MyType.cpp includes/MyType.h includes/ioControl.cpp includes/ioControl.h includes/Token.cpp includes/Token.h includes/TokenType.cpp includes/TokenType.h Lexing/LexAnalysis.cpp Lexing/LexAnalysis.h Lexing/LexingException.cpp Lexing/LexingException.h Parsing/Parsing.cpp Parsing/Parsing.h includes/Externs.h Parsing/ParsingException.cpp Parsing/ParsingException.h)
