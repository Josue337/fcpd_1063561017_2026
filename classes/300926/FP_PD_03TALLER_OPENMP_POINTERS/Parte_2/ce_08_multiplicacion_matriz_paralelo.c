/**
 * @file ec_08_multiplicacion_matriz_paralelo.c
 * @brief Sequential and parallel square matrix multiplication with thread row mapping.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 500 // Matrix size N x N

// Helper function to allocate 2D dynamic contiguous array
double** allocate_matrix(int size) {
    double **mat = (double **)malloc(size * sizeof(double *));
    for (int i = 0; i < size; i++) {
        mat[i] = (double *)malloc(size * sizeof(double));
    }
    return mat;
}

// Helper function to free matrix memory
void free_matrix(double **mat, int size) {
    for (int i = 0; i < size; i++) {
        free(mat[i]);
    }
    free(mat);
}

int main(void) {
    double **A = allocate_matrix(N);
    double **B = allocate_matrix(N);
    double **C_seq = allocate_matrix(N);
    double **C_par = allocate_matrix(N);

    // Initialize matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = 1.0;
            B[i][j] = 2.0;
            C_seq[i][j] = 0.0;
            C_par[i][j] = 0.0;
        }
    }

    // --- Sequential Matrix Multiplication ---
    double start_seq = omp_get_wtime();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C_seq[i][j] = sum;
        }
    }
    double end_seq = omp_get_wtime();
    double seq_time = end_seq - start_seq;

    // --- Parallel Matrix Multiplication ---
    double start_par = omp_get_wtime();
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) {
        int thread_id = omp_get_thread_num();
        
        // Sample logging: print thread assignment for select rows
        if (i % 100 == 0) {
            printf("Thread %d is computing row %d\n", thread_id, i);
        }

        for (int j = 0; j < N; j++) {
            double sum = 0.0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C_par[i][j] = sum;
        }
    }
    double end_par = omp_get_wtime();
    double par_time = end_par - start_par;

    // Verify correctness
    int correct = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (C_seq[i][j] != C_par[i][j]) {
                correct = 0;
                break;
            }
        }
    }

    printf("\n--- Performance Summary ---\n");
    printf("Matrix Size:           %d x %d\n", N, N);
    printf("Sequential Time:       %.6f seconds\n", seq_time);
    printf("Parallel Time:         %.6f seconds\n", par_time);
    printf("Speedup:               %.2fx\n", seq_time / par_time);
    printf("Results Match:         %s\n", correct ? "YES" : "NO");

    // Clean up memory
    free_matrix(A, N);
    free_matrix(B, N);
    free_matrix(C_seq, N);
    free_matrix(C_par, N);

    return 0;
}