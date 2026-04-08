#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <map>
#include <chrono>
#include <cctype>

// Global Variables //
int charsInAlphabet = 0;
std::unordered_map<char, int> valMap;
std::string str1 = "";
std::string str2 = "";

// These are not needed in an efficient implementation but will make managing information easier.
std::string longestSubsequence = "";
int longestSubsequenceLength = 0;

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

void WriteOutputData(std::string fileTarget, std::string data)
{
    std::ofstream target(fileTarget);

    target << data;

    target.close();
}

std::string DetermineOptimalSubsequence(std::string str1, std::string str2)
{
    // A function which takes in two strings and attempts to discover the greatest subsequence shared between them.
    // Return the substring found, as the specification only asks for any one of the longest substrings. Include the
    // length of this substring when returning in main (store the value globally or calculate manually before exit).

    std::string subsequence;

    //std::cout << str1 << std::endl;
    //std::cout << str2 << std::endl;
    //if (str1.size() > str2.size())
    //{
    //    std::cout << "swap" << std::endl;
    //    std::string temp = str2;
    //    str2 = str1;
    //    str1 = temp;
    //}

    // For each character in one string, check each character in the second string for the longest consecutive match
    // between the two strings. Maintain storage of the longest substring indexes and/or substring with length.
    for (int i = 0; i < str1.size(); i++)
    {
        // Retrieve character (I use two chars to get around const char* since char is easier to work with for me)
        const char* checkingChar = (str1.substr(i, 1)).c_str();
        //char checkingChar = inp;
        //char checkingChar = str1[i];
        int matchLength = 0;

        // Check the other string for occurrences of this character, then check consecutives for longer matches.
        for (int j = 0; j < str2.size(); j++)
        {
            const char* compareToChar = (str2.substr(j, 1)).c_str();

            if (strcmp(checkingChar, compareToChar) == 0)
            {
                //matchLength = 1;
                char toPlace_first = *checkingChar;
                matchLength += valMap.at(toPlace_first);
                int working_i = i + 1;
                int working_j = j + 1;

                //const char* nextChar1 = ((str1.substr(working_i + 1, 1))).c_str();
                //const char* nextChar2 = ((str2.substr(working_j + 1, 1))).c_str();

                //while (strcmp(str1.at(working_i), str2.at(working_j)) == 0)
                //while (str1.at(working_i) == str2.at(working_j))   // Not using strcmp makes having whitespace in subsequence impossible
                //if ( ((str1.substr(working_i, 1)).c_str()) != '\n' && ((str1.substr(working_i, 1)).c_str()) != nullptr
                //&& ((str2.substr(working_j, 1)).c_str()) != '\n' && ((str2.substr(working_j, 1)).c_str()) != nullptr )
                //if (!( ((str1.substr(working_i, 1)).c_str()).isEmpty() || ((str2.substr(working_j, 1)).c_str()).isEmpty() ))
                //if ( ((((str1.substr(working_i, 1)).c_str()) != nullptr && ((str2.substr(working_j, 1)).c_str()) != nullptr )) )
                //if ( !( std::isspace((str1.substr(working_i, 1)).c_str()) && std::isspace((str2.substr(working_j, 1)).c_str()) ) )
                // while (strcmp(((str1.substr(working_i, 1)).c_str()), ((str2.substr(working_j, 1)).c_str())) = 0)   // Do not need to worry about space since whitespace can't be given a value in map
                //while (strcmp(nextChar1, nextChar2) == 0)
                while (strcmp( ((str1.substr(working_i, 1)).c_str()), ((str2.substr(working_j, 1)).c_str()) ) == 0)
                {
                    //matchLength++;
                    char toPlace = *((str1.substr(working_i, 1)).c_str());
                    matchLength += valMap.at(toPlace);
                    working_i++;
                    working_j++;

                    //std::cout << *((str1.substr(working_i, 1)).c_str()) << std::endl;

                    char inefficientChar1 = *((str1.substr(working_i, 1)).c_str());
                    char inefficientChar2 = *((str2.substr(working_j, 1)).c_str());
                    if (inefficientChar1 == '\n' || inefficientChar2 == '\n')
                    {
                        std::cout << "newline" << std::endl;
                        break;
                    }

                    //std::cout << ((str1.substr(working_i, 3))) << "1   2" << ((str2.substr(working_j, 3))) << std::endl;
                    //nextChar1 = ((str1.substr(working_i + 1, 1))).c_str();
                    //nextChar2 = ((str2.substr(working_j + 1, 1))).c_str();
                }

                // Match has ended
                // Length starts at 0, so the first existing subsequence always work; therefore, use equals too.
                if (matchLength >= longestSubsequenceLength)
                {
                    // Setting two longest subsequence variables is unnecessary but thorough to make sure data is
                    // retained if not immediately stored upon return of this function.

                    // Either str1 or str2 will function the same since it should be the same if no mistake made.
                    // Will use both str1 and str2 for the sake of testing here, but in a real-world implementation,
                    // would make more sense to only use one regardless.
                    subsequence = str1.substr(i, working_i);
                    longestSubsequence = str2.substr(j, working_j);
                    longestSubsequenceLength = matchLength;
                }
            }
        }
    }

    // Both strings have been searched for substring. An improvement which could be made if time complexity was a priority
    // would be to stop checking as soon as the length of the greatest subsequence exceeds the number to check left from
    // str1, as it becomes impossible for a new substring to emerge at that point.

    // Return the local longestSubsequence; longestSubsequenceLength can be retrieved globally or manually calculated.
    return subsequence;
}


int main()
{
    clock_t start = clock();    // TIMER CREDIT: https://stackoverflow.com/questions/39181930/how-do-i-get-the-clion-debugger-console-to-tell-me-how-many-seconds-my-program-t#39438574
    std::string finalSubsequence;

    // Primary Operations
    ReadInputData("_input/input.in");
    finalSubsequence = DetermineOptimalSubsequence(str1, str2);

    // Create a string object so it can both be outputted in runtime and written to a file.
    std::cout << '\n';
    std::string result = std::to_string(longestSubsequenceLength) + '\n' + finalSubsequence;
    std::cout << result;

    // Write data to file
    WriteOutputData("_output/output.out", result);

    // Timer referenced from: https://stackoverflow.com/questions/39181930/how-do-i-get-the-clion-debugger-console-to-tell-me-how-many-seconds-my-program-t#39438574
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);

    return 0;
}