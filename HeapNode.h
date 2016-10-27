// HeapNode.h
/*
* creates template for HeapNode class
*/

#ifndef HeapNode_H
#define HeapNode_H

#include "HuffmanNode.h"

using namespace std;

class HeapNode{

private:
HuffmanNode* huffmanNode;

public:

HeapNode();

HuffmanNode* getHuffmanNode() const;

void buildLeaf(int weight, int value);

bool operator<(const HeapNode &node1) const;

void buildNode(HuffmanNode* leftChild, HuffmanNode* rightChild);

};
#endif
