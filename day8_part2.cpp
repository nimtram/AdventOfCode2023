#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


int getIndexOfInput(const std::vector<std::string>& inputMaze, const std::string& input);
std::string getFirstThreeLetters(const std::string& input);
std::string getFirstFromParentheses(const std::string& input);
std::string getSecondFromParentheses(const std::string& input);
std::vector<std::string> getStringsWithThirdLetterA(const std::vector<std::string>& inputStrings);



int main(){

  std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day8_input.txt");
  std::vector<std::string> inputMaze;
   std::string inputInstructions;
  std::string lineFromFile;

  std::getline (MyReadFile, inputInstructions);
  //skip second line
  std::getline (MyReadFile, lineFromFile);

  while (std::getline (MyReadFile, lineFromFile)) {
    inputMaze.push_back(lineFromFile);
  }
  std::vector<int> eachStartCounter;
  int counterOfSteps = 0;
  int numberOfInstructions = inputInstructions.size();
  int actualInstructionIndex = 0;
  int actualPositionIndex = 0;
  std::vector<std::string> startingPositions = getStringsWithThirdLetterA(inputMaze);
  for (size_t i = 0; i < startingPositions.size(); i++)
  {
    counterOfSteps = 0;
    std::string actualPosition = startingPositions[i];
    //int counter =0;
    while (actualPosition[2] != 'Z'){
      actualPositionIndex = getIndexOfInput(inputMaze, actualPosition);
      if(inputInstructions[actualInstructionIndex] == 'R'){
        actualPosition = getSecondFromParentheses(inputMaze[actualPositionIndex]);
      }else{
        actualPosition = getFirstFromParentheses(inputMaze[actualPositionIndex]);
      }

      actualInstructionIndex++;
      actualInstructionIndex%=numberOfInstructions;
      counterOfSteps++;
    }
    eachStartCounter.push_back(counterOfSteps);
    std::cout << "Number of steps: " << counterOfSteps << std::endl;
  }
  
  
}
int getIndexOfInput(const std::vector<std::string>& inputMaze, const std::string& input) {
  int resultIndex = -1;
  
  for (int i = 0; i < inputMaze.size(); i++) {
    std::string str = getFirstThreeLetters(inputMaze[i]);
    if (str.substr(0, 3) == input) {
      resultIndex = i;
      break;
    }
  }
  
  return resultIndex;
}

std::string getFirstThreeLetters(const std::string& input) {
  return input.substr(0, 3);
}


std::string getFirstFromParentheses(const std::string& input) {
  size_t start = input.find('(');
  size_t end = input.find(')');
  if (start != std::string::npos && end != std::string::npos && start < end) {
    return input.substr(start + 1, 3);
  }
  return "";
}

std::string getSecondFromParentheses(const std::string& input) {
  size_t start = input.find('(');
  size_t end = input.find(')');
  if (start != std::string::npos && end != std::string::npos && start < end) {
    return input.substr(end -3,3);
  }
  return "";
}

std::vector<std::string> getStringsWithThirdLetterA(const std::vector<std::string>& inputStrings) {
  std::vector<std::string> resultStrings;
  
  for (const std::string& str : inputStrings) {
    if (str.size() >= 3 && str[2] == 'A') {
      resultStrings.push_back(str.substr(0, 3));
    }
  }
  
  return resultStrings;
}



  