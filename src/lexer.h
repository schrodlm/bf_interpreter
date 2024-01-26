#include <fstream>

class Lexer{

public:
    void next();
    char get_val();

private:

    char curr_val;
    std::ifstream file;
};