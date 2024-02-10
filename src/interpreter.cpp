
#include "interpreter.h"
#include <stdexcept>

Interpreter::Interpreter(std::vector<Command> _commands) : commands(_commands)
{
    memory.resize(1000, 0);
}

void Interpreter::apply()
{

    size_t com_ptr = 0;
    size_t mem_ptr = 0;

    while (com_ptr < commands.size())
    {
        Command curr_comm = commands[com_ptr];

        switch (curr_comm.op)
        {
        case OP_INCREMENT:
            memory[mem_ptr] += curr_comm.operand;
            com_ptr++;
            break;

        case OP_DECREMENT:
            memory[mem_ptr] -= curr_comm.operand;
            com_ptr++;
            break;

        case OP_LEFT:
            if (mem_ptr < curr_comm.operand)
                throw std::runtime_error("RUNTIME ERROR: Memory underflow");
            mem_ptr -= curr_comm.operand;
            com_ptr++;
            break;

        case OP_RIGHT:
            mem_ptr += curr_comm.operand;
            com_ptr++;
            break;

        case OP_OUTPUT:
            for (size_t i = 0; i < curr_comm.operand; i++)
            {
                fwrite(&memory[mem_ptr], 1, 1, stdout);
            }
            com_ptr++;
            break;

        case OP_INPUT:
            for (size_t i = 0; i < curr_comm.operand; i++)
            {
                fread(&memory[mem_ptr], 1, 1, stdin);
            }
            com_ptr++;
            break;

        case OP_ZERO_JUMP:
            if (memory[mem_ptr] == 0)
            {
                com_ptr = curr_comm.operand;
            }
            else
                com_ptr++;
            break;

        case OP_NON_ZERO_JUMP:
            if (memory[mem_ptr] > 0)
            {
                com_ptr = curr_comm.operand;
            }
            else
                com_ptr++;
            break;

        default:
            break;
        }

        if (mem_ptr > memory.size())
            memory.resize(2 * mem_ptr, 0);
    }
}
