#include "Scanner.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
   string input;
   cout << "Enter expression: ";
  getline(cin, input);

    Scanner scanner(input);
    Token token = scanner.getNextToken();

    while (token.type != END_OF_INPUT) {
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER:cout << "NUMBER"; break;
            case OPERATOR: cout << "OPERATOR"; break;
            case LPAREN: cout << "LPAREN"; break;
            case RPAREN: cout << "RPAREN"; break;
            case UNKNOWN: cout << "UNKNOWN"; break;
            default:cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";

        token = scanner.getNextToken();
    }

    return 0;
}
