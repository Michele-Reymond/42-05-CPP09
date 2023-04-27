#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <utility>
#include <cstdlib>
#include <algorithm>

class PmergeMe {
    public:
        PmergeMe(char **args, int argc); // constructeur plusieurs args
        PmergeMe(char *arg); // constructeur string d'args
        PmergeMe(const PmergeMe& instance);
        virtual ~PmergeMe();

        PmergeMe &operator=(const PmergeMe &instance);

        void    print_pairs();
        void    print_sorted_vector();

        class limitException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "An argument is greater than max_int";
                }
        };

        class negativeException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Arguments must be postivie integers";
                }
        };

        class notDigitException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Arguments must be digits";
                }
        };

        class doubleException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "There can't be 2 same numbers";
                }
        };

    private:
        std::vector<std::pair<int, int> >       _vector;
        std::vector<int>                        _sortedVector;
        int                                     *_tab;
        // CONTAINER 2

        void    _check_arg(char *arg);
        void    _sort_vector(int argc);
};

#endif