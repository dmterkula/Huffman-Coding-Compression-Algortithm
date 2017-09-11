// Decoder.cpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Decoder.h"
#include "HeapNode.h"
#include "HuffmanNode.h"

using namespace std;

Decoder::Decoder(string fileName1){
  fileName = fileName1;
}

void Decoder::readFile(){
  ifstream infile;
  infile.open(getFileName().c_str());
  numCharacters = infile.get();
  char value;
  int weight;
  for(int i = 0; i < numCharacters; i++){
     value = infile.get();
     inflie >> weight;
     infile.get(); // the space afterwards
     HeapNode* newNode = buildLeaf(value, weight);
     secondHeap.push(newNode);
     buildHuffmanTree();
  }
  infile >> characterPath;

}



string Decoder::getFileName(){
  return fileName;
}



HeapNode Decoder::getHuffmanTree(){
//cout << "Tree Building!" << endl;
  while(secondHeap.size() > 1){
    HeapNode newNode;
    HeapNode smallest = secondHeap.top();
    secondHeap.pop();
    HeapNode nextSmallest = secondHeap.top();
    secondHeap.pop();
    newNode.buildNode(smallest.getHuffmanNode(), nextSmallest.getHuffmanNode());
    secondHeap.push(newNode);
  }
  return secondHeap.top();
}
