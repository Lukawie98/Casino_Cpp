#include "board.hpp"

class BoardThree :public Board
{
    
public:
    void showBoard(std::vector<Player> & p) override;    //displayes board for 3 people
};