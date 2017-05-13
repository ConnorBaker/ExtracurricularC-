/*
*  filename: Decomp.cpp
*  author: Connor Baker
*  version: 0.1b
*  description: Take a number that is not a power of two and find the upper and
*  lower bounds of a sum on the natural numbers that is equal to that number,
*  compsoded of at least three terms (since any odd number can be decomposed
*  into two terms adjacent to the half of the number, like with 9 into 4 and 5).
*  Example: input of 15 would return 1 and 5 (1+2+3+4+5=15) and 4 and 6
*  (4+5+6=15).
*/

#include <iostream>
#include <string>
using namespace std;

int iteration = 0;

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
    #pragma omp parallel for
    for (int i = 1; i < input/2; i++) { // No sense in going over half the value for the sum
        for (int j = i+1; j < input/2+1; ++j) { // No sense in going over half the value for the sum
            if (sum(i,j) == input) { // Pass the values to our method to calculate possible bounds
                cout << "Lower bound: "<< i << "\t Upper bound: " << j << endl; // Print successful attempts
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

    cout << "There were " << iteration << " iterations." << endl;
    // Exit gracefully
    return 0;
}
