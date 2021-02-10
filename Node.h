//
//Node header file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the header for a Node class
//

#ifndef ASSIGNMENT2_NODE_H
#define ASSIGNMENT2_NODE_H

#include <cmath>
#include <iostream>
#include <string>

template <typename value_type>
class Node{

public:
    //The student class is added to value_type
    //typedef std::string value_type;

    //Constructors
    //No precondition
    Node();
    //A blank node is created

    //The value_type data exists
    Node(const value_type data);
    //A node with data is created


    //Destructor
    //A node exists
    ~Node();
    //Node is removed from memory

    //Setters
    //Sets the next pointer of a node
    //Node exists
    void setNext(Node<value_type>* n);
    //Node is set to next

    //Sets the data of the node
    //Value_type data exists
    void setData(const value_type s);
    //The value_type data is added to node

    //Getters
    //Gets the next pointer of a node
    //Next exists
    Node<value_type>* getNext() const;
    //Next pointer is returned

    //Gets the data of the node
    //Node with data exists
    value_type getData() const;
    //Data of node returned


private:

    //A pointer for the next node
    Node<value_type>* next;

    //A value_type data type
    value_type data;



};

//overloads the << operator for outputting Node's
template <typename value_type>
std::ostream& operator <<(std::ostream& out, const Node<value_type>& value);

#include "Node.hpp"

#endif //ASSIGNMENT2_NODE_H
