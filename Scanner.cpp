#include "Scanner.h"
#include <cctype>

//Assigns token type and value
Token::Token(TokenType typeOfToken, const string& valueOfToken) {
    type = typeOfToken;
    value = valueOfToken;
}
//Stores input and initializes position
Scanner::Scanner(const string& input) {
    this->input = input;
    pos = 0;
}

// Gets and returns the next token from the input 
Token Scanner::getNextToken() {
    // Skip any whitespace
    while (pos < input.length() && isspace(input[pos])) {
        ++pos;
    }

    //END OF INPUT condition 
    if (pos >= input.length()) {
        return Token(END_OF_INPUT, "");
    }

    char curr = input[pos];

    // Handle negative numbers
    if (curr == '-' && pos + 1 < input.length() && isdigit(input[pos + 1])) {
        string number = "-";
        pos++;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Handle regular numbers
    if (isdigit(curr)) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Handle arithmetic operators
    if (curr == '+' || curr == '-' || curr == '*' || curr == '/') {
        return Token(OPERATOR, string(1, input[pos++]));
    }

    // Handle left parenthesis
    if (curr == '(') {
        return Token(LeftParen, string(1, input[pos++]));
    }

    // Handle right parenthesis
    if (curr == ')') {
        return Token(RightParen, string(1, input[pos++]));
    }

    // Handle unknown & invalid characters
    string unknown;
    while (pos < input.length() && !isdigit(input[pos]) &&
           !isspace(input[pos]) && input[pos] != '+' && input[pos] != '-' &&
           input[pos] != '*' && input[pos] != '/' &&
           input[pos] != '(' && input[pos] != ')') {
        unknown += input[pos++];
    }
    return Token(UNKNOWN, unknown);
}
