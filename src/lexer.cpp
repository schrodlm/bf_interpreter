#include "lexer.h"
#include <iostream>
Lexer::Lexer(std::string path)
{

    file = std::ifstream(path.c_str());

    if (!file.is_open())
        throw std::invalid_argument("Provided file is invalid.");
}

void Lexer::parse()
{
    char c = next();
    while (c)
    {
        Command comm;

        switch (c)
        {

        case '+':
        case '-':
        case '>':
        case '<':
        case '.':
        case ',': {
            comm.op = (Operation)c;
            comm.operand = 1;
            char streak = next();
            while (c==streak)
            {
                comm.operand++;
                streak = next();
            }
            c = streak;
            commands.push_back(comm);
        } break;

        case '[':
        {
            comm.op = (Operation)c;
            comm.operand = commands.size(); //saving current adress for paired closing bracket
            jump_stack.push(comm);
            c = next();
            commands.push_back(comm);
        } break;

        case ']':
        {
            if(jump_stack.empty()) {
                file.close();
                throw std::runtime_error("Jump stack empty.");
            }

            Command paired_bracket = jump_stack.top();
            jump_stack.pop();
            
            comm.op = (Operation)c;
            comm.operand = paired_bracket.operand+1;

            paired_bracket.operand = commands.size()+1;
            //todo: here i am changing the copy inside commands, i would like to do
            //      it with pointers
            commands[comm.operand-1] = paired_bracket;
        commands.push_back(comm);
        c = next();
        } break;

        default: {}
        }
    }
}

char Lexer::next()
{
    char c;
    while (file.get(c))
    {
        if (is_bf_command(c))
        {
            return c;
        }
    }
    return 0;
}

bool Lexer::is_bf_command(const char c)
{
    std::string bf_commands = "+-<>[].,";

    for (size_t i = 0; i < bf_commands.size(); i++)
    {
        if (c == bf_commands[i])
            return true;
    }
    return false;
}

std::vector<Command>& Lexer::get_commands()
{
    return commands;
}