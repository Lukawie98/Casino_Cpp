#include "player.hpp"

Player::Player(
        std::string name,
        int accBalance)
    : name_(name)               
    , accBalance_(accBalance)
{}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////    

void Player::show() const
{
    std::cout<<name_<<": $"<< accBalance_;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
void Player::displayName() const
{
    std::cout << name_;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void Player::setName()
{
    std::string name;
    std::cin >> name;
    name_ = name;
}

std::string Player::getName() const
{
    return name_;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void Player::setAccBalance(int accBalance)
{
    accBalance_ = accBalance;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

int Player::getAccBalance() const
{
    return accBalance_;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void Player::setBetNumber()
{
    std::cin >> betNumber_;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

int Player::getBetNumber() const
{
    return betNumber_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void Player::setBetAmount()
{
    std::cin >> betAmount_;
    checkingIfBetIsTooHigh(); 

    accBalance_ -= betAmount_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void Player::checkingIfBetIsTooHigh()
{
     while(betAmount_ > accBalance_)
    {
        std::cout << "Not enough funds in the account, try one more time:";
        std::cin >> betAmount_;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

int Player::getBetAmount() const
{
    return betAmount_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void Player::addToAccBalance(int wonBet)
{
    accBalance_ += wonBet;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void Player::setBetOption()
{
    std::cin >> betOption_;
    
    while(betOption_ < '1' || betOption_ > '7')
    {
        std::cout << "You have to choose option: 1 - 7\nTry one more time:";
        std::cin >> betOption_;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

char Player::getBetOption() const
{
    return betOption_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

int Player::getOptionSwitch() const
{
    return optionSwitch_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void Player::setOptionSwitch(int optionSwitch)
{
    optionSwitch_ = optionSwitch;
}