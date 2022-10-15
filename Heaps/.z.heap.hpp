#ifndef HEAP_H
#define HEAP_H

#include <string>
#include "nodes.hpp"

template <typename E>
using comparator = bool (*)(E, E);

template <typename E>
class Heap{
    private:
        int _size;
        node* _root;
        comparator _comparator;

        void deleteHelper(node<E>* current);
    public:
        Heap(comparator<E> c);
        Heap(E data, comparator<E> c);
        ~Heap();

        void heapify();
        void add(E data);
        E peek();
        E pop();
        int size(){ return _size; };
        std::string print();
};

template <typename E>
Heap<E>::Heap(comparator<E> c){
    _size = 0;
    _root = nullptr;
    _comparator = c;
}

template <typename E>
Heap<E>::Heap(E data, comparator<E> c){
    _size = 1;
    _root = new node<E>(data);
    _comparator = c;
}

template <typename E>
Heap<E>::~Heap(){
    deleteHelper(_root);
}

template <typename E>
void Heap<E>::deleteHelper(node<E>* current){
    if(node == nullptr){
        return;
    }
    if(node->leftChild != nullptr){
        deleteHelper(node->leftChild);
    }
    if(node->rightChild != nullptr){
        deleteHelper(node->rightChild);
    }
    delete node;
}

template <typename E>
void Heap<E>::add(E data){
    if(_size == 0){
        _root = new node<E>(data);
    }
    else if(_size == 1){
        _root->leftChild = new node<E>(data);
    }
    else if(_size == 2){
        _root->rightChild = new node<E>(data);
    }
    else{
        int level = (int)(log10(n+1)/log10(2));
        int steps[level];
        int n = _size + 1;
        for(int i = level - 1; i >= 0; i--){
            steps[i] = n;
            n /= 2;
        }
        node* current = _root;
        for(int i = 0; i < level - 1; i++){
            if(steps[i]%2 == 0){
                current = current._leftChild;
            }
            else{
                current = current._rightChild;
            }
        }
        if(steps[level - 1]%2 == 0){
            current->_leftChild = new node<E>(data);
        }
        else{
            current->_rightChild = new node<E>(data);
        }
    }
    ();
    _size++;
}

template <typename E>
void Heap<E>::heapify(){

}

#endif // HEAP_H