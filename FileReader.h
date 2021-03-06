// FileReader.h
/*
* creates the outline for a class that reads in a file by each char
*/

#ifndef FileReader_H
#define FileReader_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class FileHandler{

private:
  const int PSEUDOEOF = 256;
  vector<int> characters;
  string fileName;



public:
  FileReader(string fileName1);

  vector<int> readFile();

  string getFileName();

void printToFile(vector<string> encodings, int heapSize);
  void printFile();
  int getMaxChar();


};
#endif
