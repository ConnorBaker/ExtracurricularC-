#include <x86intrin.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

void print_mat(vector<vector<__m256>> a) {
    // Print the result
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            for (size_t k = 0; k < 8; k++) {
                cout << a[i][j][k] << ' ';
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

    for (size_t i = 0; <#condition#>; i++) {
        for (size_t j = 0; <#condition#>; j++) {
            = _mm256_setr_ps(a[i][][0], a[i][][0], a[i][][0], a[i][][0], a[i][][0], a[i][][0], a[i][][0], a[i][][0]);
        }
    }
    
    return a_transpose;
}

int main() {
    // Initialize the two matrices to multiply
    vector<vector<__m256>> mat_A(8, vector<__m256>(2, _mm256_setr_ps(0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0)));
    print_mat(mat_A);
    cout << endl;
    print_mat(transpose_mat(mat_A));

    return 0;
}
