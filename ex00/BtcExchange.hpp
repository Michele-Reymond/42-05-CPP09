#ifndef BTCEXCHANGE_HPP
# define BTCEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

class BtcExchange {
    public:
        BtcExchange(char *infile);
        BtcExchange(const BtcExchange& instance);
        virtual ~BtcExchange();

        BtcExchange &operator=(const BtcExchange &instance);

        class datafileException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "There is a problem with the data file: check if data.csv exist!";	
                }
        };

        class dataformatException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "There is a problem with the data file: check that the datas are cleaned!";	
                }
        };

        class inputFileException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "There is a problem with the input file: check that the file exist!";	
                }
        };

        class emptyFileException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The input file is empty";	
                }
        };

        class valueException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The value is not conform!";	
                }
        };

        class dateException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "The date format is not conform: Year-Month-Day";	
                }
        };

        class sepException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Format of data must be \"date | value\"";	
                }
        };
        
        class tooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Value can't be negative";	
                }
        };
        
        class tooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "Value is too high. The limit is 1000";	
                }
        };

    private:
        std::map<std::string, float>    _map;
        std::string                     _current_date;

        std::string _calculate_exchange(std::string line);
        void        _stock_datafile(std::string file);
        void        _check_date_format(std::string date);
        float       _check_value_format(std::string value);
};

#endif