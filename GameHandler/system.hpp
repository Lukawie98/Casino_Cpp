#pragma once

#include "../PlayerHandler/player.hpp"
#include <vector>


class System 
{
    std::vector<Player> players_;       //player storage container
    unsigned short int randomNumb_{0};  //the number that is drawn to guess
    unsigned short int betNumber_{0};   //number, which the player bets that it fell out
    unsigned short int turns{0};        //number of rounds
    char numOfPlayers{0};               //number of players
    
public:
    enum BettingOption : char { GOLDEN ='1'
                              , LESS7 
                              , LESS5
                              , LESS3
                              , GREATER3 
                              , GREATER5
                              , GREATER7 }; //option to bet
    void displayRanking();            //displays ranking of players
    char getNumOfPlayers();           //gets the number of players  
    void handlingPlayers(int numOfPlayers); //adds players to the container and allows you to enter their names
    void selectionAccBalance();                //player account balance selection
    void selectionNumOfPlayers();              //selecting number of players       
    void runMenu();                            //starts first menu and programm
    void generateRandNumb();                   //generates the random number
    void setRandomNumber();                    //sets the random number
    int getRandNumb();                         //gets the random number
    void choicePlayersBetOption();             //A feature in which all players take turns selecting betting options
    void playingSetNumbOfTurns();              //sets the number of rounds how many players will play
    void displayBetweenRounds(int t);          //wyswietla zaktualizowane wygrane graczy, generuje nowa losowa liczbe 
    void selectingOptionsToBetOn(char betOpt, Player & player); //selects the option the player decides on and checks if he has guessed
    void checkingWinner();                                      //checks which player has won
    void selectionBalanceSystem();                              //system of handling the selection of amounts on the account   
    void playersDisplayOfWinnings();                            //displays all players winning
    bool checkingAccBalance(int accountBalance);                //checks if players' account balance is more than 0
    void enterGoldenNumb();                                     //sets golden number in first option of bet
    void displayOfWinnings(Player & ply, int converter);        //displays player winning
    void displayBoard(std::vector<Player> & ply, char amountPlayers);   //displays the board for the selected number of players
    void finalSorting(std::vector<Player> & players);                   //Sorting players on the last step based on their final account balance
};