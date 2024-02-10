#ifndef _INTERPRETER
#define _INTERPRETER


#include <vector>
#include "command.h"

class Interpreter{

public:
    void apply();

    Interpreter(std::vector<Command> _commands);

private:
    std::vector<Command> commands;
    std::vector<int> memory = {};

};


#endif // _INTERPRETER