/**
 * @file ec_07_producto_escalar.c
 * @brief Vector dot product parallelized with OpenMP reduction and thread logging.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 1000000

int main(void) {
    double *a = (double *)malloc(N * sizeof(double));
    double *b = (double *)malloc(N * sizeof(double));

    if (a == NULL || b == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize vectors
    for (int i = 0; i < N; i++) {
        a[i] = 2.0;
        b[i] = 3.0;
    }

    double dot_product = 0.0;

    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int total_threads = omp_get_num_threads();

        // Single execution block to print thread count safely
        #pragma omp single
        {
            printf("Running vector dot product with %d threads.\n", total_threads);
        }

        #pragma omp for reduction(+:dot_product)
        for (int i = 0; i < N; i++) {
            dot_product += a[i] * b[i];

            // Print thread participation sample for the first few elements
            if (i < 4) {
                printf("Thread %d processed vector element index %d\n", thread_id, i);
            }
        }
    }

    printf("Dot Product Result: %.2f (Expected: %.2f)\n", dot_product, (double)N * 6.0);

    free(a);
    free(b);
    return 0;
}