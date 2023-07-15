#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;

public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Error: Queue is empty." << std::endl;
            return -1; // Assuming -1 represents an error value
        }
        Node* temp = front;
        int value = temp->data;
        front = front->next;
        delete temp;
        size--;
        if (isEmpty()) {
            rear = nullptr;
        }
        return value;
    }

    int getFront() {
        if (isEmpty()) {
            std::cerr << "Queue is empty." << std::endl;
            return -1; // Assuming -1 represents an error value
        }
        return front->data;
    }

    bool isEmpty() {
        return (size == 0);
    }

    int getSize() {
        return size;
    }
};

bool isBalanced(const string& expression) {
    stack<char> st;
    for (char c : expression) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                return false;
            }
        }
    }
    return st.empty();
}

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to get the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0;
}

// Function to convert infix to postfix notation
string infixToPostfix(string infix) {
    stack<char> operatorStack;
    string postfix;
    unordered_map<char, int> precedence;

    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // Add operand directly to postfix expression
        }
        else if (c == '(') {
            operatorStack.push('(');
        }
        else if (c == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.pop(); // Pop '(' from the stack
        }
        else if (isOperator(c)) {
            while (!operatorStack.empty() && precedence[c] <= precedence[operatorStack.top()]) {
                postfix += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(c);
        }
    }

    // Pop any remaining operators from the stack
    while (!operatorStack.empty()) {
        postfix += operatorStack.top();
        operatorStack.pop();
    }

    return postfix;
}

int main() {

    Queue queue;

    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << "Front element: " << queue.getFront() << endl;
    cout << "Size: " << queue.getSize() << endl;

    int dequeued = queue.dequeue();
    cout << "Dequeued element: " << dequeued << endl;

    cout << "Front element: " << queue.getFront() << endl;
    cout << "Size: " << queue.getSize() << endl;

    string infixExpression;
    cout << "Enter an infix expression: ";
    getline(cin, infixExpression);

    if (!isBalanced(infixExpression)) {
        cout << "Not Balanced. Try again. " << endl;
        return 0;
    }

    string postfixExpression = infixToPostfix(infixExpression);
    cout << "Postfix expression: " << postfixExpression << endl;

    return 0;
}
