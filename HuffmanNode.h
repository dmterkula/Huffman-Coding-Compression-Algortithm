// HuffmanMode.h
/*
* creates the template for the huffman node class
*/

#ifndef HuffmanNode_H
#define HuffmanNode_H

using namespace std;

class HuffmanNode{

private:
  int weight;
  int value; // represent char held in node if there is one
  HuffmanNode* leftChild;
  HuffmanNode* rightChild;

public:

  HuffmanNode(int weight, int value);
  HuffmanNode(HuffmanNode* leftChild1, HuffmanNode* rigtChild1);

  int getValue() const;
  int getWeight() const;
  HuffmanNode* getLeftChild();
  HuffmanNode* getRightChild();
};
#endif
