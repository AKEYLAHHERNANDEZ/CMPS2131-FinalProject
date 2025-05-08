#ifndef SCANNER_H
#define SCANNER_H

#include <string>
#include <vector>
using namespace std;

// Enum to represent the different types of tokens
enum TokenType {
    NUMBER,
    OPERATOR,
    LeftParen,
    RightParen,
    UNKNOWN,
    END_OF_INPUT
};

// Struct representing a token with its type and value
struct Token {
    TokenType type;
    string value;

    // Constructor to initialize the tokens
    Token(TokenType typeOfToken, const string& valueOfToken);
};

// Scanner class to process input strings and extract tokens
class Scanner {
public:
    // Constructor to initialize with input string
    Scanner(const string& input);

    // Returns the next token from the input
    Token getNextToken();
//Declaration for the input and size
private:
    string input;  
    size_t pos;    
};

#endif
