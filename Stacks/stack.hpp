#ifndef STACK_H
#define STACK_H

#include "nodes.hpp"

template <typename E>
class Stack{
    private:
        node* _root;
        node* _current;
        int _size;

    public:
        Stack();
        Stack(E data);
        ~Stack();

        void push(E data);
        E pop();
        E peek();
        int size();
};

template <typename E>
Stack<E>::Stack(){
    _root = _current = nullptr;
    _size = 0;
}

template <typename E>
Stack<E>::Stack(E data){
    _root = _current = new node<E>(data);
    _size = 1;
}

template <typename E>
Stack<E>::~Stack(){
    for(node* curr = _root; curr->next != nullptr;){
        curr = curr->next;
        delete curr->last;
    }
    delete _current;
}

template <typename E>
void Stack<E>::push(E data){
    if(_root == nullptr){
        _root = _current = new node<E>(data);
    }
    else{
        _current->next = new node<E>(data);
        _current->next->last = _current;
        _current = _current->next;
    }
    _size++;
}

template <typename E>
E Stack<E>::pop(){
    if(_root == nullptr){
        throw "ERROR: Stack is empty";
    }
    E output = _current->element;
    _current = _current->last;
    delete _current->next;
    _size--;
    return output;
}

template <typename E>
E Stack<E>::peek(){
    if(_root == nullptr){
        throw "ERROR: Stack is empty";
    }
    
    return _current->element;
}

template <typename E>
int Stack<E>::size(){
    if(_root == nullptr){
        throw "ERROR: Stack is empty";
    }
    
    return _size;
}

#endif // STACK_H