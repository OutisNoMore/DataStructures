#ifndef NODES_H
#define NODES_H

template <typename E>
struct node{
  node* leftChild;
  node* rightChild;
  E element;

  node(E element){
    this->element = element;
    leftChild = rightChild = nullptr;
  }
};

#endif // NODES_H
