#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>
using namespace std;
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOperator(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b != 0) {
            return a / b;
        }
        else {
            std::cerr << "Error: Division by zero\n";
            exit(1);
        }
    default: return 0;
    }
}

int evaluateExpression(std::istringstream& iss) {
    stack<int> numbers;
    stack<char> operations;

    char currentChar;
    while (iss >> currentChar) {
        if (isdigit(currentChar)) {
            iss.putback(currentChar);
            int number;
            iss >> number;
            numbers.push(number);
        }
        else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            while (!operations.empty() && getPriority(operations.top()) >= getPriority(currentChar)) {
                int b = numbers.top(); numbers.pop();
                int a = numbers.top(); numbers.pop();
                char op = operations.top(); operations.pop();
                numbers.push(applyOperator(a, b, op));
            }
            operations.push(currentChar);
        }
        else if (currentChar == '(') {
            operations.push(currentChar);
        }
        else if (currentChar == ')') {
            while (operations.top() != '(') {
                int b = numbers.top(); numbers.pop();
                int a = numbers.top(); numbers.pop();
                char op = operations.top(); operations.pop();
                numbers.push(applyOperator(a, b, op));
            }
            operations.pop(); 
        }
    }

    while (!operations.empty()) {
        int b = numbers.top(); numbers.pop();
        int a = numbers.top(); numbers.pop();
        char op = operations.top(); operations.pop();
        numbers.push(applyOperator(a, b, op));
    }

    return numbers.top();
}

int main() {
    char* expression[255];
    cout << "Enter an arithmetic expression: ";
    getline(std::cin, expression);

    istringstream iss(expression);
    int result = evaluateExpression(iss);

    cout << "Result: " << result << std::endl;

}
}
