#include "system.hpp"
#include "menu.hpp"
#include "../BoardManagment/boardThree.hpp"
#include "../BoardManagment/boardFour.hpp"
#include "../BoardManagment/boardFive.hpp"

#include <unistd.h>
#include <algorithm>
#include <random>

void System::displayRanking()
{
    std::cout<<"The ranking is: \n";
    for(auto player : players_)
    {
        player.show();
        std::cout<<"\n";
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void System::handlingPlayers(int numOfPlayers)
{
    players_.reserve(numOfPlayers);

    for(int i = 0; i < numOfPlayers; i++)
    {
        std::string playerName{""};
        std::cout << "Enter name for player " << i+1 << ": ";
        std::cin >> playerName;

        players_.emplace_back(playerName, 0);
    }
    system("cls");
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::selectionNumOfPlayers()
{
    std::cin >> numOfPlayers;
    switch(numOfPlayers)
        {
            case '3':
            {
                handlingPlayers(3);
                displayBoard(players_, getNumOfPlayers());
                break;
            }
            case '4':
            {
                handlingPlayers(4);
                displayBoard(players_, getNumOfPlayers());
                break;
            }
            case '5':
            {
                handlingPlayers(5);
                displayBoard(players_, getNumOfPlayers());
                break;
            }
            case '0':
            {
                exit(0);
                break;
            }
            default:
            {
                system("cls");
                std::cout << "!Wrong sign, try one more time!\n Press enter to return to menu";
                std::cin.get();
                system("cls");
                break;
            }
        }
        selectionBalanceSystem();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////   

char System::getNumOfPlayers()
{
    return numOfPlayers;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::selectionAccBalance()
{
    char choiceAmount;
    std::cin >> choiceAmount;
    
    switch(choiceAmount)
    {
        case '1':
            {
                for(auto && player : players_)
                {
                    player.setAccBalance(500);
                }
                break;
            }
        case '2':
            {
                for(auto && player : players_)
                {
                    player.setAccBalance(1000);
                }
                break;
            }     
        case '3':
            {
                for(auto && player : players_)
                {
                    player.setAccBalance(2000);
                }
                break;
            }
        case '4':
            {
                for(auto && player : players_)
                {
                    player.setAccBalance(5000);
                }
                break;
            }
        default:
            {
                system("cls");
                std::cout << "!Wrong sign, try one more time!\n Press enter to return to menu";
                std::cin.get();
                break;
            }
    }
    playingSetNumbOfTurns();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::selectionBalanceSystem()
{
     while(true)
    {
         Menu m1;
         m1.displayBalanceSelection();
         selectionAccBalance();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::runMenu()
{
    while(true)
    {
        Menu m1;
        m1.displayPlayerNumMenu();
        selectionNumOfPlayers();
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::enterGoldenNumb()
{
     std::cout << "\nWrite the number: ";
     std::cin >> betNumber_;
     
     while(betNumber_ < 1 || betNumber_ > 10)
    {
        std::cout << "The number must be between 1 and 10, try again: ";
        std::cin >> betNumber_;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::selectingOptionsToBetOn(char betOpt, Player & ply)
{
    switch(betOpt)
         {
             case GOLDEN:
            {
                enterGoldenNumb();
                
                if(randomNumb_ == betNumber_)
                {
                    ply.setOptionSwitch(1);
                }
                else
                {
                    ply.setOptionSwitch(0);
                }
                break;
            }
            case LESS7:
            {
                if(randomNumb_ < 7)
                {
                    ply.setOptionSwitch(2);
                }
                else
                {
                    ply.setOptionSwitch(0);
                }
                break;
            }
            case LESS5:
            {
                if(randomNumb_ < 5)
                {
                    ply.setOptionSwitch(3);
                }
                else
                {
                    ply.setOptionSwitch(0);
                }
                break;
            }
            case LESS3:
            {
                if(randomNumb_ < 3)
                {
                    ply.setOptionSwitch(4);
                }
                else
                {
                    ply.setOptionSwitch(0);
                    
                }
                break;
            }
            case GREATER3:
            {
                if(randomNumb_ > 3)
                {
                    ply.setOptionSwitch(5) ;
                    
                }
                else
                {
                    ply.setOptionSwitch(0);
                }
                break;
            }
            case GREATER5:
            {
                if(randomNumb_ > 5)
                {
                   ply.setOptionSwitch(6) ;
                }
                else
                {
                    ply.setOptionSwitch(0) ;
                    
                }
                break;
            }
            case GREATER7:
            {
                if(randomNumb_ > 7)
                {
                    ply.setOptionSwitch(7);
                }
                else
                {
                    ply.setOptionSwitch(0);
                }
                break;
            }
        }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::choicePlayersBetOption()
{
    setRandomNumber();
    
    for(auto && player : players_)
    {
        system("cls");
        displayBoard(players_, getNumOfPlayers());
        
        player.displayName();

        if(checkingAccBalance(player.getAccBalance()))
        {
            Menu m1;
            m1.displayOptionsForBets();
            player.setBetOption();
            
            selectingOptionsToBetOn(player.getBetOption() , player);
            
            std::cout << "\nEnter the amount you want to bet ";
            player.setBetAmount();
        }
        else
        {
            std::cout << "\nSorry, your account balance is 0!\nPress anything to move on\n";
            std::cin.get();
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::convertingBettingAmount()
{
    choicePlayersBetOption();
    
    for(auto && player : players_)
    {
        switch(player.getOptionSwitch())
        {
            case 1:
            {
                player.addToAccBalance(player.getBetAmount()*10);
                break;
            }
            case 2:
            {
                player.addToAccBalance(player.getBetAmount()*2);
                break;
            }
            case 3:
            {
                player.addToAccBalance(player.getBetAmount()*5);
                break;
            }
            case 4:
            {
                player.addToAccBalance(player.getBetAmount()*7);
                break;
            }
            case 5:
            {
                player.addToAccBalance(player.getBetAmount()*2);
                break;
            }
            case 6:
            {
                player.addToAccBalance(player.getBetAmount()*5);
                break;
            }
            case 7:
            {
                player.addToAccBalance(player.getBetAmount()*7);
                break;
            }
            case 0:
            {
                player.addToAccBalance(0);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::displayOfWinnings(Player & ply, int converter)
{
    ply.displayName();
    std::cout<<" - Your winnings are: "<< ply.getBetAmount()*converter << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::playersDisplayOfWinnings()
{
    for(auto && player : players_)
    {
        switch(player.getOptionSwitch())
        {
            case 1:
            {
                displayOfWinnings(player, 10);
                break;
            }
            case 2:
            {
                displayOfWinnings(player, 2);
                break;
            }
            case 3:
            {
                displayOfWinnings(player, 5);
                break;          
            }
            case 4:
            {
                displayOfWinnings(player, 7);
                break;
            }
            case 5:
            {
                displayOfWinnings(player, 2);
                break;
            }
            case 6:
            {
                displayOfWinnings(player, 5);  
                break;
            }
            case 7:
            {
                displayOfWinnings(player, 7);
                break;
            }
            case 0:
            {
                displayOfWinnings(player, 0);
                break;
            }
        }
    }
}    
                
////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::displayBetweenRounds(int t)
{
    for(int i = 1; i <= t; i++)
    {
        convertingBettingAmount();
        system("cls");
        std::cout <<"The Number is: "<< getRandNumb() << "\n";
        std::cin.get();
        std::cin.get(); 
        system("cls");
        
        playersDisplayOfWinnings();
        std::cin.get();
        system("cls");
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::playingSetNumbOfTurns()
{
    int turns;
    std::cout <<"\nWrite how many turns do you want to play(1-10):\n";
    std::cin >> turns; 
    
    while(turns < 1 || turns > 10)
    {
        std::cout << "You have to choose 1 - 10\nTry one more time:";
        std::cin >> turns;
    }
  
    displayBetweenRounds(turns);
    checkingWinner();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::generateRandNumb()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    
    //set range to the random number
    std::uniform_int_distribution<int> distribution(1, 10);
    randomNumb_ = distribution(generator);
}

///////////////////////////////////////////////////////////////////////

int System::getRandNumb()
{
    return randomNumb_;
}

///////////////////////////////////////////////////////////////////////

void System::setRandomNumber()
{
        generateRandNumb();
        getRandNumb();
}

///////////////////////////////////////////////////////////////////////

void System::checkingWinner()
{   
    //sort the ranking of winners    
    finalSorting(players_);
    std::cout << "The BIG WINNER IS: \n";
    players_[0].show();
    std::cout <<"\n********************\n\n";
    
    displayRanking();
    
    std::cout << "Press 'enter' to exit! \n";
    std::cin.get();
    exit(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

bool System::checkingAccBalance(int accountBalance)
{
    if(accountBalance <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::displayBoard(std::vector<Player> & ply, char amountPlayers)
{
    system("cls");
    Board *brd;

        switch(amountPlayers)
        {
            case '3':
            {
                 BoardThree b3;
                 brd = &b3;
                 brd -> showBoard(ply);
                 break;
            }
            case '4':
            {
                BoardFour b4;
                brd = &b4;
                brd -> showBoard(ply);
                break;
            }
            case '5':
            {
                 BoardFive b5;
                 brd = &b5;
                 brd -> showBoard(ply);
                 break;
            }
            default:
            {
                std::cout<<"Wrong sign, select between 2-5: ";
                break;
            } 
        }
}

void System::finalSorting(std::vector<Player> & players)
{    
    std::sort(players.begin(), players.end(), [](const Player & player1, const Player & player2)
        {
            return player1.getAccBalance() > player2.getAccBalance();
        });
}