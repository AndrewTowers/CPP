#include "Harl.hpp"

static int getLevel(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <level>" << std::endl;
        return 1;
    }
    Harl harl;
    
    switch (getLevel(argv[1])) {
        case 0:
            std::cout << "[DEBUG]" << std::endl;
            harl.complain("DEBUG");
            std::cout << std::endl;
        case 1:
            std::cout << "[INFO]" << std::endl;
            harl.complain("INFO");
            std::cout << std::endl;
        case 2:
            std::cout << "[WARNING]" << std::endl;
            harl.complain("WARNING");
            std::cout << std::endl;
        case 3:
            std::cout << "[ERROR]" << std::endl;
            harl.complain("ERROR");
            std::cout << std::endl;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    return 0;
}