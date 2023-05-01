#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <ctime>

#define DOUBLES 1

class PmergeMe {
    public:
        PmergeMe(char **args, int argc);
        PmergeMe(const PmergeMe& instance);
        virtual ~PmergeMe();

        PmergeMe &operator=(const PmergeMe &instance);

        void    print_pairs();
        void    print_sorted_vector();
        void    print_sorted_list();
        void    print_unsorted();
        void    print_vtime();
        void    print_ltime();

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
        std::clock_t                            _vStart;
        double                                  _vTime;
        std::list<std::pair<int, int> >         _list;
        std::list<int>                          _sortedList;
        std::clock_t                            _lStart;
        double                                  _lTime;
        int                                     *_tab;
        int                                     _argc;

        void    _check_arg(char *arg);
        void    _sort_vector();
        void    _sort_list();
};

#endif