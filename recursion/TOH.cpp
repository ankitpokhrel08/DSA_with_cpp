#include<iostream>
using namespace std;

void TOH(int n, int a, int b, int c);

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n; // Added a prompt for clarity
    int a = 1, b = 2, c = 3;
    TOH(n, a, b, c);
    return 0;
}

void TOH(int n, int a, int b, int c) {
    if (n > 0) {
        TOH(n - 1, a, c, b);
        cout << "Move disk from " << a << " to " << c << endl;
        TOH(n - 1, b, a, c);
    }
}