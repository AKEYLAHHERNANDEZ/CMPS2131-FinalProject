#include <cctype>  
#include <iostream>
#include <vector>
using namespace std;

enum TokenType {
    NUMBER,
    UNKNOWN,
    END_OF_INPUT
};

struct Token {
    TokenType type;
    string value;

    Token(TokenType typeOfToken, const string& valueOfToken) {
        type = typeOfToken;
        value = valueOfToken;
    }
};

Token getNextToken(const string& input, size_t& pos);

int main() {
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    size_t position = 0;
    vector<Token> tokens;

    while (true) {
        Token token = getNextToken(input, position);
        if (token.type == END_OF_INPUT) {
            break;
        }
        tokens.push_back(token);
    }

    for (const Token& token : tokens) {
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER:
                cout << "NUMBER";
                break;
            case UNKNOWN:
                cout << "UNKNOWN";
                break;
            default:
                cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}

Token getNextToken(const string& input, size_t& pos) {
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }

    if (pos >= input.length()) {
        return Token(END_OF_INPUT, "");
    }

    // Check for a negative number
    char curr = input[pos]; 
   if(curr == '-' && pos + 1 < input.length()
      && isdigit(input[pos + 1])) { 
          string number;
          number += curr;
          while(pos < input.length() && isdigit(input[pos])) {
              number += input[pos];
              pos++;
           }
           return Token(NUMBER, number);
   }

    // Check for a positive number
    if (isdigit(input[pos])) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos];
            pos++;
        }
        return Token(NUMBER, number);
    }

    string unknown;
    while (pos < input.length() && !isdigit(input[pos]) && !isspace(input[pos])) {
        unknown += input[pos];
        pos++;
    }
    return Token(UNKNOWN, unknown);
}


//fix this code
//finish code so it recognise expressions like -7(5+7)-2*7+5
//aslo the grammar + scanner - use tesxt file  the break down 
//rewrite the scanner  to use  a scanner class 