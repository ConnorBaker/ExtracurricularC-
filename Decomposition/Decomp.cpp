/*
*  Filename: Decomp.cpp
*
*  Author: Connor Baker, IllegalArgument
*
*  Version: 0.2d
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
#include <cmath>
#include <string>
using namespace std;



void decompose(unsigned int input) {
  unsigned int length_max = (unsigned int) sqrt(2 * input);
  #pragma omp parallel for
	for (unsigned int length = 1; length < length_max; input -= length, length++) {
		if (input % length == 0) {
			printf("Decomposable as the sum on [%u, %u]\n", input / length, input / length + length - 1);
		}
	}
}



void decompose(unsigned long input) {
  unsigned long length_max = (unsigned long) sqrt(2 * input);
  #pragma omp parallel for
  for (unsigned long length = 1; length < length_max; input -= length, length++) {
    if (input % length == 0) {
      printf("Decomposable as the sum on [%lu, %lu]\n", input / length, input / length + length - 1);
    }
  }
}



void decompose(unsigned long long input) {
  unsigned long long length_max = (unsigned long long) sqrt(2 * input);
  #pragma omp parallel for
  for (unsigned long long length = 1; length < length_max; input -= length, length++) {
    if (input % length == 0) {
      printf("Decomposable as the sum on [%llu, %llu]\n", input / length, input / length + length - 1);
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
