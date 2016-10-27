// HuffmanMode.h
/*
* creates the template for the huffman node class
*/

#include <iostream>
#include "HuffmanNode.h"

using namespace std;

  HuffmanNode::HuffmanNode(int weight1, int value1){
    weight = weight1;
    value = value1;
    leftChild = NULL;
    rightChild = NULL;
  }
  HuffmanNode::HuffmanNode(HuffmanNode* leftChild1, HuffmanNode* rightChild1){
    leftChild = leftChild1;
    rightChild = rightChild1;
    weight = leftChild->getWeight() + rightChild->getWeight();
    value = -1;
  }

  int HuffmanNode::getValue() const {
    return value;
  }
  int HuffmanNode::getWeight() const {
    return weight;
  }
  HuffmanNode* HuffmanNode::getLeftChild(){
    return leftChild;
  }
  HuffmanNode* HuffmanNode::getRightChild(){
    return rightChild;
  }
