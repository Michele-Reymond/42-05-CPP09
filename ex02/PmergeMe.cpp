#include "PmergeMe.hpp"

// --------- Constructor and destructor ------------

PmergeMe::PmergeMe(char **args, int argc) {
    _tab = new int[argc - 1];
    // check args and doubles
    for (int i = 1; i < argc; i++) {
        _check_arg(args[i]);

        int k = atoi(args[i]);
        for (int j = 0; j < i; j++) {
            if (k == _tab[j])
                throw PmergeMe::doubleException();
        }
        _tab[i - 1] = k;
    }

    // sort both containers
    _sort_vector(argc - 1);

    
    // CONTAINER 2
}

//  std::pair<int, int> pair(args[i], args[i - 1]);

// PmergeMe::PmergeMe(char *arg) {

//         // throw operandException();
// }

PmergeMe::PmergeMe(const PmergeMe &instance) {
    *this = instance;
}

PmergeMe::~PmergeMe() { delete _tab; }

// --------- Member functions ------------

void    PmergeMe::_check_arg(char *arg) {
    long    l_arg;

    l_arg = atol(arg);
    if (l_arg > std::numeric_limits<int>::max())
        throw PmergeMe::limitException();
    else if (l_arg < 0)
        throw PmergeMe::negativeException();
    for (int i = 0; arg[i] != '\0'; i ++) {
        if (!isdigit(arg[i]))
             throw PmergeMe::notDigitException();
    }
}

void PmergeMe::_sort_vector(int argc) {

    // start timer TO DO

    // create pairs
    for (int i = 0; i < argc; i++) {
        if (i + 1 == argc)
            _vector.push_back(std::make_pair(-1, _tab[i]));
        else
            _vector.push_back(std::make_pair(_tab[i], _tab[i + 1]));
        i++;
    }

    // swap pairs
    for (std::vector< std::pair<int, int> >::iterator it = _vector.begin(); it != _vector.end(); it++) {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
        std::cout << "{" << (*it).first << ", " << (*it).second << "} ";
    }
    std::cout << std::endl;
}

// --------- Operator overload ------------

PmergeMe &PmergeMe::operator=(const PmergeMe &instance) {
    (void) instance;
    return *this;
}