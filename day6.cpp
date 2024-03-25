#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 


long long int getNumberOfSolutions(long long int time, long long int distance);

int main(){
  std::string firstLineFromFile;
  std::string secondLineFromFile;
  std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day6_input.txt");
  std::getline (MyReadFile, firstLineFromFile);
  std::getline (MyReadFile, secondLineFromFile);
  // int tmp = getNumberOfSolutions(41, 249);
  // int tmp2 = getNumberOfSolutions(77, 1362);
  // int tmp3 = getNumberOfSolutions(70, 1127);
  // int tmp4 = getNumberOfSolutions(96, 1011);
  // std::cout << "result: " << tmp * tmp2 * tmp3 * tmp4;
  long long int tmp = getNumberOfSolutions(41777096,249136211271011);
  std::cout << "result: " << tmp;
}
  
long long int getNumberOfSolutions(long long int time, long long int distance){
  long long int speed;
  long long int timeRemaining;
  long long int distanceToReach;
  long long int winningSolutions = 0;
  for (long long int i = 0; i < time; i++)
  {
    timeRemaining = time - i;
    distanceToReach = i * (time - i);
    if(distanceToReach > distance){
      winningSolutions++;
    }
    //std::cout << i << std::endl;
  }

  std::cout << winningSolutions << std::endl;
  return winningSolutions;
  

}