#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 

char getFirstNumber(std::string lineOfFile);
char getSecondNumber(std::string lineOfFile);

int main()
{
std::string lineFromFile;
std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day1_input.txt");
int sumOfNumbers = 0;

char firstDigit;
char secondDigit;
std::string fullNumber;

while (std::getline (MyReadFile, lineFromFile)) {

    firstDigit = getFirstNumber(lineFromFile);
    secondDigit = getSecondNumber(lineFromFile);

 std::string fullNumber(1, firstDigit);
    fullNumber += secondDigit;
    sumOfNumbers = sumOfNumbers + stoi((fullNumber));
}
std::cout << sumOfNumbers;
}

char getFirstNumber(std::string lineOfFile){
    for (char &letter : lineOfFile) {
        if (isdigit(letter)){
           return letter;
        }
    }
    return 'x';
}

char getSecondNumber(std::string lineOfFile){
    char letter;
    for (int iter = lineOfFile.length()-1; iter>=0; iter--){
    letter = lineOfFile[iter];
        if (isdigit(letter)){
           return letter;
        }
    }
    return 'x';
}