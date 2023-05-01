#include <iostream>
#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        std::cout << "Error: You must enter only one argument\n";
    try {
        RPN rpn(argv[1]);
        std::cout << "result: " << rpn.result() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}