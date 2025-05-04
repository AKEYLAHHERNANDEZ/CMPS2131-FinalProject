#include "Scanner.h"
#include <cctype>

Token::Token(TokenType typeOfToken, const string& valueOfToken)
    : type(typeOfToken), value(valueOfToken) {}

Scanner::Scanner(const string& input) : input(input), pos(0) {}

Token Scanner::getNextToken() {
    while (pos < input.length() && isspace(input[pos])) {
        ++pos;
    }

    if (pos >= input.length()) {
        return Token(END_OF_INPUT, "");
    }

    char curr = input[pos];

    // Handle numbers (including negative)
    if (curr == '-' && pos + 1 < input.length() && isdigit(input[pos + 1])) {
        string number = "-";
        pos++;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    if (isdigit(curr)) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Handle operators and parentheses
    if (curr == '+' || curr == '-' || curr == '*' || curr == '/') {
        return Token(OPERATOR, string(1, input[pos++]));
    }

    if (curr == '(') {
        return Token(LeftParen, string(1, input[pos++]));
    }

    if (curr == ')') {
        return Token(RightParen, string(1, input[pos++]));
    }

    // Handle unknown characters
    string unknown;
    while (pos < input.length() && !isdigit(input[pos]) &&
           !isspace(input[pos]) && input[pos] != '+' && input[pos] != '-' &&
           input[pos] != '*' && input[pos] != '/' &&
           input[pos] != '(' && input[pos] != ')') {
        unknown += input[pos++];
    }
    return Token(UNKNOWN, unknown);
}


//fix this code
//finish code so it recognise expressions like -7(5+7)-2*7+5
//aslo the grammar + scanner - use tesxt file  the break down 
//rewrite the scanner  to use  a scanner class 