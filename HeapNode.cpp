// HeapNode.h
/*
* creates HeapNode class
*/

#include "HeapNode.h"

using namespace std;


HeapNode::HeapNode(){

}

HuffmanNode* HeapNode::getHuffmanNode() const {
  return huffmanNode;
}

void HeapNode::buildLeaf(int weight, int value){
huffmanNode = new HuffmanNode(weight, value);
}

bool HeapNode::operator<(const HeapNode &node1) const {
  bool returnMe = false;
  if(node1.getHuffmanNode()->getWeight() < huffmanNode->getWeight()){
    returnMe = true;
  }
  else{
    returnMe = false;
  }
  return returnMe;
}

void HeapNode::buildNode(HuffmanNode* leftChild, HuffmanNode* rightChild){
  huffmanNode = new HuffmanNode(leftChild, rightChild);
}
