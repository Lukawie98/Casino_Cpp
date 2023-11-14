#include "boardFour.hpp"

void BoardFour::longerName(int fP0, int fP2)
{
     //if informations about player are longer, adds as many spaces to the variable as needed
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

void BoardFour::showBoard(std::vector<Player> & p)
{
    std::string lines = "@=====================@";
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
    
    std::string spacesLines(lines.length()-2, ' ');
    std::string spacesRight0((lines.length() + leftSpace.length() - (nameLength0 + balanceLength0) - 4), ' ');
    std::string spacesRight2((lines.length() + leftSpace.length() - (nameLength2 + balanceLength2) - 4) , ' ');
    
    p[0].show();
    std::cout << spacesRight0;
    p[1].show();
    std::cout<<"\n"<< leftSpace << lines<<"\n"
             << leftSpace << "I"<<spacesLines <<"I\n"
             << leftSpace << "I"<<spacesLines <<"I\n"
             << leftSpace << "I"<<spacesLines <<"I\n"
             << leftSpace << "I"<<spacesLines <<"I\n"
             << leftSpace << "I"<<spacesLines <<"I\n"
             << leftSpace << lines << "\n";
    p[2].show();
    std::cout << spacesRight2;
    p[3].show();
    std::cout << "\n\n\n";
}