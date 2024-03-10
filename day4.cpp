#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 

std::string extractFirstSubstring(const std::string& line);
std::vector<int> extractSubstrings(const std::string& line);

int main(){

  std::string lineFromFile;
  std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day4_input.txt");
  int count = 0;
  int totalScore = 0;
  size_t doubleDotPos;
  size_t linePos;


  while (std::getline (MyReadFile, lineFromFile)) {
    count = 0;

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

    if(count > 0){
      totalScore += (int)pow(2, (count-1));
    }
    //std::cout << "count" << count << std::endl;
  }
  std::cout << "totalScore" << totalScore << std::endl;
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
