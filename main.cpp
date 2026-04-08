#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <map>
#include <chrono>

// Global Variables //
int charsInAlphabet = 0;
std::unordered_map<char, int> valMap;
std::string str1 = "";
std::string str2 = "";

// // // // // // //

void ReadInputData(std::string fileSource)
{
    // This code is REUSED from my previous assignments in this class and only serves the purpose of reading input file.
    // Citation for methodology followed: https://www.geeksforgeeks.org/cpp/how-to-read-from-a-file-in-cpp/

    // Retrieve the data from the file
    std::ifstream source(fileSource);

    if (!source.is_open())
    {
        std::cout << "Unsuccessful in opening file." << std::endl;
    }
    else
    {
        std::string currLine;
        bool isFirst = true;
        int charsPlaced = 0;
        bool hasDoneStr1 = false; // Need to account for if str1 is completely empty
        bool hasDoneStr2 = false;

        // Parse the data line-by-line, using the formatting specified in the description
        while (getline(source, currLine))
        {
            std::cout << currLine << std::endl;

            if (isFirst)
            {
                // The number represents dimensions of later lines
                charsInAlphabet = std::stoi(currLine);
                isFirst = false;
                std::cout << charsInAlphabet << std::endl;
            }
            else
            {
                // The line represents either data for hospitals or students; hospitals come first, followed by students
                // Citation: https://stackoverflow.com/questions/216068/parsing-integers-from-a-line
                std::stringstream ss(currLine);

                //for (int i = 0; i < charsInAlphabet; i++)
                if (charsPlaced < charsInAlphabet)
                {
                    std::string result = "";
                    int valLength = result.size() - 2 - 1;
                    const char* c;
                    int charVal = 0;


                    ss >> result;
                    c = (result.substr(0, 1)).c_str();
                    charVal = std::stoi(currLine.substr(2, valLength));

                    std::cout << "char " << c << " with val " << charVal << std::endl;
                    char test = *c;
                    valMap[test] = charVal;

                    charsPlaced++;
                }
                else
                {
                    // After chars in alphabet, there are two strings
                    if (!(hasDoneStr1))
                    {
                        ss >> str1;
                        hasDoneStr1 = true;
                    }
                    else if (!(hasDoneStr2))
                    {
                        ss >> str2;
                        hasDoneStr2 = true;
                    }
                    else
                    {
                        // Stop taking in input and end
                        //source.close();
                    }
                }
            }
        }

        // All of the data from the input file---cache capcity, number of requests, and the integer sequence---should
        // now all be in the program and ready for computation.
        source.close();
    }
}

std::string DetermineOptimalSubsequence(String str1, String str2)
{
    // A function which takes in two strings and attempts to discover the greatest subsequence shared between them.
    // Return the substring found, as the specification only asks for any one of the longest substrings. Include the
    // length of this substring when returning in main (store the value globally or calculate manually before exit).

    // For each character in one string, check each character in the second string for the longest consecutive match
    // between the two strings. Maintain storage of the longest substring indexes and/or substring with length.
    for (int i = 0; i < str1.size(); i++)
    {
        // Retrieve character (I use two chars to get around const char* since char is easier to work with for me)
        const char* inp = (str1.substr(i, 1)).c_str();
        char checkingChar = inp;

        // Check the other string for occurrences of this character, then check consecutives for longer matches.
        for (int j = 0; j < str2.size(); j++)
        {

        }
    }

    return "";
}


int main()
{
    std::string finalSubsequence;

    try
    {
        ReadInputData("input.in");
        finalSubsequence = DetermineOptimalSubsequence(this.str1, this.str2);
    }
    catch (...)
    {
        std::cout << "Fatal error" << std::endl;
    }

    std::cout << "result test" << std::endl;
    return 0;
}