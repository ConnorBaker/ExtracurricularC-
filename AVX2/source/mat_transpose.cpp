#include <x86intrin.h>
#include <iostream>
#include <vector>

#include <random>

using std::cout;
using std::endl;
using std::vector;

void print_mat(vector<vector<__m256>> a) {
    // Print the result
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            for (size_t k = 0; k < 8; k++) {
                if (static_cast<int>(a[i][j][k]/10) == 0) {
                    cout << a[i][j][k] << "  ";
                } else {
                    cout << a[i][j][k] << ' ';
                }
            }
            cout << '\t';
        }
        cout << endl;
    }
}

vector<vector<__m256>> transpose_mat(vector<vector<__m256>> a) {
    // Divide row count by eight since we are packing them into __m256
    // Mult column count by eight since we are unpacking them from __m256
    
    vector<vector<__m256>> a_transpose(a[0].size()*8, vector<__m256>(a.size()/8, _mm256_set1_ps(0.0)));
    
    // Known working
#pragma omp parallel for
    for (size_t m = 0; m < a_transpose[0].size(); m++) {
        #pragma omp simd collapse(3)
        for (size_t j = m*8; j < (m+1)*8; j+=8) {
        for (size_t i = 0; i < a[0].size(); i++) {
        for (size_t k = 0; k < 8; k++) {
            a_transpose[k+i*8][m] = _mm256_setr_ps(a[0+j][i][k], a[1+j][i][k], a[2+j][i][k], a[3+j][i][k], a[4+j][i][k], a[5+j][i][k], a[6+j][i][k], a[7+j][i][k]);
        }
    }
    }
    }
    
    return a_transpose;
}

int main() {
    // Initialize the two matrices to multiply
    vector<vector<__m256>> mat_A(16384, vector<__m256>(2048, _mm256_setr_ps(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0)));
    
//    print_mat(mat_A);
    transpose_mat(mat_A);
//    print_mat(transpose_mat(mat_A));
    
    return 0;
}
