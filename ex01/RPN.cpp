#include "RPN.hpp"

// --------- Constructor and destructor ------------

RPN::RPN(char *args) {
    int     what;
    float   a, b;
    char    c[2];

    c[1] = '\0';
    for (int i = 0; args[i] != '\0'; i++) {
        what = _what_is_that(args[i]);
        if (what == Number) {
            c[0] = args[i];
            this->_stack.push(atof(c));
        }
        else if (what == Operand) {
            if (this->_stack.size() < 2)
                throw calculException();
            b = this->_stack.top();
            this->_stack.pop();
            a = this->_stack.top();
            this->_stack.pop();
            this->_stack.push(_operate(a, b, args[i]));
        }
        else if (what == Error)
            throw formatException();
    }
    if (this->_stack.size() > 1 || strlen(args) < 2)
        throw operandException();
}

RPN::RPN(const RPN &instance) {
    *this = instance;
}

RPN::~RPN() {}

// --------- Member functions ------------

float RPN::result() {
    return (this->_stack.top());
}

float RPN::_operate(float &a, float &b, char c) {
    if (c == '+')
        return a + b;
    else if (c == '-')
        return a - b;
    else if (c == '*')
        return a * b;
    else
        return a / b;
}

int RPN::_what_is_that(char c) {
    char op[4] = {'+', '-', '/', '*'};
    char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    if (isspace(c) != 0)
        return Spaces;
    for (int i = 0; i < 4; i++) {
        if (c == op[i])
            return Operand;
    }
    for (int i = 0; i < 10; i++) {
        if (c == num[i])
            return Number;
    }
    return Error;
}


// --------- Operator overload ------------

RPN &RPN::operator=(const RPN &instance) {
    this->_stack = instance._stack;
    return *this;
}