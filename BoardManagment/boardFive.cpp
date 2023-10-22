#include "boardFive.hpp"

void BoardFive::longerName(int fP0, int fP2)
{
    //if informations about one player are longer, adds as many spaces to the variable as needed
        if(fP0 > fP2)
    {
         while(fP0 >= 0)
         {
             leftSpace += ' ';
             fP0--;
         }        
    }
    else
    {
          while(fP2 >= 0)
         {
             leftSpace += ' ';
             fP2--;
         }
    }
}

void BoardFive::showBoard(std::vector<Player> & p)
{
    std::string accBalance0 = std::to_string(p[0].getAccBalance());
    std::string accBalance2 = std::to_string(p[2].getAccBalance());
    int nameLength0 = p[0].getName().length();
    int nameLength2 = p[2].getName().length();
    int balanceLength0 = accBalance0.length();
    int balanceLength2 = accBalance2.length();
    
    //variables showing the entire length of player information
    int fullP0 = nameLength0 + balanceLength0;
    int fullP2 = nameLength2 + balanceLength2;
    
    longerName(fullP0, fullP2);
    std::string line {"_ _ _ _ _ _ _ _ _"};
    
    //Displays board with appropriate spaces
    std::cout << std::setw(fullP2);
    p[0].show(); 
    std::cout << std::setw(leftSpace.length() + line.length() - (nameLength0 + balanceLength0));
    p[1].show(); 
    std::cout << "\n"
              << leftSpace << "  " <<line << "\n"    
              << leftSpace <<" |                  \\"<<"\n"
              << leftSpace <<" |                   \\"<<"\n"
              << leftSpace <<" |                    \\"<<"\n"
              << leftSpace <<" |                     \\ ";
    p[3].show();
    std::cout <<"\n"
              << leftSpace <<" |                     /"<<"\n"
              << leftSpace <<" |                    /"<<"\n"
              << leftSpace <<" |                   /"<<"\n"
              << leftSpace <<" |" << line << " /\n";
    std::cout << std::setw(fullP0);
    p[2].show();
    std::cout << std::setw(leftSpace.length() + line.length() - (nameLength2 + balanceLength2));
    p[4].show();
    std::cout <<"\n";
}