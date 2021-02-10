//
//TowerHanoi cpp file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the implementation for a TowerHanoi class
//

#include "LStack.h"
#include "TowerHanoi.h"


//A constructor which initialises the game and creates the starting state for a towers of hanoi game
//It creates the 3 stacks, the first with the specified number of discs and 2 more empty stacks
TowerHanoi::TowerHanoi(int numOfDiscs){
    std::string nodeData;
    numberOfDiscs = numOfDiscs;
    std::string out;
    std::string strX = "X", whiteSpace = " ", empty = "";
    std::string strXOut;
    std::string whiteSpaceString = " ";
    std::string finString;
    int whiteSpaceInt;
    int numX;
    stackWidth = 1+2*(numberOfDiscs-1)+4;

    for (int j = 0; j < 3; j++) {
        stack[j] = new LStack<std::string>();
        if (j==0){
            for (int i =numberOfDiscs; i>0; i--){
                numX = 1+2*(i-1);
                strXOut = numX*strX;
                whiteSpaceInt = (stackWidth-numX)/2;
                whiteSpaceString = whiteSpaceInt*whiteSpace;
                out = whiteSpaceString+strXOut+whiteSpaceString;
                stack[j]->push(out);
            }
        } else{
            for (int i =numberOfDiscs; i>0; i--){
                stack[j]->push(empty);
            }
        }
    }
}

//A function for moving the discs. It takes the two inputs of the to and from discs and returns that there is an error to the user if they have inputted the incorrect data
//The rods given are then checked to make sure that there is a disc to move and that the move is legal i.e. the rod is smaller than the one it is going on top of
//It then empties both rods of any blank strings and then pushes the disc onto the receiving rod and then removes the disc from it's previous rod.
//Both stacks are then reassembled with blank strings until they are the normal height.
void TowerHanoi::move(const int from, const int to) {
    //Check the from rod has a disc
    //Check the to rod has a disc
    //Check the size of the disc on the from rod is smaller than the to rod

    if (from < 1 || from > 3 || to < 1 || to > 3){
        error("The data you have entered is incorrect. The rod values cannot be greater than 3 or less than 1 as there is only 3.");
        return;
    }

    std::string fromString, toString, empty = "";
    bool noFromDiscs = false, noToDiscs = false;
    for (int i = 0; i < numberOfDiscs; i++) {
        if (stack[from-1]->top()==empty){
            if (stack[from-1]->height() == 1){
                stack[from-1]->pop();
                noFromDiscs = true;
                break;
            }
            stack[from-1]->pop();
        } else {
            noFromDiscs = false;
            break;
        }
    }

    if (noFromDiscs){
        for (int i =numberOfDiscs; i>0; i--){
            stack[from-1]->push(empty);
        }
        error("The rod you were trying to move from has no discs.");
        return;
    }
    for (int i = 0; i < numberOfDiscs; i++) {
        if (stack[to-1]->top()==empty){
            if (stack[to-1]->height() == 1){
                stack[to-1]->pop();
                noToDiscs = true;
                break;
            }
            stack[to-1]->pop();
        } else {
            noToDiscs = false;
            break;
        }
    }

    if (!noToDiscs){
        //getStack(to-1)->top();
        toString = stack[to-1]->top();
        fromString = stack[from-1]->top();
        if (fromString<toString){
            stack[to-1]->push(stack[from-1]->top());
            stack[from-1]->pop();
        } else {
            error("The disc you were trying to move is larger than the one you are trying to put it on top of. ");
        }
    } else {
        stack[to-1]->push(stack[from-1]->top());
        stack[from-1]->pop();
    }

    while (stack[from-1]->height()<numberOfDiscs){
        stack[from-1]->push(empty);
    }
    while (stack[to-1]->height()<numberOfDiscs){
        stack[to-1]->push(empty);
    }
}

//A function that checks if the game has been won by looking at the top of the third stack and if the top string is not empty then the game has been completed
bool  TowerHanoi::checkWin() const{
    if (stack[2]->top() != ""){
        return true;
    } else return false;
}

//An error function that can be used to display an error message to the user
void TowerHanoi::error(std::string errorMessage) const{
    std::cout << "An error has occurred: " << std::endl << errorMessage << std::endl << " Because of this the last action made has not been completed." << std::endl;
}

//A print helper function
//Uses the methods top, push and pop to get the data on the top of the stack, add it to a string and a temporary stack and then remove the top item of the stack
//Once a fully formatted string has been created the stacks are rebuilt from the temporary stack exactly as they were before printing
std::string TowerHanoi::print() {
    std::string out, stackData, stackPrintData, dash = "-", blank = " ";
    LStack<std::string>* tempStack[3];
    for (int k = 0; k < 3; k++) {
        tempStack[k] = new LStack<std::string>();
    }
    for (int i = 0; i < numberOfDiscs; i++) {
        for (int j = 0; j < 3; j++) {
            stackData = stack[j]->top();
            if (stackData == ""){
                stackPrintData = stackWidth*blank;
            } else {
                stackPrintData = stackData;
            }
            out += stackPrintData;
            if (j == 2){
                out += "\n";
            }
            tempStack[j]->push(stackData);
            stack[j]->pop();
        }
    }

    for (int i = 0; i < numberOfDiscs; i++) {
        for (int j = 0; j < 3; j++) {
            stackData = tempStack[j]->top();
            stack[j]->push(stackData);
            tempStack[j]->pop();
        }
    }

    stackPrintData = (stackWidth*dash) + (stackWidth*dash) + (stackWidth*dash);
    out += stackPrintData + "\n";
    return out;
}


//An overloaded << operator to allow TowerHanoi to be printed
//Calls a helper print function which returns a multiline string that is correctly formatted for displaying all the discs in the game
std::ostream& operator <<(std::ostream& out, TowerHanoi& t){
    out << t.print();
    return out;
}

//Overloading of the * operator to allow for multiplication of select strings used in the formatting of creating the discs and stacks
std::string operator*(int num, std::string x){
    std::string xString = "";
    if(x=="X"){
        xString = "X";
    } else if (x==" "){
        xString = " ";
    } else if (x=="-"){
        xString = "-";
    }
    std::string out = "";
    for (int i = 0; i < num; ++i) {
        out += xString;
    }
    return out;
}