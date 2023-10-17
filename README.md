# Casino_Cpp
> A casino game for 3-5 people, involving betting a selected amount on one of several betting options so that it matches the generated number. Here it is not luck that counts, but money management.

## General Information
The project allows 3-5 players to play, players give their names and decide with what amount they start the game. Once the game starts, a number 1-10 is drawn and players are presented with several choices:
- Golden Bet, the player states the number he thinks has been drawn, when he hits his wagered amount is multiplied x10,
- Less than 7, the bet amount is multiplied x2,
- Less than 5, the bet amount is multiplied x5,
- Less than 3, the amount bet is multiplied x7,
- More than 3, the bet amount is multiplied x7,
- More than 5, the bet amount is multiplied x5,
- More than 7, the bet amount is multiplied x2.
If the option chosen by the player does not match the drawn number, he loses the entire amount he bet. The game lasts for the number of rounds determined by the players at the beginning.

This project aimed to better understand object-oriented programming, use its advantages of encapsulation and polymorphism, use getters, setters, const-corretness, following SOLID principles and correct patterns

## Technologies Used
The whole project is written in C++ language and uses such libraries as:
- vector
- string
- iostream
- unistd.h
- iomanip

The integrated development environment(IDE) used was Visual Studio Code.

## Features


## Project Status
Project is: _in progress_.

## Room for Improvement
The project is one of the first and gave me a lot of fun, but it needs some improvements:
- creating a separate class for the computer at different levels, polymorphism can be used here,
- use of const-correctness
- simplifying the code and improving the names of variables and functions

## Contact
Created by lukaszwieczorek1998@gmail.com - feel free to contact me!
