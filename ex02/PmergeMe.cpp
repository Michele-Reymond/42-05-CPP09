#include "PmergeMe.hpp"

// --------- Constructor and destructor ------------

PmergeMe::PmergeMe(char **args, int argc) : _argc(argc) {
    _tab = new int[_argc - 1];

    // check args and doubles
    for (int i = 1; i < _argc; i++) {
        _check_arg(args[i]);

        int k = atoi(args[i]);
        for (int j = 0; j < i; j++) {
            if (k == _tab[j] && !DOUBLES) {
                delete _tab;
                throw PmergeMe::doubleException();
            }
        }
        _tab[i - 1] = k;
    }

    // sort both containers
    _sort_vector();
    _sort_list();
}

PmergeMe::PmergeMe(const PmergeMe &instance) {
    *this = instance;
}

PmergeMe::~PmergeMe() { delete _tab; }

// --------- Member functions ------------

void    PmergeMe::print_unsorted() {
    std::cout << "Before: ";
    for (int i = 0; i < _argc - 1; i++) {
        std::cout << _tab[i] << " ";
    }
    std::cout << std::endl;
}

void    PmergeMe::print_pairs() {
    if (_vector.empty())
        std::cout << "vector is empty!" << std::endl;
    else {
        for (std::vector< std::pair<int, int> >::iterator it = _vector.begin(); it != _vector.end(); it++) {
            std::cout << "{" << (*it).first << ", " << (*it).second << "} ";
        }
        std::cout << std::endl;
    }
}

void    PmergeMe::print_sorted_vector() {
    if (_sortedVector.empty())
        std::cout << "vector is empty!" << std::endl;
    else {
        std::cout << "After: ";
        for (std::vector< int >::iterator it = _sortedVector.begin(); it != _sortedVector.end(); it++) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }
}

void    PmergeMe::print_sorted_list() {
    if (_sortedList.empty())
        std::cout << "List is empty!" << std::endl;
    else {
        std::cout << "After: ";
        for (std::list< int >::iterator it = _sortedList.begin(); it != _sortedList.end(); it++) {
            std::cout << (*it) << " ";
        }
        std::cout << std::endl;
    }
}

void    PmergeMe::print_vtime() {
    std::cout << "Time to process a range of " << _argc - 1 << " elements with std::vector : " << _vTime << " us\n";
}

void    PmergeMe::print_ltime() {
    std::cout << "Time to process a range of " << _argc - 1 << " elements with std::list : " << _lTime << " us\n";
}

void    PmergeMe::_check_arg(char *arg) {
    long    l_arg;

    l_arg = atol(arg);
    if (l_arg > std::numeric_limits<int>::max()) {
        delete _tab;
        throw PmergeMe::limitException();
    }
    else if (l_arg < 0) {
        delete _tab;
        throw PmergeMe::negativeException();
    }
    for (int i = 0; arg[i] != '\0'; i ++) {
        if (!isdigit(arg[i]))
        {
            delete _tab;
            throw PmergeMe::notDigitException();
        }
    }
}

void PmergeMe::_sort_vector() {

    // start timer
    _vStart = clock();

    // create pairs
    for (int i = 0; i < _argc - 1; i++) {
        if (i + 1 == _argc - 1)
            _vector.push_back(std::make_pair(-1, _tab[i]));
        else
            _vector.push_back(std::make_pair(_tab[i], _tab[i + 1]));
        i++;
    }

    // swap pairs
    for (std::vector< std::pair<int, int> >::iterator it = _vector.begin(); it != _vector.end(); it++) {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }

    // sort first element in pairs
    for (std::vector< std::pair<int, int> >::iterator it = _vector.begin() + 1; it != _vector.end(); it++) {
        std::vector< std::pair<int, int> >::iterator actual = it;
        std::vector< std::pair<int, int> >::iterator prev = it - 1;
        while ((*actual).first < (*prev).first) {
            std::swap(*actual, *prev);
            if (prev != _vector.begin()) {
                actual = prev;
                prev = actual - 1;
            }
        }
    }

    // push sorted first elem in def vector
    for (std::vector< std::pair<int, int> >::iterator it = _vector.begin(); it != _vector.end(); it++) {
        if ((*it).first != -1)
            _sortedVector.push_back((*it).first);
    }

    // insert second elem in def vector
    for (std::vector< std::pair<int, int> >::iterator it = _vector.begin(); it != _vector.end(); it++) {
        std::vector<int>::iterator low;

        low = std::lower_bound (_sortedVector.begin(), _sortedVector.end(), (*it).second);
        _sortedVector.insert(low, (*it).second);
    }

    // stop timer
    _vTime = (clock() - _vStart ) * 1000000/CLOCKS_PER_SEC;
}

// LIST

void PmergeMe::_sort_list() {

    // start timer
    _lStart = clock();

    // create pairs
    for (int i = 0; i < _argc - 1; i++) {
        if (i + 1 == _argc - 1)
            _list.push_back(std::make_pair(-1, _tab[i]));
        else
            _list.push_back(std::make_pair(_tab[i], _tab[i + 1]));
        i++;
    }

    // swap pairs
    for (std::list< std::pair<int, int> >::iterator it = _list.begin(); it != _list.end(); it++) {
        if ((*it).first > (*it).second)
            std::swap((*it).first, (*it).second);
    }


    // sort first element in pairs
    std::list< std::pair<int, int> >::iterator it = _list.begin();
    for (++it; it != _list.end(); it++) {
        std::list< std::pair<int, int> >::iterator actual = it;
        std::list< std::pair<int, int> >::iterator prev = it;
        prev--;
        while ((*actual).first < (*prev).first) {
            std::swap(*actual, *prev);
            if (prev != _list.begin()) {
                actual = prev;
                prev = actual;
                prev--;
            }
        }
    }

    // push sorted first elem in def vector
    for (std::list< std::pair<int, int> >::iterator it = _list.begin(); it != _list.end(); it++) {
        if ((*it).first != -1)
            _sortedList.push_back((*it).first);
    }

    // insert second elem in def vector
    for (std::list< std::pair<int, int> >::iterator it = _list.begin(); it != _list.end(); it++) {
        std::list<int>::iterator low;

        low = std::lower_bound (_sortedList.begin(), _sortedList.end(), (*it).second);
        _sortedList.insert(low, (*it).second);
    }

    // stop timer
    _lTime = (clock() - _lStart ) * 1000000/CLOCKS_PER_SEC;
}

// --------- Operator overload ------------

PmergeMe &PmergeMe::operator=(const PmergeMe &instance) {
    _vStart = instance._vStart;
    _vTime = instance._vTime;
    _lStart = instance._lStart;
    _lTime = instance._lTime;
    _argc = instance._argc;

    for (std::vector< std::pair<int, int> >::const_iterator it = instance._vector.begin(); it != instance._vector.end(); it++) {
        _vector.push_back(std::make_pair((*it).first, (*it).second));
    } 
    for (std::list< std::pair<int, int> >::const_iterator it = instance._list.begin(); it != instance._list.end(); it++) {
        _list.push_back(std::make_pair((*it).first, (*it).second));
    } 
    for (std::vector< int >::const_iterator it = instance._sortedVector.begin(); it != instance._sortedVector.end(); it++) {
        _sortedVector.push_back(*it);
    } 
    for (std::list< int >::const_iterator it = instance._sortedList.begin(); it != instance._sortedList.end(); it++) {
        _sortedList.push_back(*it);
    } 
    _tab = new int[_argc - 1];
    for (int i = 0; i < _argc - 1; i++) {
        _tab[i] = instance._tab[i];
    }
    return *this;
}