# Casino_Cpp
> A casino game for 3-5 people, involving betting a selected amount on one of several betting options so that it matches the generated number. Here it is not luck that counts, but money management!

## General Information
The project allows 3-5 players to play, players give their names and decide with what amount they start the game. Once the game starts, a number 1-10 is drawn and players are presented with several choices:
- Golden Bet, the player states the number he thinks has been drawn, when he hits his wagered amount is multiplied x10,
- Number is less than 7, the bet amount is multiplied x2,
- Number is less than 5, the bet amount is multiplied x5,
- Number is less than 3, the amount bet is multiplied x7,
- Number is more than 3, the bet amount is multiplied x7,
- Number is more than 5, the bet amount is multiplied x5,
- Number is more than 7, the bet amount is multiplied x2.
  
If the option chosen by the player does not match the drawn number, he loses the entire amount he bet. The game lasts for the number of rounds determined by the players at the beginning.

This project aimed to better understand object-oriented programming, use its advantages of encapsulation and polymorphism, use getters, setters, const-corretness, following SOLID principles and correct patterns

## Technologies Used
The whole project is written in C++ language and uses such libraries as:
- vector,
- string,
- iostream,
- unistd.h,
- iomanip,
- algorithm.

The integrated development environment(IDE) used was Visual Studio Code.

## Features
- The program uses the string and iomanip libraries for easier operation and modification,
- A vector was used as a container for storing Player class objects,
- Enum enumeration type to create more readable and understandable code,
- The sort function from the algorithm library using lambda was used to sort the objects in the container,
- Used polymorphism, abstract class and virtual functions to facilitate extensibility and enable movement on different boards for different numbers of players,
- Encapsulation is used to prevent private information from leaking out,
- Const-correctness and unsigned short types are used to prevent unwanted changes and reduce memory usage,
- References were used, and also references to constants when possible, to avoid creating unnecessary copies,
- Getter and setter functions have been created to return and set private class data,
- Used a constructor with an initialization list to improve performance and readability.

## Project Status
Project is: _in progress_.

## Room for Improvement
This project taught me a lot, such as how to use references and use functions, but at this stage I have a lot of improvements that improve its functioning:
- dynamic creation of objects using new and delete operators or smart pointers from the memory library,
- changes in the functions of the board class and making greater use of the polymorphism used,
- breaking down two functions from system.cpp into smaller and more detailed ones,
- add unit tests.

Project upcoming extension:
- creating an introductory board with a welcome and game description, loaded from another file, using the fstream library,
- introduction of a mode for two people,
- introducing the possibility of playing against the computer.

## Contact
Created by lukaszwieczorek1998@gmail.com - feel free to contact me!
