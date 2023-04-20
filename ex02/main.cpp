#include <iostream>

#define COLOR_RESET     "\x1b[0m"
#define COLOR           "\x1b[2m"

int main(int argc, char **argv) {
    if (argc < 2)
        std::cout << "Error: You must enter arguments\n";
    return 0;
}

// TO DO

// 1. little parsing and error handling
// 2. utiliser un vector container et faire un algo de tri
// 3. Faire un algo de tri pour un 2eme container (deque? list?)
// 4. implementer le timer