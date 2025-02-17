#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int evaluatePostfix(string expression) {
    stack<int> s;
    stringstream ss(expression);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        } else {
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();
            switch (token[0]) {
                case '+': s.push(val2 + val1); break;
                case '-': s.push(val2 - val1); break;
                case '*': s.push(val2 * val1); break;
                case '/': s.push(val2 / val1); break;
                case '%': s.push(val2 % val1); break;
                case '^': s.push(pow(val2, val1)); break;
                case '$': s.push(pow(val2, val1)); break;
            }
        }
    }
    return s.top();
}

int evaluatePrefix(string expression) {
    stack<int> s;
    reverse(expression.begin(), expression.end());
    stringstream ss(expression);
    string token;
    vector<string> tokens;

    while (ss >> token) {
        tokens.push_back(token);
    }

    reverse(tokens.begin(), tokens.end());

    for (string& token : tokens) {
        if (isdigit(token[0])) {
            s.push(stoi(token));
        } else {
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();
            switch (token[0]) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '%': s.push(val1 % val2); break;
                case '^': s.push(pow(val1, val2)); break;
                case '$': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top();
}

int main() {
    string expression;
    char choice;

    cout << "Enter 'p' for postfix evaluation or 'r' for prefix evaluation: ";
    cin >> choice;
    cin.ignore(); // Ignore the newline character after the choice input
    cout << "Enter the expression (space-separated): ";
    getline(cin, expression);

    if (choice == 'p') {
        cout << "Result: " << evaluatePostfix(expression) << endl;
    } else if (choice == 'r') {
        cout << "Result: " << evaluatePrefix(expression) << endl;
    } else {
        cout << "Invalid choice" << endl;
    }

    return 0;
}
