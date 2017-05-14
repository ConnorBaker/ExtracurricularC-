/*
*  Filename: Decomp.cpp
*
*  Author: Connor Baker, IllegalArgument
*
*  Version: 0.2c
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
#include <climits>
#include <string>
using namespace std;



void decompose(unsigned int input) {
    unsigned int upper_bound;
    unsigned int sum;
    #pragma omp parallel for
    for (unsigned int lower_bound = 1; lower_bound < input/3; lower_bound++) {
        sum = 0;
        for (upper_bound = lower_bound; sum < input; upper_bound++) {
            sum += upper_bound;
        }
        if (sum == input) {
            printf("Decomposable as the sum on [%u,%u]\n", lower_bound, upper_bound-1);
        }
    }
}



void decompose(unsigned long input) {
    unsigned long upper_bound;
    unsigned long sum;
    #pragma omp parallel for
    for (unsigned long lower_bound = 1; lower_bound < input/3; lower_bound++) {
        sum = 0;
        for (upper_bound = lower_bound; sum < input; upper_bound++) {
            sum += upper_bound;
        }
        if (sum == input) {
            printf("Decomposable as the sum on [%lu,%lu]\n", lower_bound, upper_bound-1);
        }
    }
}



void decompose(unsigned long long input) {
    unsigned long long upper_bound;
    unsigned long long sum;
    #pragma omp parallel for
    for (unsigned long long lower_bound = 1; lower_bound < input/3; lower_bound++) {
        sum = 0;
        for (upper_bound = lower_bound; sum < input; upper_bound++) {
            sum += upper_bound;
        }
        if (sum == input) {
            printf("Decomposable as the sum on [%llu,%llu]\n", lower_bound, upper_bound-1);
        }
    }
}



int main(int argc, char *argv[]) {
    // Check if the user has input anything
    if (argc == 1) {
        cout << "Please pass as an argument the number (that is not a power of two) to decompose" << endl;
        return 0;
    }

    // Try to store our input as an unsigned long long
    try {
        unsigned long long input_long_long = stoull(argv[1]);
        if (UINT_MAX > input_long_long) {
            unsigned int input_int = stol(argv[1]);
            decompose(input_int);
        } else if (ULONG_MAX > input_long_long) {
            unsigned long input_long = stoul(argv[1]);
            decompose(input_long);
        } else {
            decompose(input_long_long);
        }
    } catch (out_of_range& e) {
        cout << "Please enter a number smaller than 1.844674407E19" << endl;
        return 0;
    } catch (invalid_argument& e) {
        cout << "Please enter a number";
        return 0;
    }

    // Exit gracefully
    return 0;
}
