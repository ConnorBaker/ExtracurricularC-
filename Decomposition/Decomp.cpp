/*
*  Filename: Decomp.cpp
*
*  Author: Connor Baker, IllegalArgument
*
*  Version: 0.1d
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
using namespace std;

unsigned long iteration = 0;


void decompose(int input) {
    #pragma omp parallel for
    for (int lower_bound = 1; lower_bound < input/3; lower_bound++) {
        int sum = 0;
        int upper_bound;
        for (upper_bound = lower_bound; sum < input; upper_bound++) {
            sum += upper_bound;
            iteration++;
        }
        if (sum == input) {
            printf("Decomposable as \\sum_{%d}^{%d}\n", lower_bound, upper_bound-1);
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

    cout << "There were " << iteration << " iterations." << endl;
    // Exit gracefully
    return 0;
}
