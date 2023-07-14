#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/' || c == '%')
        return 2;
    else
        return 0;
}

bool isBalancedParentheses(const string& expression) {
    stack<char> parenthesesStack;
    for (char c : expression) {
        if (c == '{' || c == '(' || c == '[') {
            parenthesesStack.push(c);
        }
        else if (c == '}' || c == ')' || c == ']') {
            if (parenthesesStack.empty())
                return false;
            char top = parenthesesStack.top();
            parenthesesStack.pop();
            if ((c == '}' && top != '{') || (c == ')' && top != '(') || (c == ']' && top != '['))
                return false;
        }
    }
    return parenthesesStack.empty();
}

string infixToPostfix(const string& infix) {
    stack<char> operatorStack;
    string postfix = "";
    for (char c : infix) {
        if (isOperator(c)) {
            while (!operatorStack.empty() && isOperator(operatorStack.top()) && getPrecedence(operatorStack.top()) >= getPrecedence(c)) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
        else if (c == '(') {
            operatorStack.push(c);
        }
        else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(')
                operatorStack.pop();
        }
        else {
            postfix += c;
        }
    }
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }
    return postfix;
}

int main() {
    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    if (!isBalancedParentheses(infixExpression)) {
        cout << "Invalid expression! It fails the balanced parentheses check." << endl;
    }
    else {
        string postfixExpression = infixToPostfix(infixExpression);
        cout << "Postfix expression: " << postfixExpression << endl;
    }

    return 0;
}