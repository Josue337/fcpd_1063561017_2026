/**
 * @file ec_08_multiplicacion_matriz_secuencial.c
 * @brief Sequential square matrix multiplication.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 500

double** allocate_matrix(int size) {
    double **mat = (double **)malloc(size * sizeof(double *));
    if (mat == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        mat[i] = (double *)malloc(size * sizeof(double));
        if (mat[i] == NULL) {
            return NULL;
        }
    }
    return mat;
}

void free_matrix(double **mat, int size) {
    for (int i = 0; i < size; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main(void) {
    double **A = allocate_matrix(N);
    double **B = allocate_matrix(N);
    double **C = allocate_matrix(N);

    if (A == NULL || B == NULL || C == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C[i][j] = 0.0;
        }
    }

    clock_t start = clock();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    clock_t end = clock();
    double seq_time = (double)(end - start) / CLOCKS_PER_SEC;

    /* Every element should be N * 1.0 * 2.0 */
    int correct = 1;
    for (int i = 0; i < N && correct; i++) {
        for (int j = 0; j < N; j++) {
            if (C[i][j] != (double)N * 2.0) {
                correct = 0;
                break;
            }
        }
    }

    printf("--- Performance Summary ---\n");
    printf("Matrix Size:           %d x %d\n", N, N);
    printf("Sequential Time:       %.6f seconds\n", seq_time);
    printf("Result Correct:        %s\n", correct ? "YES" : "NO");

    free_matrix(A, N);
    free_matrix(B, N);
    free_matrix(C, N);

    return 0;
}