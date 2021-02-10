//
//LinkedList hpp file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the implementation for a LinkedList template class
//

//creates an empty LinkedList of size 0
template <typename value_type>
LinkedList<value_type>::LinkedList(){
    head = NULL;
    tail = NULL;
    current = NULL;
    size = 0;
}

//removes LinkedList from the memory
template <typename value_type>
LinkedList<value_type>::~LinkedList(){
    LinkedList lL;
    bool finished = false;
    while(!finished){
        if (getHead()!=getTail()){
            removeNode(getHead());
        } else {
            removeNode(getHead());
            head = NULL;
            tail = NULL;
            current = NULL;
            size = 0;
            finished = true;
        }
    }
}

//Returns the value of the head Node
template <typename value_type>
Node<value_type>* LinkedList<value_type>::getHead(){
    return head;
}

//Returns the value of the tail Node
template <typename value_type>
Node<value_type>* LinkedList<value_type>::getTail(){
    return tail;
}

//Set the value of the head Node to h
template <typename value_type>
void LinkedList<value_type>::setHead(const Node<value_type>* h){
    head = h;
}

//Set the value of the head Node to h
template <typename value_type>
void LinkedList<value_type>::setTail(const Node<value_type>* t){
    tail = t;
}

//Add a new Node at the head with data value
template <typename value_type>
void LinkedList<value_type>::addToHead(value_type value){
    //add new node at head
    Node<value_type>* node = new Node<value_type>(value);
    node->setNext(head);
    if(size == 0){
        tail = node;
        current = node;
    } else {
        current = node;
    }
    head = node;
    size++;
}

//Set the current pointer to head
template <typename value_type>
void LinkedList<value_type>::setCurrentToHead(){
    current = head;
}

//Set the current pointer to next Node
template <typename value_type>
void LinkedList<value_type>::setCurrentToNext(){
    current = current->getNext();
}

//Return the current pointer
template <typename value_type>
Node<value_type>* LinkedList<value_type>::getCurrent() const{
    return current;
}

//Return the size of the LinkedList
template <typename value_type>
int LinkedList<value_type>::getSize() const{
    return size;
}

//remove a node and rearrange the pointers
template <typename value_type>
void LinkedList<value_type>::removeNode(Node<value_type>* n){


    if(n == head){
        //set head to next
        head = n->getNext();
    }
    size--;
    delete n;
}
