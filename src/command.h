
typedef enum {
    OP_INCREMENT = '+',
    OP_DECREMENT = '-',
    OP_LEFT = '<',
    OP_RIGHT = '>',
    OP_OUTPUT = '.',
    OP_INPUT = ',',
    OP_ZERO_JUMP = '[',
    OP_NON_ZERO_JUMP = ']'
} Operation;


class Command{
    public:
    Operation op;
    int operand;
};