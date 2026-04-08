# highest-val_longest-common

Student Name: Gabriel Fernandez
UFID : 24394306

Instructions:
To use this program, please reference the "template.in" file to learn how inputs should be formatted. A sample "input.in" file is provided in the input directory. The expected result of this input is found in the output directory (as "output.out").

Files used in the program are found in the cmake-build-debug folder due to the way CLion (the IDE used for development) works by default. The two relevant folders are "_input" and "_output", and, as their names imply, they are used for input and output respectively.

In order to enter new data, please replace the "input.in" file with the desired contents according to the template. Upon running, the result will be printed to console as well as appear in a new "output.out" file.


Question 1:
1: 0.04200
2: 0.02500
3: 0.04800
4: 0.66900
5: 0.03600
6: 0.02700
7: 0.04200
8: 0.05100
9: 0.06900
10: 0.07400
Please refer to the chart image included in the repository files.

Question 2: The recurrence equation is 

Question 3: In order to compute the HVLCS of strings 1 and 2, one would follow a similar procedure to the code above. With the given data, for each character in the first string, the second string should be checked for characters in common. When a common character is found, each consecutive character from that point in both strings should be compared against each other, incrementing a size until they are either no longer consistent or one of the strings end. In order to maintain weighted values for different characters, it would be necessary to maintain a data structure (such as a map) specifying these values for each character used: it would be required either to have an assigned value for every character present amongst the union of the strings or to use a default case, such as each non-specified character being worth 0 or 1.

This code would follow the exact same procedure as the main.cpp code found above. In the scenario retrieving the data does not add additional complexity, scanning string 1 would use O(n) and scanning string 2 would use O(n), where string 2's scan is nested within each character from string 1's scan, meaning O(n^2) would be the Big-Oh complexity (other operations surrounding are O(1)). From the measured runtime tests in Question 1, when the outlier of test 4 is removed, the average runtime evaluates to 0.046.
