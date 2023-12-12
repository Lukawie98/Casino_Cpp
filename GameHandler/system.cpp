#include "system.hpp"
#include "menu.hpp"
#include "../BoardManagment/boardThree.hpp"
#include "../BoardManagment/boardFour.hpp"
#include "../BoardManagment/boardFive.hpp"

#include <unistd.h>
#include <algorithm>
#include <random>
#include <memory>

void System::clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void System::displayRanking()
{
    std::cout<<"The ranking is: \n";
    for(const auto & player : this->players_)
    {
        player.show();
        std::cout<<"\n";
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void System::setNumOfPlayers()
{
    int numOfPlayers = 0;
    while (!(std::cin >> numOfPlayers)) 
    {
        std::cout << "Enter the number of players (3-5, 0 to exit): ";
        if (numOfPlayers < 0 || numOfPlayers > 5) 
        {
            std::cout << "!Invalid choice. Please enter 3, 4, or 5 (0 to exit)\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } 
        else if (numOfPlayers == 0) 
        {
            exit(0);
        } 
    }        
    this->numOfPlayers_ = numOfPlayers;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////  

void System::handlingPlayers()
{
    setNumOfPlayers();
    this->players_.reserve(this->numOfPlayers_);
    std::string playerName{""};
    
    for(int i = 0; i < this->numOfPlayers_; i++)
    {
        std::cout << "Enter name for player " << i+1 << ": ";
        std::cin >> playerName;

        this->players_.emplace_back(playerName, 0);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

int System::getNumOfPlayers()
{
    return this->numOfPlayers_;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::assigingBeginningBalanceToPlayers(int beginningAccBalance)
{
    for(auto && player : this->players_)
    {
        player.setAccBalance(beginningAccBalance);
    }  
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::selectionAccBalance()
{
    char choiceAmount{};
    bool validChoice = false;

    while (!validChoice) 
    {
        std::cin >> choiceAmount;
        switch(choiceAmount)
        {
            case '1': 
                assigingBeginningBalanceToPlayers(500); 
                validChoice = true;
                break;
            case '2': 
                assigingBeginningBalanceToPlayers(1000); 
                validChoice = true;
                break;
            case '3': 
                assigingBeginningBalanceToPlayers(2000); 
                validChoice = true;
                break;
            case '4': 
                assigingBeginningBalanceToPlayers(5000); 
                validChoice = true;
                break;
            default:
                std::cout << "!Wrong sign, try one more time!\n Press enter to return to menu";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.get();
                break;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::selectionBalanceSystem()
{
    Menu m1;
    m1.displayBalanceSelection();
    selectionAccBalance();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::runMenu()
{
    Menu m1;
    m1.displayPlayerNumMenu();
    handlingPlayers();
    selectionBalanceSystem();
    handlingRounds(playingSetNumbOfTurns());
    checkingWinner();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::enterGoldenNumb()
{
     std::cout << "\nWrite the number: ";
     std::cin >> this->betNumber_;
     
     while(this->betNumber_ < 1 || this->betNumber_ > 10)
    {
        std::cout << "The number must be between 1 and 10, try again: ";
        std::cin >> this->betNumber_;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::selectingOptionsToBetOn(char betOpt, Player & ply)
{
    switch(betOpt)
         {
            case GOLDEN:
                enterGoldenNumb();
                ply.setOptionSwitch((this->randomNumb_ == this->betNumber_) ? 1 : 0);
                break;
            case LESS7:
                ply.setOptionSwitch(this->randomNumb_ < 7 ? 2 : 0);
                break;
            case LESS5:
                ply.setOptionSwitch(this->randomNumb_ < 5 ? 3 : 0);
                break;
            case LESS3:
                ply.setOptionSwitch(this->randomNumb_ < 3 ? 4 : 0);
                break;
            case GREATER3:
                ply.setOptionSwitch(this->randomNumb_ > 3 ? 5 : 0);
                break;
            case GREATER5:
                ply.setOptionSwitch(this->randomNumb_ > 5 ? 6 : 0);
                break;        
            case GREATER7:
                ply.setOptionSwitch(this->randomNumb_ > 7 ? 7 : 0);
                break;
            default: 
                std::cerr << "Error! Invalid option switch value\n"; 
                break;
        }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::choicePlayersBetOption()
{    
    for(auto && player : this->players_)
    {
        displayBoard(this->players_, getNumOfPlayers());
        
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

void System::displayOfWinnings(Player & ply, int converter)
{
    ply.displayName();
    std::cout<<" - Your winnings are: "<< ply.getBetAmount() * converter << "\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::playersDisplayOfWinnings()
{
    for (auto && player : this->players_)
    {
        int option{player.getOptionSwitch()};
        int multiplier{0};
        
        //allocating the correct multiplier of the bet amount
        switch (option)
        {
            case 1: multiplier = 10; break;
            case 2: multiplier = 2;  break;
            case 3: multiplier = 5;  break;
            case 4: multiplier = 7;  break;
            case 5: multiplier = 2;  break;
            case 6: multiplier = 5;  break;
            case 7: multiplier = 7;  break;
            case 0: multiplier = 0;  break;
            default: 
                std::cerr << "Error! Invalid option switch value\n"; 
                break;
        }
        displayOfWinnings(player, multiplier);
        player.addToAccBalance(player.getBetAmount() * multiplier);
    }
}    
                
////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::handlingRounds(int turns)
{
    for(int i = 1; i <= turns; i++)
    {
        setRandomNumber();
        choicePlayersBetOption();
        
        clearScreen();
        std::cout <<"The Number is: "<< getRandNumb() << "\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.get();
        std::cout << "-------------------------------\n";
        
        playersDisplayOfWinnings();
        std::cin.get();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int System::playingSetNumbOfTurns()
{
    int turns;
    std::cout <<"\nWrite how many turns do you want to play(1-10):\n";
    std::cin >> turns; 
    
    while(turns < 1 || turns > 10)
    {
        std::cout << "You have to choose 1 - 10\nTry one more time:";
        std::cin >> turns;
    }
    return turns;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::generateRandNumb()
{
    std::random_device rd;
    std::mt19937 generator(rd());
    
    //set range to the random number
    std::uniform_int_distribution<int> distribution(1, 10);
    this->randomNumb_ = distribution(generator);
}

///////////////////////////////////////////////////////////////////////

int System::getRandNumb()
{
    return this->randomNumb_;
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
    finalSorting(this->players_);
    clearScreen();
    std::cout << "The BIG WINNER IS: \n";
    this->players_[0].show();
    std::cout <<"\n********************\n\n";
    
    displayRanking();
    
    std::cout << "Press 'enter' to exit! \n";
    std::cin.get();
    exit(0);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

bool System::checkingAccBalance(int accountBalance)
{
    return accountBalance > 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 

void System::displayBoard(std::vector<Player> & ply, const int & amountPlayers)
{
    clearScreen();
    std::unique_ptr<Board> brd;

    switch(amountPlayers)
    {
        case 3:
        {
            brd = std::make_unique<BoardThree>(); 
            break;
        }
        case 4:
        {
            brd = std::make_unique<BoardFour>();
            break;
        }
        case 5:
        {
            brd = std::make_unique<BoardFive>();
            break;
        }
        default:
        {
            std::cout<<"Wrong sign, select between 3-5: ";
            break;
        } 
    }
    brd->showBoard(ply);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void System::finalSorting(std::vector<Player> & players)
{    
    std::sort(players.begin(), players.end(), [](const Player & player1, const Player & player2)
        {
            return player1.getAccBalance() > player2.getAccBalance();
        });
}