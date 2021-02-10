//
//LinkedList header file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the header for a LinkedList class
//

#ifndef ASSIGNMENT2_LINKEDLIST_H
#define ASSIGNMENT2_LINKEDLIST_H

#include "Node.h"
#include <iostream>
#include <sstream>
#include <cmath>

template <typename value_type>
class LinkedList {

public:
    //The student class is added to value_type
    //typedef Node::value_type value_type;

    //constructors
    //No precondition
    LinkedList();
    //created LinkedList

    //No precondition
    //LinkedList();
    //created LinkedList of specified size

    //destructor
    //No precondition
    ~LinkedList();
    //removed the LinkedList

    //return the head pointer
    //A head pointer exists
    Node<value_type>* getHead();
    //A head pointer is removed

    //return the tail pointer
    //A tail pointer exists
    Node<value_type>* getTail();
    //returns tail

    //sets the head pointer
    //A Head exists
    void setHead(const Node<value_type>* h);
    //A head pointer is returned

    //Sets the tail pointer
    //No pre-condition
    void setTail(const Node<value_type>* t);
    //A tail pointer has been set

    //Adds a new node before the head which becomes the head
    //There is a head
    void addToHead(const value_type value);
    //A new head has been created, which becomes the head

    //Adds a new node after the tail which becomes the tail
    //A tail exists
    void addToTail(const value_type value);
    //A new node has been added with Student Data, which becomes the tail

    //Adds a new node after the tail which becomes the tail
    //A tail exists
    void addToTail(const Node<value_type>* node);
    //A new node has been added, which becomes the tail

    //Sets the current pointer to head
    //A current pointer exists
    void setCurrentToHead();
    //The current pointer is at head

    //Moves the current pointer to the next node
    //A current pointer exists
    void setCurrentToNext();
    //The current pointer has been moved to the next node

    //Gets curernt pointer
    //A current pointer exists
    Node<value_type>* getCurrent() const;
    //Returns current pointer

    //Gets the size of LinkedList
    //A linked list exists
    int getSize() const;
    //The size of the LinkedList is returned

    //Removes the node
    //A node exists
    void removeNode(Node<value_type>* current);
    //The node has been removed


private:
    //A pointer to the head node
    Node<value_type>* head;

    //A pointer to the tail node
    Node<value_type>* tail;

    //A pointer to the current node
    Node<value_type>* current;

    //The size of the LinkedList
    int size;
};

#include "LinkedList.hpp"

#endif //ASSIGNMENT2_LINKEDLIST_H
