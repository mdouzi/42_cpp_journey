#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <iostream>

// Reverse polish nation implementation

int RPN::evaluate(const std::string& expression) {
    std::istringstream iss(expression);
    std::stack<int> operands;
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            operands.push(std::stoi(token));
        } else if (isOperator(token[0])) {
            if (operands.size() < 2) {
                std::cerr << "Error: Insufficient operands for operator " << token << std::endl;
                return 0;
            }
            int b = operands.top();
            operands.pop();
            int a = operands.top();
            operands.pop();
            int result = applyOperator(a, b, token[0]);
            operands.push(result);
        } else {
            std::cerr << "Error: Invalid token " << token << std::endl;
            return 0;
        }
    }

    if (operands.size() != 1) {
        std::cerr << "Error: Invalid expression" << std::endl;
        return 0;
    }

    return operands.top();
}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(int a, int b, char op) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b == 0) {
                std::cerr << "Error: Division by zero" << std::endl;
                return 0;
            }
            return a / b;
        default:
            std::cerr << "Error: Invalid operator " << op << std::endl;
            return 0;
    }
}
