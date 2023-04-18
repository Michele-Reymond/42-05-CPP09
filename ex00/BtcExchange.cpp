#include "BtcExchange.hpp"

// --------- Constructor and destructor ------------

BtcExchange::BtcExchange(char *infile) {
    _stock_datafile("data.csv");

    std::ifstream   input;
    std::string     line;
    std::string     key;
    int             i = 0;

    input.open(infile);
    if (!input)
        throw inputException();
    while (getline(input, line)) {
        if (i != 0 || (i == 0 && isdigit(line[0]))) {
            // _check_date_format(line);
            // key = line.substr(0, 10);
            // line.erase(0,10);
            // this->_map.insert(std::pair<std::string,float>(key, atof(line.c_str())));  
        }
        i++;
    }
}

BtcExchange::BtcExchange(const BtcExchange &instance) {
    *this = instance;
}

BtcExchange::~BtcExchange() {}

// --------- Member functions ------------

void BtcExchange::_stock_datafile(std::string file) {
    std::ifstream   data;
    std::string     line;
    std::string     key;
    int             i = 0;

    data.open(file.c_str());
    if (!data)
         throw datafileException();
    while (getline(data, line)) {
        if (i != 0 || (i == 0 && isdigit(line[0]))) {
            // _check_date_format(line);
            key = line.substr(0, 10);
            line.erase(0,10);
            this->_map.insert(std::pair<std::string,float>(key, atof(line.c_str())));  
        }
        i++;
    }
}

void BtcExchange::_check_date_format(std::string date) {
    int i = 0;

    for ( std::string::iterator it = date.begin(); it != date.end(); ++it) {
        if ((i == 4 || i == 7) && *it != '-')
            throw dataformatException();
        else if (i == 10 && *it != ',')
            throw dataformatException();
        else if (i < 10 && i != 4 && i != 7 && !isdigit(*it))
            throw dataformatException();
        else if (i > 10 && !(isdigit(*it) || *it == '.'))
            throw dataformatException();
        i++;
    }
}


// --------- Operator overload ------------

BtcExchange &BtcExchange::operator=(const BtcExchange &instance) {
    // this->_stack = instance._stack;
    (void) instance;
    return *this;
}