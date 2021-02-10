//
//LStack header file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the header for a LStack class
//

#ifndef ASSIGNMENT2_LSTACK_H
#define ASSIGNMENT2_LSTACK_H

#include "LinkedList.h"
#include <iostream>
#include <cmath>

template <typename value_type>
class LStack{

public:
    //The data type for LStack has been initialised
    //creates an Lstack with an empty LinkedList
    LStack();
    //An empty LStack has been created with an empty LinkedList

	//An LStack exists
	//LStack destructor
	~LStack();
	//LStack has been removed from memory
	
    //The length has been specified
    //creates an Lstack with a LinkedList of a specified length
    LStack(const int length);
    //An LStack has been created with an empty LinkedList of a specific length

    //The LStack has been initialised
    //returns if the stack is empty
    bool empty() const;
    //A bool value has been returned which is true if the LStack is empty otherwise it's true

    //The LStack has been initialised
    //returns the size of the stack
    int height() const;
    //The size of the LinkedList is returned

    //The LinkedList has at least one node
    //returns the value of the top most element on the stack
    value_type top();
    //the value of the head Node is returned

    //An LStack has been initialised
    //adds an element at the top of the stack
    void push(const value_type element);
    //A new Node has been created at the head of the LinkedList with the element as its data

    //The LinkedList has at least one node
    //deletes the top most element of the stack
    void pop();
    //The head Node is removed from the LinkedList


private:


    //An uninitialised LinkedList object
    LinkedList<value_type>* data;



};
//including the implementation for the template class
#include "LStack.hpp"
#endif //ASSIGNMENT2_LSTACK_H
