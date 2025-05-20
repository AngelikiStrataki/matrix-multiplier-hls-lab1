#include <stdint.h>

#define LM 6    // Define lm (for example, lm = 6 -> m = 2^6 = 64)
#define LN 6    // Define ln (for example, ln = 6 -> n = 2^6 = 64)
#define LP 6    // Define lp (for example, lp = 6 -> p = 2^6 = 64)

#define M (1 << LM)  // m = 2^lm
#define N (1 << LN)  // n = 2^ln
#define P (1 << LP)  // p = 2^lp

void matrix_multiply_hw(
    const uint8_t A[N][M],
    const uint8_t B[M][P],
    uint32_t C[N][P]
) {
	#pragma HLS ARRAY_PARTITION variable=A complete dim=2
    #pragma HLS ARRAY_PARTITION variable=B complete dim=1
    #pragma HLS ARRAY_PARTITION variable=C complete dim=2

    // Perform matrix multiplication: C = A * B
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < P; ++j) {
            C[i][j] = 0;  // Initialize element C[i][j]
            for (int k = 0; k < M; ++k) {
				#pragma HLS UNROLL
                C[i][j] += (uint32_t)A[i][k] * (uint32_t)B[k][j];
            }
        }
    }
}
