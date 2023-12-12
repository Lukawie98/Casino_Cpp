#include "menu.hpp"
#include <iostream>

void Menu::displayBalanceSelection() const
{
        std::cout << "Choose the account balance you want to start with:\n"
                  << "1 - Start with $500\n"
                  << "2 - Start with $1000\n"
                  << "3 - Start with $2000\n"
                  << "4 - Start with $5000\n"
                  << "Enter: ";
    
}

void Menu::displayPlayerNumMenu() const
{
        std::cout << "Choose the number of players on the board (3-5): \n"
                  << "3 - Game for three players\n"
                  << "4 - Game for four players\n"
                  << "5 - Game for five players\n"
                  << "0 - Exit\n"
                  << "Enter: ";

}

void Menu::displayOptionsForBets() const
{
     std::cout  << "\n1 - Golden Bet!\n"
                << "2 - Less than 7\n"
                << "3 - Less than 5\n"
                << "4 - Less than 3\n"
                << "5 - More than 3\n"
                << "6 - More than 5\n"
                << "7 - More than 7\n"
                << "Choose the option: \n";
}