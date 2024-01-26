#include <iostream>

#include "lexer.h"


int main(int argc, char** argv)
{  
    std::string usage = "Usage: ./bf_int <input_file>";

    if(argc != 2) 
    {
        std::cout << "Wrong number of arguments provided.\n" << usage << std::endl;
        return 1;
    }

    std::string path = argv[1];
    Lexer l(path);
}