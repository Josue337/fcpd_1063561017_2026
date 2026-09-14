/**
 * @file ce_06_invertir_con_punteros.c
 * @brief reverse an array using pointers
 * @author Josue Bustamante
 * @date 2026-09-12
 */



#include <stdio.h>

void reverseArray(int *array, int size) {

    int temp;

    for (int i = 0; i < size / 2; i++) {

        temp = *(array + i);
        *(array + i) = *(array + size - 1 - i);
        *(array + size - 1 - i) = temp;
    }
}

int main() {

    int array[] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Before: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    reverseArray(array, size);

    printf("\nAfter: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}