//
//TowerHanoi header file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the header for a TowerHanoi class
//

#ifndef ASSIGNMENT2_TOWERHANOI_H
#define ASSIGNMENT2_TOWERHANOI_H

#include "LStack.h"
#include <iostream>
#include <cmath>
#include <list>
#include <string>



class TowerHanoi{
public:

    //The numOfDiscs has been entered
    //initialises the game by creating a TowerHanoi object with a given number of discs
    TowerHanoi(int numOfDiscs);
    //TowerHanoi has been initialised with the LStacks in their starting positions

    //TowerHanoi has been created and initialised
    //makes all the possible checks to see if a move is legal and then moves the disc from one rod to another
    void move(const int from, const int to);
    //The top value from the from rod has been moved to the top of to and removed from the from rod (If it is a legal move)

    //TowerHanoi has been created and initialised
    //checks to see if the game has been finished (all discs are on the right hand stack)
    bool checkWin() const;
    //A bool value has been returned which is true if all the discs are on the 3rd rod, overwise it's false

    //Ostream has been included
    //A function to announce there has been an error with something that was attempted
    void error(std::string errorMessage) const;
    //The error specified has been displayed to the user

    //String has been included
    //A print helper function that returns a string
    std::string print();
    //A formatted string containing all the data of the stacks has been returned



private:
    //An int value for the width of the stack which is declared in the constructor
    int stackWidth;

    //An int value for the number of discs which is declared in the constructor
    int numberOfDiscs;

    //An array variable which stores the 3 LStacks of type std::string which hold the discs
    LStack<std::string>* stack[3];

};

//TowerHanoi has been created and initialised
//An overloaded << operator to allow TowerHanoi to be printed
std::ostream& operator <<(std::ostream& out, TowerHanoi& t);
//A formatted string containing all the data of the 3 stacks is displayed to the user

//The string entered is one which is supported by the function
//Overloading of the * operator to allow for multiplication of select strings used in the formatting of creating the discs and stacks
std::string operator*(int num, std::string x);
//A string containing however many  x's num is

#endif //ASSIGNMENT2_TOWERHANOI_H
