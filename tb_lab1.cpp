#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iomanip>  // For std::setw

#define LM 6
#define LN 6
#define LP 6

#define M (1 << LM)
#define N (1 << LN)
#define P (1 << LP)

void matrix_multiply_hw(const uint8_t A[N][M], const uint8_t B[M][P], uint32_t C[N][P]);

// Software matrix multiplication for verification
void matrix_multiply_sw(const uint8_t A[N][M], const uint8_t B[M][P], uint32_t C[N][P]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            C[i][j] = 0;  // Initialize element C[i][j]
            for (int k = 0; k < M; ++k) {
                C[i][j] += (uint32_t)A[i][k] * (uint32_t)B[k][j];
            }
        }
    }
}

int main() {
    // Initialize random seed
    std::srand(std::time(0));

    // Declare matrices A, B, and C for both HW and SW computation
    uint8_t A[N][M];
    uint8_t B[M][P];
    uint32_t C_hw[N][P];
    uint32_t C_sw[N][P];

    // Initialize matrices A and B with random values in the range 0–255
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = rand() % 256;
        }
    }
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            B[i][j] = rand() % 256;
        }
    }

    // Perform matrix multiplication using both hardware and software functions
    matrix_multiply_hw(A, B, C_hw);
    matrix_multiply_sw(A, B, C_sw);

    // Verify the results
    bool success = true;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            if (C_hw[i][j] != C_sw[i][j]) {
                success = false;
                break;
            }
        }
        if (!success) break;
    }

    // Print matrices and results
    std::cout << "Matrix A:" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << std::setw(4) << static_cast<int>(A[i][j]) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix B:" << std::endl;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < P; ++j) {
            std::cout << std::setw(4) << static_cast<int>(B[i][j]) << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix C (Hardware Result):" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            std::cout << std::setw(6) << C_hw[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Matrix C (Software Result):" << std::endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            std::cout << std::setw(6) << C_sw[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Print test result
    if (success) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}
