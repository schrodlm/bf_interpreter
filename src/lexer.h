#include <fstream>
#include <string>

class Lexer{

public:
    Lexer(std::string);
    void next();
    char get_val();

private:

    char curr_val;
    std::ifstream file;
};