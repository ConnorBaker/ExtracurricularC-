#include <x86intrin.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
 *  Takes two vectors as arguments and sums their contents.
 *  Precondition: The matrices are of the same size.
 *  Postcondition: The function returns a matrix of the size of the inputs.
 */
vector<vector<__m256>> add_mat(vector<vector<__m256>> a, vector<vector<__m256>> b) {
    // Initialize the matrix to return, with the same row and column size as input
    vector<vector<__m256>> c(a.size(), vector<__m256>(a[0].size(), _mm256_set1_ps(0.0)));
    
    // Sum the the elements of the matrices
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            c[i][j] = _mm256_add_ps(a[i][j], b[i][j]);
        }
    }
    return c;
}

int main() {
    // Initialize the two matrices to sum
    vector<vector<__m256>> mat_A(8, vector<__m256>(1, _mm256_setr_ps(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0)));
    vector<vector<__m256>> mat_B(8, vector<__m256>(1, _mm256_setr_ps(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0)));
    
    // Pass the sum to a third matrix
    vector<vector<__m256>> mat_C = add_mat(mat_A, mat_B);
    
    // Print the result
    for (size_t i = 0; i < mat_C.size(); i++) {
        for (size_t j = 0; j < mat_C[0].size(); j++) {
            for (size_t k = 0; k < 8; k++) {
                cout << mat_C[i][j][k] << ' ';
            }
            cout << '\t';
        }
        cout << endl;
    }
    
    return 0;
}
