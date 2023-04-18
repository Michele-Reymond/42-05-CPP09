#include <iostream>
#include "BtcExchange.hpp"

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main(int argc, char **argv) {
    if (argc != 2)
        std::cout << "Error: You must enter one argument\n";
    BtcExchange btc(argv[1]);
    return 0;
}

// checker le fait qu'il y aie un argument et que ce soit un fichier OK
// checker la databse OK

// faire un check de la date plus malin qui fonctionne pour les 2 cas

// checker que le format des données correspond à date | value
// checker le format des dates Year-Month-Day.
// checker la valeur: valid value must be either a float or a positive integer between 0 and 1000

// display la reponses: Your program should display on the standard output the result of the value multiplied
// by the exchange rate according to the date indicated in your database.

// If the date used in the input does not exist in your DB then you
// must use the closest date contained in your DB. Be careful to use the
// lower date and not the upper one.