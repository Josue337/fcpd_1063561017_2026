/**
 * @file ec_07_producto_escalar_secuencial.c
 * @brief Sequential vector dot product.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>
#include <stdlib.h>

#define N 1000000

int main(void) {
    double *a = (double *)malloc(N * sizeof(double));
    double *b = (double *)malloc(N * sizeof(double));

    if (a == NULL || b == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(a);
        free(b);
        return 1;
    }

    for (int i = 0; i < N; i++) {
        a[i] = 2.0;
        b[i] = 3.0;
    }

    double dot_product = 0.0;

    printf("Running vector dot product sequentially.\n");

    for (int i = 0; i < N; i++) {
        dot_product += a[i] * b[i];

        if (i < 4) {
            printf("Processed vector element index %d\n", i);
        }
    }

    printf("Dot Product Result: %.2f (Expected: %.2f)\n", dot_product, (double)N * 6.0);

    free(a);
    free(b);
    return 0;
}