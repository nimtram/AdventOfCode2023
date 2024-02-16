#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <bits/stdc++.h> 
#include <iostream>
#include <sstream>
#include <string>


int main()
{
    std::string lineFromFile;
    std::ifstream MyReadFile("C:/Documents/Prg/AdventOfCode2023/day2_input.txt");
    int power;
    int sumPower = 0;
    int actualGame = 0;
    int sumOfPossibleGames=0;
    int totalRed = 12;
    int totalGreen = 13;
    int totalBlue = 14;
    int minNumberOfRed = 0;
    int minNumberOfGreen = 0;
    int minNumberOfBlue = 0;
    int number = 0;
    char lastChar;
    bool end = false;
    std::string oneWord;
    while (std::getline (MyReadFile, lineFromFile)) {
        actualGame ++;
        std::stringstream ss(lineFromFile);
        while (ss >> oneWord) { 
            if (isdigit((char)oneWord[0])){
                number = stoi(oneWord);
            }else if ((char)oneWord[0] == 'r')
            {
                if (number > totalRed) end = true;
                if (number > minNumberOfRed) minNumberOfRed = number;
            }else if ((char)oneWord[0] == 'g')
            {
                if (number > totalGreen) end = true;
                if (number > minNumberOfGreen) minNumberOfGreen = number;
            }else if ((char)oneWord[0] == 'b')
            {
                if (number > totalBlue) end = true;
                if (number > minNumberOfBlue) minNumberOfBlue = number;
            }

        }

        if (end == false){
            sumOfPossibleGames += actualGame;
            //std::cout << "game " << actualGame << "je ok" << std::endl;
        }
        end = false;
        
        power = minNumberOfBlue * minNumberOfGreen * minNumberOfRed;
        std::cout << "game " << actualGame << "je " << minNumberOfBlue <<" "  << minNumberOfGreen<<" "  << minNumberOfRed <<std::endl;
        std::cout << "game " << actualGame << "je " << power << std::endl;
        sumPower += power;

        minNumberOfBlue = 0;
        minNumberOfGreen = 0;
        minNumberOfRed = 0;

        

    }

    std::cout << sumOfPossibleGames << std::endl;
    std::cout << sumPower;
}