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

        class inputDataException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "There is a problem with the input file: check that the datas are cleaned!";	
                }
        };

    private:
        std::map<std::string, float> _map;

        void        _calculate_exchange(std::string date, float value);
        void        _stock_datafile(std::string file);
        void        _check_date_format(std::string date);
        float       _check_value_format(std::string value);
};

#endif