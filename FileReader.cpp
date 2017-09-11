// FileHandler.h
/*
* creates a class that reads
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "FileReader.h"

using namespace std;


  FileHandler::FileHandler(string fileName1){
    characters.assign(257,0);
    characters[256] = 1;
    fileName = fileName1;
    //readFile();
  }



  string FileHandler::getFileName(){
    return fileName;
  }

  vector<int> FileHandler::readFile(){
    ifstream infile;
    infile.open(getFileName().c_str());
    while(infile.peek() && !infile.eof()){
      char ch = infile.get();
      characters[ch] ++;
    }
    return characters;
  }

  void FileHandler::printToFile(vector<string> encodings, int heapSize){
  string convertedText = "";
   ofstream outputFile; // start using obstream
   outputFile.open("HuffEncodingData.txt");
   outputFile << heapSize;
   for(int i = 0; i < characters.size() -1; i++){ // don't use PSEUDOEOF
     if(characters[i] != 0){
       char letter = i;
       convertedText += encodings[i];
       outputFile << letter << characters[i] << " ";
     }
   }
   outputFile << convertedText; // use write bits method
  }

 void FileHandler::printFile(){
   cout << "in printFile" << endl;
   for(int i = 0; i < characters.size(); i++){
     cout << i << ": count: " << characters[i] << endl;
   }
 }

    int FileHandler::getMaxChar(){
      return PSEUDOEOF;
    }
