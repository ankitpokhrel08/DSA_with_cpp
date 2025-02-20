#include <iostream>
#include <cctype>
using namespace std;

// Function to convert prefix to postfix
string prefixToPostfix(string &prefix, int &index) {
    char ch = prefix[index++];
    
    // Base case: If it's an operand, return as is
    if (isalnum(ch)) {
        return string(1, ch);
    }

    // Recursive case: It's an operator, process left and right operands
    string left = prefixToPostfix(prefix, index);
    string right = prefixToPostfix(prefix, index);

    // Construct postfix expression
    return left + right + ch;
}

int main() {
    string prefix = "*+AB-CD"; 
    int index = 0;
    
    string postfix = prefixToPostfix(prefix, index);
    cout << "Postfix: " << postfix << endl;  // Expected Output: "AB+CD-*"

    return 0;
}