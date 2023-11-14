#pragma once

#include <string>
#include <iostream>

class Player
{
    std::string name_ {""};          //player name
    int accBalance_{0};    //player's account balance
    unsigned int betNumber_ {0};             //number, which the player bets that it fell out
    int betAmount_ {0};             //the amount the player is betting
    char betOption_ {0};            //option on which the player is betting
    unsigned int optionSwitch_ {0};          //An artificial variable that stores relevant information about what option the player bet on and whether he hit, if not it is 0

public:
    Player(const std::string & name,
           int accBalance);
    
    void setName();                     //sets the player's name
    void displayName() const;                 //displays the player's name
    void setAccBalance(int accBalance); //sets the player's account balance
    void show() const;                        //displays player's name and balance
    std::string getName() const;              //gets the player's name
    int getAccBalance() const;                //gets the player's balance
    void setBetAmount();                //sets the amount that the player bets
    int getBetAmount() const;                 //gets the amount that the player bets
    void setBetNumber();                //sets the number, which the player bets that it fell out
    int getBetNumber() const;                 //gets the number, which the player bets that it fell out
    void addToAccBalance(int wonBet);   //adds the amount won to the player's account balance 
    void setBetOption();                //sets the option on which the player is betting
    char getBetOption() const;                //gets the option on which the player is betting
    void setOptionSwitch(int optionSwitch); //sets the artificial variable which verifies the win
    int getOptionSwitch() const;                  //gets the artificial variable which verifies the win
    void checkingIfBetIsTooHigh();          //checks that the amount a player bets is not larger than his account balance
};