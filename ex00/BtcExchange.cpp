#include "BtcExchange.hpp"

// --------- Constructor and destructor ------------

BtcExchange::BtcExchange(char *infile) {
    _stock_datafile("data.csv");

    std::ifstream   input;
    std::string     line;
    std::string     date;
    int             pos;
    int             i = 0;
    float           value;

    input.open(infile);
    if (!input)
        throw inputFileException();
    while (getline(input, line)) {
        if (i != 0 || (i == 0 && isdigit(line[0]))) {
            pos = line.find(" | ");
            if (pos != 10)
                throw inputDataException();
            date = line.substr(0, 10);
            _check_date_format(date);
            line.erase(0, 13);
            value = _check_value_format(line);
            if (!(value >= 0 && value <= 1000))
                throw inputDataException();
            _calculate_exchange(date, value);
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
    std::string     date;
    int             pos;
    int             i = 0;
    float           value;

    data.open(file.c_str());
    if (!data)
        throw datafileException();
    while (getline(data, line)) {
        if (i != 0 || (i == 0 && isdigit(line[0]))) {
            pos = line.find(",");
            if (pos != 10)
                throw dataformatException();
            date = line.substr(0, 10);
            _check_date_format(date);
            line.erase(0, 11);
            value = _check_value_format(line);
            this->_map.insert(std::pair<std::string,float>(date, value));  
        }
        i++;
    }
}

void BtcExchange::_check_date_format(std::string date) {
    struct tm   tm;

    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
        throw dataformatException();
}

float BtcExchange::_check_value_format(std::string value) {
    float   f;

    for ( std::string::iterator it = value.begin(); it != value.end(); ++it) {
        if (!(isdigit(*it) || *it == '.'))
            throw dataformatException();
    }
    f = atof(value.c_str());
    return (f);
}

void BtcExchange::_calculate_exchange(std::string date, float value) {
    std::map<std::string, float>::iterator exchangeFound;

    exchangeFound = _map.lower_bound(date);
    if (exchangeFound == _map.end() || exchangeFound == _map.begin()) {
        std::cout << "Nothing found\n";
    } else {
        exchangeFound--;
        std::cout << "date: " << date << ", value: " << value << ", exchange date: " << exchangeFound->first << ", exchange value: " << exchangeFound->second << std::endl;
        std::cout << "The result is: " << value * exchangeFound->second << std::endl;
    }
}
// --------- Operator overload ------------

BtcExchange &BtcExchange::operator=(const BtcExchange &instance) {
    // this->_stack = instance._stack;
    (void) instance;
    return *this;
}