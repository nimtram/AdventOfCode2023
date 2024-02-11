#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main()
{
std::string lineFromFile;
std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day1_input.txt");
int sumOfNumbers = 0;

std::string firstDigit;
std::string secondDigit;
std::string fullNumber;
int i;
while (std::getline (MyReadFile, lineFromFile)) {
    firstDigit = "x";
    secondDigit = "x";
    //std::cout << lineFromFile << std::endl;
    int lineLength = lineFromFile.length();
    for (i= 0; i <= lineLength; i++)
    {
        if (isdigit(lineFromFile[i])){
            firstDigit = lineFromFile[i];
            break;
        }
    }

    for (int j = lineLength; j >= 0; j--)
    {
        if (isdigit(lineFromFile[j])){
            secondDigit = lineFromFile[j];
            break;
        }
    }
    
    if (firstDigit !="x" && secondDigit!="x" ){
        fullNumber = firstDigit + secondDigit;
    }else if (firstDigit!="x")
    {
        fullNumber = firstDigit;
    }
    
    
    std::cout << fullNumber << std::endl;
    sumOfNumbers = sumOfNumbers + stoi((fullNumber));
}
std::cout << sumOfNumbers;


}