/*
*  Filename: Decomp.cpp
*
*  Author: Connor Baker
*
*  Version: 0.1c
*
*  Description: This program is meant to take as a command line argument a
*  natural number greater than three and print the lower and upper bounds of
*  the decomposition of the number. The decomposition of a number refers to a
*  way of rewriting a number as the sum of consecutive natural numbers.
*
*
*
*  Example: input of 15 would return 1 and 5 (1+2+3+4+5=15) and 4 and 6
*  (4+5+6=15).
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long iteration = 0;
vector<string> list;

int sum(int lower_bound, int upper_bound) {
    int sum = lower_bound;
    iteration++;
    for (int i = lower_bound+1; i <= upper_bound; i++) {
        sum += i;
        iteration++;
    }
    return sum;
}



void decompose(int input) {
    // For loop to send values to test for decompositions
    for (int i = 1; i < input/3; i++) { // No sense in going over half the value for the sum
        #pragma omp parallel for
        for (int j = i+1; j < input/3+2; ++j) { // No sense in going over half the value for the sum
            if (sum(i,j) == input) { // Pass the values to our method to calculate possible bounds
                list.push_back("Lower bound: "+to_string(i)+"\tUpper bound: "
                                +to_string(j)); // Print successful attempts
            }
        }
    }
}



int main(int argc, char *argv[]) {
    // Check if the user has input anything
    if (argc == 1) {
        cout << "Please pass as an argument the number (that is not a power of two) to decompose" << endl;
        return 0;
    }

    // Grab input from the console, use stoi to convert the string to an integer
    int input = stoi(argv[1]);

    // Pass to method to decompose
    decompose(input);

    // Order the vector
    sort(list.begin(), list.end());

    for (const auto s: list)
        cout << s << endl;

    cout << "There were " << iteration << " iterations." << endl;
    // Exit gracefully
    return 0;
}
