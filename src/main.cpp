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
    l.parse();

    std::vector<Command> v = l.get_commands();
    for(int i = 0; i < v.size(); i++)
    {
        std::cout <<i << ": " << char(v[i].op) << "(" << v[i].operand << ")" << std::endl; 
    }
}