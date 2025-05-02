#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void scanDigit(const string& input) {
   if (input.length() != 1) {
       cout << "Error: Input must be a single character." << endl;
       return;
  }
   char c = input[0];
    if (isdigit(c)) {
      cout << "Valid digit: " << c << endl;
    } else {
       cout << "Error: '" << c << "' is not a valid digit (0-9)." << endl;
    }
}


int main() {
    string input;
    cout << "Enter a single character: ";
    cin >> input;

    scanDigit(input);

    return 0;
}

