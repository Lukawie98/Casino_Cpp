#include "board.hpp"

class BoardFour :public Board
{
    std::string leftSpace{0};               //Distance from the left edge

public:
    void showBoard(std::vector<Player> & p) override; //displayes board for 4 people
    void longerName(int fP0, int fP2);                //checks which name is longer
};