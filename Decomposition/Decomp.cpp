/*
*  Filename: Decomp.cpp
*
*  Author: Connor Baker, IllegalArgument
*
*  Version: 0.2a
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

void decompose(unsigned int input) {
    #pragma omp parallel for
    for (unsigned int lower_bound = 1; lower_bound < input/3; lower_bound++) {
        unsigned int sum = 0;
        unsigned int upper_bound;
        for (upper_bound = lower_bound; sum < input; upper_bound++) {
            sum += upper_bound;
            iteration++;
        }
        if (sum == input) {
            printf("Decomposable as $\\sum_{%u}^{%u} k$\n", lower_bound, upper_bound-1);
        }
    }
}

void decompose(unsigned long input) {
    #pragma omp parallel for
    for (unsigned long lower_bound = 1; lower_bound < input/3; lower_bound++) {
        unsigned long sum = 0;
        unsigned long upper_bound;
        for (upper_bound = lower_bound; sum < input; upper_bound++) {
            sum += upper_bound;
            iteration++;
        }
        if (sum == input) {
            printf("Decomposable as $\\sum_{%lu}^{%lu} k$\n", lower_bound, upper_bound-1);
        }
    }
}

void decompose(unsigned long long input) {
    #pragma omp parallel for
    for (unsigned long long lower_bound = 1; lower_bound < input/3; lower_bound++) {
        unsigned long long sum = 0;
        unsigned long long upper_bound;
        for (upper_bound = lower_bound; sum < input; upper_bound++) {
            sum += upper_bound;
            iteration++;
        }
        if (sum == input) {
            printf("Decomposable as $\\sum_{%llu}^{%llu} k$\n", lower_bound, upper_bound-1);
        }
    }
}



int main(int argc, char *argv[]) {
    // Check if the user has input anything
    if (argc == 1) {
        cout << "Please pass as an argument the number (that is not a power of two) to decompose" << endl;
        return 0;
    }


    // Initialize our possible variables
    unsigned int input_int;
    unsigned long input_long;
    unsigned long long input_long_long;

    // Use try-catch statements to make sure we assign the variable correctly
    // It's best to use this to avoid the performance penalty involved with larger types
    try {
        // Grab input from the console, use stoi to convert the string to an integer
        input_int = stoi(argv[1]);
        cout << "Treating " << input_int << " as a uint" << endl;
        decompose(input_int);
    } catch (out_of_range& e) {
        try {
            input_long = stoul(argv[1]);
            cout << "Treating " << input_long << " as a ulong" << endl;
            decompose(input_long);
        } catch (out_of_range& e) {
            try {
                input_long_long = stoull(argv[1]);
                cout << "Treating " << input_long_long << " as a ulonglong" << endl;
                decompose(input_long_long);
            } catch (out_of_range& e) {
                cout << "Please enter a number smaller than 1.844674407E19" << endl;
                return 0;
            }
        }
    } catch (invalid_argument& e) {
        cout << "Please enter a number";
        return 0;
    }

    cout << "There were " << iteration << " iterations." << endl;
    // Exit gracefully
    return 0;
}
