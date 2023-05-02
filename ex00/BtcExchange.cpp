#include "BtcExchange.hpp"

// --------- Constructor and destructor ------------

BtcExchange::BtcExchange(char *infile) {
    std::ifstream   input;
    std::string     line;
    int             i = 0;

    // stock value in container
    _stock_datafile("data.csv");

    // open and check file
    input.open(infile);
    if (!input)
        throw inputFileException();
    if (input.peek() == std::ifstream::traits_type::eof())
        throw emptyFileException();

    // calculate input entries
    while (getline(input, line)) {
        if ((i > 0 && !line.empty()) || (i == 0 && isdigit(line[0]))) {
            try {
                _calculate_exchange(line);
            }
            catch (std::exception& e) {
                std::cerr << "Error input: " << _current_date << ": " << e.what() << std::endl;
            }
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
    int         i = 0;

    if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
        throw dateException();
    for ( std::string::iterator it = date.begin(); it != date.end(); ++it) {
        if (i != 4 && i != 7 && !isdigit(*it))
            throw dateException();
        i++;
    }
}

float BtcExchange::_check_value_format(std::string value) {
    float   f;

    for ( std::string::iterator it = value.begin(); it != value.end(); ++it) {
        if (!(isdigit(*it) || *it == '.' || (it == value.begin() && *it == '-')))
            throw valueException();
    }
    f = atof(value.c_str());
    return (f);
}

std::string BtcExchange::_calculate_exchange(std::string line) {
    std::map<std::string, float>::iterator exchangeFound;
    int             pos;
    float           value;

    // check format
    _current_date = line.substr(0, 10);
    pos = line.find(" | ");
    if (pos != 10)
        throw sepException();
    line.erase(0, 13);
    _check_date_format(_current_date);
    value = _check_value_format(line);
    if (value < 0)
        throw tooLowException();
    else if (value > 1000)
        throw tooHighException();

    // make exchange
    if (_map.find(_current_date) != _map.end()) {
        exchangeFound = _map.find(_current_date);
        std::cout << _current_date << " => " << value << " = " << value * exchangeFound->second << std::endl;
    }
    else {
        exchangeFound = _map.lower_bound(_current_date);
        if (exchangeFound == _map.end() || exchangeFound == _map.begin()) {
            std::cout << "Error: " << _current_date <<  ": Nothing found in database\n";
        } else {
            exchangeFound--;
            std::cout << _current_date << " => " << value << " = " << value * exchangeFound->second << std::endl;
        }
    }
    return (_current_date);
}
// --------- Operator overload ------------

BtcExchange &BtcExchange::operator=(const BtcExchange &instance) {
    this->_current_date = instance._current_date;
    this->_map.insert(instance._map.begin(), instance._map.end());
    return *this;
}