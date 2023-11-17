#pragma once
#include "../PlayerHandler/player.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>
#include <iomanip>

class Board                     //Basic class for creating different sizes of boards
{
    std::string leftSpace{0};   //Distance from the left edge
public:
    virtual void showBoard(std::vector<Player> & p) = 0;  //Virtual function, displays the player board depending on the number of players
    virtual ~Board(){}
};