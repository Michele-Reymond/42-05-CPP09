#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "Error: You must enter arguments\n";
    else if (argc == 2)
        std::cout << "Error: You must enter at least 2 arguments\n";
    else {
        try {
            PmergeMe sort_comp(argv, argc);

            sort_comp.print_unsorted();
            sort_comp.print_sorted_vector();
            // sort_comp.print_sorted_list();
            sort_comp.print_vtime();
            sort_comp.print_ltime();
        }
        catch (std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    return 0;
}
