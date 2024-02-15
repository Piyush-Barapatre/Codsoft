#include <iostream>

using namespace std;

int main()
{
    double num1, num2;
    char operation;

    cout << "Welcome to the calculator! Please enter two numbers and an operation (+, -, *, /): ";
    cin >> num1 >> num2 >> operation;

    switch (operation) {
        case '+':
            cout << "The sum is: " << num1 + num2 << endl;
            break;
        case '-':
            if (num2 > num1) {
                cout << "Error: The second number cannot be greater than the first number for subtraction." << endl;
            } else {
                cout << "The difference is: " << num1 - num2 << endl;
            }
            break;
        case '*':
            cout << "The product is: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            } else {
                cout << "The quotient is: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Error: Invalid operation." << endl;
            break;
    }

    return 0;
}
