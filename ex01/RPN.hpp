#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stack>
#include <cstring>

enum what {
    Spaces,
    Operand,
    Number,
    Error
};

class RPN {
    public:
        RPN(char *args);
        RPN(const RPN& instance);
        virtual ~RPN();

        RPN &operator=(const RPN &instance);

        float result();

        class formatException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The argument you enter is in the wrong format";	
                }
        };

        class calculException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "This operation isn't correct";
                }
        };

        class operandException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "There is no operands in the operation";
                }
        };

    private:
        std::stack<float> _stack;

        int      _what_is_that(char c);
        float    _operate(float &a, float &b, char c);
};

#endif