#include "lexer.h"
#include <iostream>
Lexer::Lexer(std::string path)
{

    file = std::ifstream(path.c_str());
    
    if (!file.is_open())
        throw std::invalid_argument("Provided file is invalid.");
}

void Lexer::next()
{
    
}

char Lexer::get_val()
{
}