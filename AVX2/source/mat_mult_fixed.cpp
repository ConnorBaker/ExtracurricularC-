#include <x86intrin.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/*
 *  Takes two vectors as arguments and multiples them.
 *  Precondition: The matrices are of the same size.
 *  Postcondition: The function returns a matrix of the size of the inputs.
 */
vector<vector<__m256>> mult_mat(vector<vector<__m256>> a, vector<vector<__m256>> b) {
    // Initialize the matrix to return, with the same row and column size as input
    vector<vector<__m256>> c(a.size(), vector<__m256>(a[0].size(), _mm256_set1_ps(0.0)));
    vector<vector<__m256>> c_temp(a.size(), vector<__m256>(a[0].size(), _mm256_set1_ps(0.0)));
    
    // Create our transpose of the second matrix
    vector<vector<__m256>> b_new(b.size(), vector<__m256>(b[0].size(), _mm256_set1_ps(0.0)));
    
    // Take the transpose of the second matrix
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            for (size_t k = 0; k < 8; k++) {
                b_new[i][j][k] = b[k][j][i];
            }
        }
    }
    
    // Compute the product of the two matrices
    for (size_t i = 0; i < c.size(); i++) {
        for (size_t j = 0; j < c[0].size(); j++) {
            for (size_t k = 0; k < 8; k++) {
                c_temp[i][j] = _mm256_dp_ps(a[i][j], b_new[i][j], 0xFF);
                c[i][j][k] = c_temp[i][j][3] + c_temp[i][j][4];
            }
        }
    }
    
    c_temp = c;
    
    // Take the transpose of the product
    for (size_t i = 0; i < c.size(); i++) {
        for (size_t j = 0; j < c[0].size(); j++) {
            for (size_t k = 0; k < 8; k++) {
                c[i][j][k] = c_temp[k][j][i];
            }
        }
    }
    
    return c;
}

int main() {
    // Initialize the two matrices to multiply
    vector<vector<__m256>> mat_A(8, vector<__m256>(1, _mm256_setr_ps(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0)));
    vector<vector<__m256>> mat_B(8, vector<__m256>(1, _mm256_setr_ps(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0)));
    
    // Pass the product to a third matrix
    vector<vector<__m256>> mat_C = mult_mat(mat_A, mat_B);
    
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
