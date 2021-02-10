//
//Node hpp file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the implementation for a Node template class
//

//Node constructor creates an empty Node
template <typename value_type>
Node<value_type>::Node(){
    next = NULL;
}

//A node constructor that creates a Node with d data
template <typename value_type>
Node<value_type>::Node(const value_type d){
    next = NULL;
    data = d;
}

//Node destructor
template <typename value_type>
Node<value_type>::~Node(){
    //destructor code
    next = NULL;
}

//Set the next pointer of Node to another Node
template <typename value_type>
void Node<value_type>::setNext(Node* nxt){
    next = nxt;
}

//Returns the next pointer of a Node
template <typename value_type>
Node<value_type>* Node<value_type>::getNext() const{
    return next;
}

//Set the data to s
template <typename value_type>
void Node<value_type>::setData(const value_type s){
    data = s;
}

//Get the data of Node
template <typename value_type>
value_type Node<value_type>::getData() const{
    return data;
}

//Overloading the << operator
template <typename value_type>
std::ostream& operator <<(std::ostream& out, const Node<value_type>& value){
    out << value.getData();
    return out;
}

