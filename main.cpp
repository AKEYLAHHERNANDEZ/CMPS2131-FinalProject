#include "Scanner.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;

    // Prompt user for an input 
    cout << "Enter An Expression: ";
    getline(cin, input);

    // Initialize Scanner with the user input
    Scanner scanner(input);

    // Get the first token
    Token token = scanner.getNextToken();

    // Loop to process and print each token until input ends
    while (token.type != END_OF_INPUT) {
        cout << "Token Type: ";

        // Switch to handle & display the token type
        switch (token.type) {
            case NUMBER:
                cout << "NUMBER"; 
                break;
            case OPERATOR: 
                cout << "OPERATOR"; 
                break;
            case LeftParen: 
                cout << "LeftParen"; 
                break;
            case RightParen: 
                cout << "RightParen";
                break;
            case UNKNOWN: 
                cout << "UNKNOWN"; 
                break;
            default:
                cout << "OTHER";
        }

        // Print token value
        cout << ", Value: \"" << token.value << "\" \n";

        // Get next token
        token = scanner.getNextToken();
    }

    return 0;
}
