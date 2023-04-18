#ifndef BTCEXCHANGE_HPP
# define BTCEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>

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

        class inputException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return "There is a problem with the input file: check that the file exist!";	
                }
        };

    private:
        std::map<std::string, float> _map;

        void        _stock_datafile(std::string file);
        void        _check_date_format(std::string date);
};

#endif