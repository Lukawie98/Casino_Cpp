#include "../BoardManagment/boardThree.hpp"

void BoardThree::showBoard(std::vector<Player> & p)
{
    
    std::string line = "@- - - - - - - - - - @";
    std::string accBalance = std::to_string(p[1].getAccBalance());
    int nameLength = p[1].getName().length();
    int balanceLength = accBalance.length();
    
    //distance from the left side so that the player fits in front of the board
    std::string leftSpace(nameLength+balanceLength, ' ');
    

    std::cout << leftSpace << std::setw(line.length()/2)<<std::right; 
    p[0].show();
    std::cout << "\n"
              << leftSpace << "          /\\"<<"\n"
              << leftSpace << "         /  \\"<<"\n"
              << leftSpace << "        /    \\"<<"\n"
              << leftSpace << "       /      \\"<<"\n"
              << leftSpace << "      /        \\"<<"\n"
              << leftSpace << "     /          \\"<<"\n"
              << leftSpace << "    /            \\"<<"\n"
              << leftSpace << "   /              \\"<<"\n"
              << leftSpace << "  /                \\"<<"\n"
              << leftSpace << " /                  \\"<<"\n"
              << leftSpace <<  line<<"\n";
            p[1].show();
    std::cout << std::setw(line.length());
            p[2].show(); 
            std::cout<<std::endl; 
}