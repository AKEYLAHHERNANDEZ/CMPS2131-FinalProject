#ifndef SCANNER_H
#define SCANNER_H
#include <string>
#include <vector>
using namespace std;

enum TokenType {
    NUMBER,
    OPERATOR,
    LPAREN,
    RPAREN,
    UNKNOWN,
    END_OF_INPUT
};

struct Token {
    TokenType type;
    string value;
    Token(TokenType typeOfToken, const string& valueOfToken);
};

class Scanner {
public:
    Scanner(const std::string& input);
    Token getNextToken();

private:
    string input;
    size_t pos;
};

#endif
