//
//LStack hpp file
// Created by Tim Kemmis
//Student no: c3329386
//Course: SENG1120
//Description this is the implementation for a LStack template class
//


//A LStack constructor which creates an empty LinkedList
template <typename value_type>
LStack<value_type>::LStack() {
    data = new LinkedList<value_type>();
}

//A LStack constructor which creates an empty LinkdeList of size length
template <typename value_type>
LStack<value_type>::LStack(const int length) {
    data = new LinkedList<value_type>();
}

//LStack destructor
template <typename value_type>
LStack<value_type>::~LStack(){
	delete data;
}

//Returns a boolean value indicating if the LinkedList is empty
template <typename value_type>
bool LStack<value_type>::empty() const{
    if (data->getSize() == 0){
        return true;
    } else  {
        return false;
    }
}

//Returns the size of the LinkdeList
template <typename value_type>
int LStack<value_type>::height() const{
    return data->getSize();
}

//Returns the data of the head of the LinkedList
template <typename value_type>
value_type LStack<value_type>::top(){
    return data->getHead()->getData();
}

//Adds a new node with data element at the head
template <typename value_type>
void LStack<value_type>::push(const value_type element){
    data->addToHead(element);
}

//Removes the top Head Node of LinkdeList
template <typename value_type>
void LStack<value_type>::pop(){
    data->removeNode(data->getHead());
}

