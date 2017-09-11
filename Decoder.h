// decoder.h

#ifndef Decoder_H
#define Decoder_H

#include <priority_queue>
#include <HeapNode>

using namespace std

class Decoder{

private:
  int numCharacters;
  string fileName;
  string characterPath;
  priority_queue<HeapNode> secondHeap


public:
  Decoder(string fileName1);
  string getFileName();
  void readFile();
  void buildHeap();
  void buildTree();
  HeapNode getHuffmanTree(){
    
  }


};
#endif
