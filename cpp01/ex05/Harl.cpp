#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug(void) {
    std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void) {
    std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You don't put enough bacon in my burger!" << std::endl;
}

void Harl::warning(void) {
    std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I have been coming here for years!" << std::endl;
}

void Harl::error(void) {
    std::cout << "[ERROR] This is unacceptable! I want to speak to the manager now!" << std::endl;
}

void Harl::complain(std::string level) {
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*func[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*func[i])();
            return;
        }
    }
}
