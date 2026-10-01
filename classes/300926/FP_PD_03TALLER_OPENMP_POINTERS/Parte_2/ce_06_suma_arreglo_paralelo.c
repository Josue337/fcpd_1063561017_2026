/**
 * @file ce_06_suma_arreglo_paralelo.c
 * @brief Sequential vs. parallel array sum using OpenMP reduction clause.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 10000000 // 10 million elements

int main(void) {
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Initialize array
    for (long i = 0; i < N; i++) {
        arr[i] = 1;
    }

    long long seq_sum = 0;
    long long par_sum = 0;

    // --- Sequential Execution ---
    double start_seq = omp_get_wtime();
    for (long i = 0; i < N; i++) {
        seq_sum += arr[i];
    }
    double end_seq = omp_get_wtime();
    double seq_time = end_seq - start_seq;

    // --- Parallel Execution with OpenMP ---
    double start_par = omp_get_wtime();
    #pragma omp parallel for reduction(+:par_sum)
    for (long i = 0; i < N; i++) {
        par_sum += arr[i];
    }
    double end_par = omp_get_wtime();
    double par_time = end_par - start_par;

    // Results comparison
    printf("Sequential Sum: %lld | Time: %.6f seconds\n", seq_sum, seq_time);
    printf("Parallel Sum:   %lld | Time: %.6f seconds\n", par_sum, par_time);
    printf("Speedup: %.2fx\n", seq_time / par_time);

    free(arr);
    return 0;
}