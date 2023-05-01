#include <iostream>
#include "BtcExchange.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
        std::cerr << "Error: You must enter one argument\n";
    try {
        BtcExchange btc(argv[1]);
    }
    catch (std::exception& e) {
        std::cerr << "Error with files: " << e.what() << std::endl;
    }
    return 0;
}

// faire l'operateur de copie !!!