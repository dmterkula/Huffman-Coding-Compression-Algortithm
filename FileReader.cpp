// FileReader.h
/*
* creates a class that reads in a file by each char
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "FileReader.h"

using namespace std;


  FileReader::FileReader(string fileName1){
    characters.assign(257,0);
    characters[256] = 1;
    fileName = fileName1;
    //readFile();
  }



  string FileReader::getFileName(){
    return fileName;
  }

  vector<int> FileReader::readFile(){
    ifstream infile;
    infile.open(getFileName().c_str());
    while(infile.peek() && !infile.eof()){
      char ch = infile.get();
      characters[ch] ++;
    }
    return characters;
  }

 void FileReader::printFile(){
   cout << "in printFile" << endl;
   for(int i = 0; i < characters.size(); i++){
     cout << i << ": count: " << characters[i] << endl;
   }
 }

    int FileReader::getMaxChar(){
      return PSEUDOEOF;
    }
