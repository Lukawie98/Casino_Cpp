#include "board.hpp"

class BoardThree :public Board  
{
    std::string leftSpace{0};       //Distance from the left edge
public:
    void showBoard(std::vector<Player> & p) override;    //displayes board for 3 people
};