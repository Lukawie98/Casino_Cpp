#include "../BoardManagment/board.hpp"

class BoardFive :public Board 
{
    std::string leftSpace{0};               //space to match the distance of the board
    
public:
    void showBoard(std::vector<Player> & p); //displayes board for 5 people
    void longerName(int fP0, int fP2);       //checks which name is longer
};