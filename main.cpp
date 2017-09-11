// main.cpp
/*
* runs the huff encoder
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <queue>
#include "HuffmanNode.h"
#include "HeapNode.h"
#include "FileReader.h"

using namespace std;

static vector<string> encodings;

priority_queue <HeapNode> buildHeap(priority_queue<HeapNode> theHeap, vector<int> characters){
  // use a for loop and create heap nodebased on index and weight
  for(int asciiValue = 0; asciiValue < characters.size(); asciiValue++){
    if(characters[asciiValue] != 0){
      HeapNode newNode;
      newNode.buildLeaf(characters[asciiValue], asciiValue);
      theHeap.push(newNode);
    }

  }
  return theHeap;
}

HeapNode getHuffmanTree(priority_queue <HeapNode> theHeap){
//cout << "Tree Building!" << endl;
  while(theHeap.size() > 1){
    HeapNode newNode;
    HeapNode smallest = theHeap.top();
    theHeap.pop();
    HeapNode nextSmallest = theHeap.top();
    theHeap.pop();
    newNode.buildNode(smallest.getHuffmanNode(), nextSmallest.getHuffmanNode());
    theHeap.push(newNode);
  }
  return theHeap.top();
}

void printEncodings(){
  for(int i = 0; i < encodings.size(); i++){
      if(encodings[i] != ""){
    cout << encodings[i] << endl;
  }
  }
}

void printTheHeap(priority_queue<HeapNode> theHeap){
  while((!theHeap.empty())){
    char letter = theHeap.top().getHuffmanNode()->getValue();
  cout << "Value: " << letter << "," <<theHeap.top().getHuffmanNode()->getValue() << "   Weight: " << theHeap.top().getHuffmanNode()->getWeight() << endl;
  theHeap.pop();
}
}

void testTraverse(HuffmanNode* node){
  if(node == NULL){
    return;
  }

  if(node->getLeftChild() != NULL){ // at internal node
    cout << "at internal left node. Weight = " << node->getWeight() << endl;
    testTraverse(node->getLeftChild());
  }

if(node->getRightChild() != NULL){
  cout << "at internal right node. Weight = " << node->getWeight() << endl;
  testTraverse(node->getRightChild()); // at internal node
 }

 if(node->getValue() != -1){ // we have a legit node
   char letter = node->getValue();
 cout << "at a leaf " << letter << ", " << node->getValue() << endl;
  }
 return;

 }

 void traverse(HuffmanNode* node, string path){ // make vector of appropriate length or use map
   if(node == NULL){
     return;
   }

   if(node->getLeftChild() != NULL){
     traverse(node->getLeftChild(), path + "0");
   }

 if(node->getRightChild() != NULL){
   traverse(node->getRightChild(), path + "1");
  }

  if(node->getValue() != -1){ // we have a legit node
    char letter = node->getValue();
  cout << "at a leaf... char: " << letter << ":   " << "acsii: " << node->getValue() << ": " << "path: " << path <<  endl;
  encodings[node->getValue()] = path;
   }
 }

int main(){
  FileReader* fileReader = new FileReader("test.txt");
  vector<int> characters = fileReader->readFile();
  //fileReader->printFile();
  //cout << "characters.size() = " << characters.size() << endl;
  priority_queue <HeapNode> theHeap;
  theHeap = buildHeap(theHeap, characters);
  int heapSize = theHeap.size();
  //printTheHeap(theHeap);
  HeapNode tree = getHuffmanTree(theHeap);
  //testTraverse(tree.getHuffmanNode());
  cout << endl;
  encodings.assign(257, "");
  // cout << "encondings.size() = " << encodings.size() << endl;
  //cout << "the heap.size() = " << theHeap.size() << endl;
  string path = "";
  // cout << "getting encodings" << endl;
  traverse(tree.getHuffmanNode(), path);
  fileReader->printToFile(encodings, heapSize-1); // don't include PSEUDOEOF
  // cout << "out of trverse method" << endl;
  //printEncodings();
}
