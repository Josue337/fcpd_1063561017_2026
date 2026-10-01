/**
 * @file ec_06_suma_arreglo_secuencial.c
 * @brief Sequential array sum.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000000

int main(void) {
    int *arr = (int *)malloc(N * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (long i = 0; i < N; i++) {
        arr[i] = 1;
    }

    long long seq_sum = 0;

    clock_t start_seq = clock();
    for (long i = 0; i < N; i++) {
        seq_sum += arr[i];
    }
    clock_t end_seq = clock();
    double seq_time = (double)(end_seq - start_seq) / CLOCKS_PER_SEC;

    printf("Sequential Sum: %lld | Time: %.6f seconds\n", seq_sum, seq_time);

    free(arr);
    return 0;
}