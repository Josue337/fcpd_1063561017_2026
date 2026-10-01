/**
 * @file ec_02_suma_arreglo.c
 * @brief Summing array elements using pointer dereferencing and arithmetic.
 * @author Josue Bustamante
 * @date 2026-09-30
 */

#include <stdio.h>

#define SIZE 10

int main(void) {
    int numbers[SIZE] = {5, 12, 8, 20, 3, 15, 7, 10, 2, 18};
    int *ptr = numbers;
    int sum = 0;

    for (int i = 0; i < SIZE; i++) {
        sum += *(ptr + i); // Dereference pointer offset to add value
    }

    printf("Array elements: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\nTotal sum using pointers: %d\n", sum);

    return 0;
}