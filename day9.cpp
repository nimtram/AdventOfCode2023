#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

bool checkIfAllNumbersAreZero(std::vector<int> line, int size);

int main(){
  int counterOfSteps = 0;
  std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day9_input.txt");
  std::vector<std::vector<int>> linesOfCode;

  std::string lineFromFile;
  while (std::getline (MyReadFile, lineFromFile)){
    std::vector<int> line;
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;
    while ((pos = lineFromFile.find(delimiter)) != std::string::npos) {
      token = lineFromFile.substr(0, pos);
      lineFromFile.erase(0, pos + delimiter.length());
      line.push_back(std::stoi(token));
    }
    line.push_back(std::stoi(lineFromFile));
    linesOfCode.push_back(line);
  }

int actualSize;
bool notZero;
int totalSum = 0;
 std::vector<int> actualLine;
  for (int i = 0; i < linesOfCode.size(); i++){
    notZero = true;
    actualLine = linesOfCode[i];
    
    // code to part2
    //std::reverse(actualLine.begin(), actualLine.end());
    
    actualSize = actualLine.size();
    while (actualSize > 0){
      for(int j = 0; j < (actualSize -1); j++){
        actualLine[j] = actualLine[j+1] - actualLine[j];
      }
      if (checkIfAllNumbersAreZero(actualLine, actualSize-1)) break;
      actualSize--;       
    }
    totalSum += std::accumulate(actualLine.begin(), actualLine.end(), 0);
    std::cout << "Sum" << totalSum << std::endl;
  }
  MyReadFile.close();
  
}

bool checkIfAllNumbersAreZero(std::vector<int> line, int size){
  for (int i = 0; i < size; i++){
    if (line[i] != 0){
      return false;
    }
  }
  return true;
}

  