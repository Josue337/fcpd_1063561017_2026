/**
 * @file ce_07_matriz_diagonales.c
 * @brief Create a square matrix with random numbers and compare the diagonals.
 * @author Josue Bustamante
 * @date 2026-09-12
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int n = 3;
    int matrix[3][3];

    int mainDiagonal = 0;
    int secondaryDiagonal = 0;

    srand(time(NULL));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 10 + 1;
        }
    }


    printf("Matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }


    for (int i = 0; i < n; i++) {
        mainDiagonal = mainDiagonal + matrix[i][i];
        secondaryDiagonal = secondaryDiagonal + matrix[i][n - 1 - i];
    }

    printf("Main diagonal sum: %d\n", mainDiagonal);
    printf("Secondary diagonal sum: %d\n", secondaryDiagonal);

    if (mainDiagonal > secondaryDiagonal) {
        printf("The main diagonal is greater\n");
    } else if (secondaryDiagonal > mainDiagonal) {
        printf("The secondary diagonal is greater\n");
    } else {
        printf("Both diagonals are equal\n");
    }

    return 0;
}