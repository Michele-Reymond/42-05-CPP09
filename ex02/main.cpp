#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "Error: You must enter arguments\n";
    try {
        if (argc > 2)
            PmergeMe sort_comp(argv, argc);
        // else
        //     PmergeMe sort_comp(argv);
    }
    catch (std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
        // delete TAB here
    }
    return 0;
}

// TO DO

// 1. little parsing and error handling
// 2. utiliser un vector container et faire un algo de tri
// 3. Faire un algo de tri pour un 2eme container (deque? list?)
// 4. implementer le timer

// sort
// timer
// insertion binary search
// 