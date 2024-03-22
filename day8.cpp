#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


int getIndexOfInput(const std::vector<std::string>& inputMaze, const std::string& input);
std::string getFirstThreeLetters(const std::string& input);
std::string getFirstFromParentheses(const std::string& input);
std::string getSecondFromParentheses(const std::string& input);



int main(){
  int counterOfSteps = 0;
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

  int numberOfInstructions = inputInstructions.size();
  int actualInstructionIndex = 0;
  int actualPositionIndex = 0;
  std::string actualPosition = "AAA";
  while (actualPosition != "ZZZ"){
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
  std::cout << "Number of steps: " << counterOfSteps << std::endl;
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





  