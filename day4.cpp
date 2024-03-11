#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 

std::vector<int> extractSubstrings(const std::string& line);


int main(){
  std::deque<int> numberOfRepeat;
  std::string lineFromFile;
  std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day4_input.txt");
  int count = 0;
  int totalScore = 0;
  size_t doubleDotPos;
  size_t linePos;
  int numberOfRepeatThisLine = 0;
  bool stop = false;
  int totalCards = 0;

  while (std::getline (MyReadFile, lineFromFile) && (stop == false)) {
    totalCards = totalCards + 1 + numberOfRepeatThisLine; 
    count = 0;
    std::cout << "Pocet opakovani: " << numberOfRepeatThisLine << std::endl;
    doubleDotPos = lineFromFile.find(':');
    linePos = lineFromFile.find('|');

    std::string firstHalfString = lineFromFile.substr(doubleDotPos + 1, linePos - doubleDotPos - 1);
    std::string SecondHalfString = lineFromFile.substr(linePos + 1);

    std::vector<int> firstHalfNumbers = extractSubstrings(firstHalfString);
    std::vector<int> secondHalfNumbers = extractSubstrings(SecondHalfString);

    std::sort(firstHalfNumbers.begin(), firstHalfNumbers.end());
    std::sort(secondHalfNumbers.begin(), secondHalfNumbers.end());
    std::vector<int> commonElements;
    std::set_intersection(firstHalfNumbers.begin(), firstHalfNumbers.end(), secondHalfNumbers.begin(), secondHalfNumbers.end(), std::back_inserter(commonElements));
    count = commonElements.size();

    for (int i = 0; i < count; i++)
    {
      if (i < numberOfRepeat.size()){
        numberOfRepeat[i] += 1+(numberOfRepeatThisLine);
      }else{
        numberOfRepeat.push_back(1+numberOfRepeatThisLine);
      }
    }
    
    if(count > 0){
      totalScore += (int)pow(2, (count-1)) + (numberOfRepeatThisLine) * (int)pow(2, (count-1));
    }

    if(numberOfRepeat.size()>0){
      numberOfRepeatThisLine = numberOfRepeat[0];
      numberOfRepeat.pop_front();
    }else{
      numberOfRepeatThisLine = 0;
    }
    
    //std::cout << "count" << count << std::endl;
  }
  std::cout << "totalCards" << totalCards << std::endl;
}


std::vector<int> extractSubstrings(const std::string& inputString) {
    std::vector<int> substrings;
    std::istringstream iss(inputString);
    std::string temp;

    while (iss >> temp) {
        substrings.push_back(stoi(temp));
    }

    return substrings;
}
