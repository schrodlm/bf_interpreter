#include <fstream>
#include <string>
#include <vector>
#include <stack>

#include "Command.h"
class Lexer{

public:
    Lexer(std::string);
    void parse();
    char next();
    bool is_bf_command(const char c);
    std::vector<Command>& get_commands();

private:

    std::ifstream file;
    std::vector<Command> commands;
    std::stack<Command> jump_stack; //used for holding on to adresses of '['
};