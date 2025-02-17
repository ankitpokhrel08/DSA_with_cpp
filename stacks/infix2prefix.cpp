#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    if (op == '^' || op == '$') return 3;
    return 0;
}

bool isRightAssociative(char op) {
    return op == '^' || op == '$';
}

string infixToPrefix(string infix) {
    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Replace '(' with ')' and vice versa
    for (char& ch : infix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    // Convert to postfix
    stack<char> s;
    string prefix = "";

    for (char& ch : infix) {
        if (isalnum(ch)) {
            prefix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                prefix += s.top();
                s.pop();
            }
            s.pop(); // pop '('
        } else {
            while (!s.empty() && (precedence(s.top()) > precedence(ch) && !isRightAssociative(ch))) {
                prefix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    while (!s.empty()) {
        prefix += s.top();
        s.pop();
    }

    // Reverse the postfix expression to get the prefix expression
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
